#include "EspBox.hpp"
#include "Brewblox.hpp"
#include "cbox/Base64.h"
#include "cbox/Connections.h"
#include "esp_system.h"
#include "network/CboxConnection.hpp"
#include "proto/command.pb.h"
#include <optional>
#include <pb_decode.h>
#include <pb_encode.h>

class Request {
public:
    const uint32_t msgId;
    const command_Opcode opcode;
    const cbox::Payload payload;

    Request(uint32_t msgId_, command_Opcode opcode_, cbox::Payload&& payload_)
        : msgId(msgId_)
        , opcode(opcode_)
        , payload(std::move(payload_))
    {
    }

    Request(Request&) = delete;
    Request& operator=(const Request&) = delete;

    ~Request() = default;
};

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

std::optional<Request> parseRequest(cbox::DataIn& in, cbox::DataOut& out)
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

    auto payload = cbox::Payload(message.payload.blockId,
                                 message.payload.blockType,
                                 message.payload.subtype,
                                 std::move(payloadBytes));

    return std::make_optional<Request>(message.msgId,
                                       message.opcode,
                                       std::move(payload));
}

cbox::CboxError respond(cbox::DataOut& out, const cbox::Payload& payload)
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

void finalize(cbox::DataOut& out, const Request& request, cbox::CboxError status)
{
    command_Response message = command_Response_init_zero;
    message.msgId = request.msgId;
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

void handleCommand(cbox::DataIn& in, cbox::DataOut& out)
{
    auto parsed = parseRequest(in, out);

    if (parsed == std::nullopt) {
        return;
    }

    auto& request = parsed.value();
    auto status = cbox::CboxError::UNKNOWN_ERROR;

    auto callback = [&out](const cbox::Payload& payload) -> cbox::CboxError {
        return respond(out, payload);
    };

    switch (request.opcode) {
    case command_Opcode_NONE:
    case command_Opcode_VERSION:
        status = cbox::CboxError::OK;
        cbox::connectionStarted(out);
        break;
    case command_Opcode_BLOCK_READ:
        status = cbox::readBlock(request.payload, callback);
        break;
    case command_Opcode_BLOCK_READ_ALL:
        status = cbox::readAllBlocks(callback);
        break;
    case command_Opcode_BLOCK_WRITE:
        status = cbox::writeBlock(request.payload, callback);
        break;
    case command_Opcode_BLOCK_CREATE:
        status = cbox::createBlock(request.payload, callback);
        break;
    case command_Opcode_BLOCK_DELETE:
        status = cbox::deleteBlock(request.payload);
        break;
    case command_Opcode_BLOCK_DISCOVER:
        status = cbox::discoverBlocks(callback);
        break;
    case command_Opcode_STORAGE_READ:
        status = cbox::readStoredBlock(request.payload, callback);
        break;
    case command_Opcode_STORAGE_READ_ALL:
        status = cbox::readAllStoredBlocks(callback);
        break;
    case command_Opcode_REBOOT:
        finalize(out, request, cbox::CboxError::OK);
        esp_restart();
        return; // already finalized
    case command_Opcode_CLEAR_BLOCKS:
        status = cbox::clearBlocks();
        break;
    case command_Opcode_CLEAR_WIFI:
        status = cbox::CboxError::OK; // TODO(Bob)
        break;
    case command_Opcode_FACTORY_RESET:
        status = cbox::clearBlocks(); // TODO(Bob)
        finalize(out, request, status);
        esp_restart();
        return; // already finalized
    case command_Opcode_FIRMWARE_UPDATE:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    default:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    }

    finalize(out, request, status);
}
