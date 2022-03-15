#include "AppBox.hpp"
#include "Brewblox.hpp"
#include "cbox/Base64.h"
#include "cbox/Connections.h"
#include "esp_system.h"
#include "network/CboxConnection.hpp"
#include "proto/command.pb.h"
#include <optional>
#include <pb_decode.h>
#include <pb_encode.h>

bool decodePayloadContent(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    auto payloadBytes = static_cast<std::vector<uint8_t>*>(*arg);
    auto b64Bytes = std::vector<uint8_t>(stream->bytes_left);
    if (!pb_read(stream, b64Bytes.data(), stream->bytes_left)) {
        return false;
    }
    base64_decode(b64Bytes, *payloadBytes);
    return true;
}

bool encodePayloadContent(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = static_cast<const cbox::Payload*>(*arg);
    std::vector<uint8_t> b64Content;
    base64_encode(payload->content, b64Content);
    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }
    if (!pb_encode_string(stream, b64Content.data(), b64Content.size())) {
        return false;
    }
    return true;
}

bool encodePayload(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = static_cast<const cbox::Payload*>(*arg);
    command_Payload submsg = command_Payload_init_zero;

    submsg.blockId = payload->blockId;
    submsg.blockType = brewblox_BlockType(uint16_t(payload->blockType));
    submsg.subtype = payload->subtype;
    submsg.content.funcs.encode = &encodePayloadContent;
    submsg.content.arg = *arg;

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    if (!pb_encode_submessage(stream, command_Payload_fields, &submsg)) {
        return false;
    }

    return true;
}

cbox::CboxError encodeResponse(const cbox::Payload& payload, std::vector<uint8_t>& protoBytes)
{
    command_Response message = command_Response_init_zero;
    size_t actualSize(0);

    // Don't set message ID yet. The response is invalid until finalized
    message.payload.funcs.encode = &encodePayload;
    message.payload.arg = const_cast<cbox::Payload*>(&payload); // will be cast to a const ptr in handlers

    if (!pb_get_encoded_size(&actualSize, command_Response_fields, &message)) {
        return cbox::CboxError::NETWORK_ENCODING_ERROR;
    }

    protoBytes.resize(actualSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

    if (!pb_encode(&stream, command_Response_fields, &message)) {
        return cbox::CboxError::NETWORK_ENCODING_ERROR;
    }

    return cbox::CboxError::OK;
}

class AppCommand : public cbox::Command {
private:
    cbox::DataOut& out;
    std::unique_ptr<cbox::Payload> requestPtr;

public:
    const uint32_t msgId;
    const command_Opcode opcode;

    AppCommand(uint32_t _msgId,
               command_Opcode _opcode,
               cbox::DataOut& _out,
               cbox::Payload&& _request)
        : out(_out)
        , requestPtr(std::make_unique<cbox::Payload>(std::move(_request)))
        , msgId(_msgId)
        , opcode(_opcode)
    {
    }

    AppCommand(uint32_t _msgId,
               command_Opcode _opcode,
               cbox::DataOut& _out)
        : out(_out)
        , msgId(_msgId)
        , opcode(_opcode)
    {
    }

    virtual ~AppCommand() = default;

    virtual cbox::Payload* request() override final
    {
        return requestPtr.get();
    }

    virtual cbox::CboxError respond(const cbox::Payload& payload) override final
    {
        auto protoBytes = std::vector<uint8_t>();
        auto b64Bytes = std::vector<uint8_t>();

        auto status = encodeResponse(payload, protoBytes);
        if (status != cbox::CboxError::OK) {
            return status;
        }

        base64_encode(protoBytes, b64Bytes);

        if (!out.writeBuffer(b64Bytes.data(), b64Bytes.size())) {
            return cbox::CboxError::NETWORK_WRITE_ERROR;
        }

        out.write(',');
        return cbox::CboxError::OK;
    }

    void finalize(cbox::CboxError status)
    {
        command_Response message = command_Response_init_zero;
        message.msgId = msgId;
        message.error = command_ErrorCode(status);

        size_t actualSize;
        pb_get_encoded_size(&actualSize, command_Response_fields, &message);

        auto protoBytes = std::vector<uint8_t>(actualSize);
        auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

        if (!pb_encode(&stream, command_Response_fields, &message)) {
            out.write('\n');
            return;
        }

        auto b64Bytes = std::vector<uint8_t>();
        base64_encode(protoBytes, b64Bytes);

        out.writeBuffer(b64Bytes.data(), b64Bytes.size());
        out.write('\n');
    }
};

std::optional<AppCommand> parseMessage(cbox::DataIn& in, cbox::DataOut& out)
{
    std::vector<uint8_t> protoBytes;

    {
        std::vector<uint8_t> b64Bytes;
        b64Bytes.reserve(200);

        while (true) {
            auto c = in.read();
            if (c < 0 || c == '\n') {
                break;
            }
            b64Bytes.push_back((uint8_t)c);
        }

        // Spool in stream until either the end or a new message is reached
        while (true) {
            auto c = in.peek();
            if (c < 0 || is_base64(c)) {
                break;
            }
            in.read();
        }

        if (b64Bytes.size() == 0) {
            return std::nullopt;
        }

        base64_decode(b64Bytes, protoBytes);
    }

    command_Request message = command_Request_init_zero;
    std::vector<uint8_t> payloadBytes;

    message.payload.content.funcs.decode = &decodePayloadContent;
    message.payload.content.arg = &payloadBytes;

    auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
    if (!pb_decode(&stream, command_Request_fields, &message)) {
        return std::nullopt;
    }

    // no payload
    if (message.payload.blockId == 0 && message.payload.blockType == 0) {
        return std::make_optional<AppCommand>(message.msgId,
                                              message.opcode,
                                              out);
    }

    auto payload = cbox::Payload(message.payload.blockId,
                                 message.payload.blockType,
                                 message.payload.subtype,
                                 std::move(payloadBytes));

    return std::make_optional<AppCommand>(message.msgId,
                                          message.opcode,
                                          out,
                                          std::move(payload));
}

void handleCommand(cbox::DataIn& in, cbox::DataOut& out)
{
    auto parsed = parseMessage(in, out);

    if (parsed == std::nullopt) {
        return;
    }

    auto& cmd = parsed.value();
    auto status = cbox::CboxError::UNKNOWN_ERROR;

    switch (cmd.opcode) {
    case command_Opcode_NONE:
    case command_Opcode_VERSION:
        status = cbox::CboxError::OK;
        cbox::connectionStarted(out);
        break;
    case command_Opcode_BLOCK_READ:
        status = cbox::readObject(cmd);
        break;
    case command_Opcode_BLOCK_READ_ALL:
        status = cbox::listActiveObjects(cmd);
        break;
    case command_Opcode_BLOCK_WRITE:
        status = cbox::writeObject(cmd);
        break;
    case command_Opcode_BLOCK_CREATE:
        status = cbox::createObject(cmd);
        break;
    case command_Opcode_BLOCK_DELETE:
        status = cbox::deleteObject(cmd);
        break;
    case command_Opcode_BLOCK_DISCOVER:
        status = cbox::discoverNewObjects(cmd);
        break;
    case command_Opcode_STORAGE_READ:
        status = cbox::readStoredObject(cmd);
        break;
    case command_Opcode_STORAGE_READ_ALL:
        status = cbox::listStoredObjects(cmd);
        break;
    case command_Opcode_REBOOT:
        cmd.finalize(cbox::CboxError::OK);
        esp_restart();
        return; // already finalized
    case command_Opcode_CLEAR_BLOCKS:
        status = cbox::clearObjects(cmd);
        break;
    case command_Opcode_CLEAR_WIFI:
        status = cbox::CboxError::OK; // TODO(Bob)
        break;
    case command_Opcode_FACTORY_RESET:
        cmd.finalize(cbox::CboxError::OK);
        cbox::objects.clear();
        esp_restart();
        return; // already finalized
    case command_Opcode_FIRMWARE_UPDATE:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    default:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    }

    cmd.finalize(status);
}
