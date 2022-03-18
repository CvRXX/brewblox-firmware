#include "ParticleBox.hpp"
#include "AppTicks.hpp"
#include "cbox/Base64.hpp"
#include "cbox/Box.hpp"
#include "cbox/Connections.hpp"
#include "cbox/DataStream.hpp"
#include "delay_hal.h"
#include "deviceid_hal.h"
#include "platforms.h"
#include "proto/command.pb.h"
#include "rgbled.h"
#include "spark/Board.hpp"
#include "spark/Brewblox.hpp"
#include "spark/ConnectionsTcp.hpp"
#include "spark_wiring_stream.h"
#include "spark_wiring_usbserial.h"
#include <pb_decode.h>
#include <pb_encode.h>

namespace app {

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
    submsg.blockType = brewblox_BlockType(payload->blockType);
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

cbox::CboxExpected<std::vector<uint8_t>> encodeResponse(const cbox::Payload& payload)
{
    command_Response message = command_Response_init_zero;
    size_t actualSize(0);

    // Don't set message ID yet. The response is invalid until finalized
    message.payload.funcs.encode = &encodePayload;
    message.payload.arg = const_cast<cbox::Payload*>(&payload); // will be cast to a const ptr in handlers

    if (!pb_get_encoded_size(&actualSize, command_Response_fields, &message)) {
        return tl::make_unexpected(cbox::CboxError::NETWORK_ENCODING_ERROR);
    }

    auto protoBytes = std::vector<uint8_t>(actualSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

    if (!pb_encode(&stream, command_Response_fields, &message)) {
        return tl::make_unexpected(cbox::CboxError::NETWORK_ENCODING_ERROR);
    }

    return protoBytes;
}

#if PLATFORM_ID != PLATFORM_GCC
void updateFirmwareStreamHandler(Stream* stream)
{
    enum class DCMD : uint8_t {
        None,
        Ack,
        FlashFirmware,
    };

    auto command = DCMD::Ack;
    uint8_t invalidCommands = 0;

    while (true) {
        HAL_Delay_Milliseconds(1);
        int recv = stream->read();
        switch (recv) {
        case 'F':
            command = DCMD::FlashFirmware;
            break;
        case '\n':
            if (command == DCMD::Ack) {
                stream->write("<!FIRMWARE_UPDATER,");
                stream->write(versionCsv().c_str());
                stream->write(">\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
            } else if (command == DCMD::FlashFirmware) {
                stream->write("<!READY_FOR_FIRMWARE>\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
#if PLATFORM_ID == PLATFORM_GCC
                // just exit for sim
                HAL_Core_System_Reset_Ex(RESET_REASON_UPDATE, 0, nullptr);
#else
                bool success = system_firmwareUpdate(stream);
                reset(true, success ? UserResetReason::FIRMWARE_UPDATE_SUCCESS : UserResetReason::FIRMWARE_UPDATE_FAILED);
#endif
                break;
            } else {
                stream->write("<Invalid command received>\n");
                stream->flush();
                HAL_Delay_Milliseconds(10);
                if (++invalidCommands > 2) {
                    return;
                }
            }
            command = DCMD::Ack;
            break;
        case -1:
            continue; // empty
        default:
            command = DCMD::None;
            break;
        }
    }
}

void updateFirmwareFromStream(cbox::StreamType streamType)
{
    getConnectionPool().stopAll();
    if (streamType == cbox::StreamType::Usb) {
        updateFirmwareStreamHandler(&_fetch_usbserial());
    } else {
        TCPServer server(8332); // re-open a TCP server
        while (true) {
            HAL_Delay_Milliseconds(10); // allow thread switch so system thread can set up client
            {
                TCPClient client = server.available();
                if (client) {
                    updateFirmwareStreamHandler(&client);
                }
            }
        }
    }
}
#endif

void startFirmwareUpdate(cbox::DataIn& in)
{
    LED_SetRGBColor(RGB_COLOR_MAGENTA);
    getConnectionPool().disconnect();
    ticks.delayMillis(10);
#if PLATFORM_ID != PLATFORM_GCC
    updateFirmwareFromStream(in.streamType());
    // reset in case the firmware update failed
    reset(true, UserResetReason::FIRMWARE_UPDATE_FAILED);
#endif
}

std::optional<Request> parseRequest(cbox::DataIn& in)
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
    auto result = encodeResponse(payload);
    if (!result) {
        return result.error();
    }

    auto b64Bytes = std::vector<uint8_t>();
    base64_encode(result.value(), b64Bytes);

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
    auto parsed = parseRequest(in);

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
        finalize(out, request, cbox::CboxError::OK); // TODO(Bob) delay to ensure flush?
        reset(true, UserResetReason::CBOX_RESET);
        return; // already finalized
    case command_Opcode_CLEAR_BLOCKS:
        status = cbox::clearBlocks();
        break;
    case command_Opcode_CLEAR_WIFI:
        status = cbox::CboxError::OK; // TODO(Bob)
        break;
    case command_Opcode_FACTORY_RESET:
        finalize(out, request, cbox::CboxError::OK);
        cbox::objects.clear();
        reset(true, UserResetReason::CBOX_FACTORY_RESET);
        return; // already finalized
    case command_Opcode_FIRMWARE_UPDATE:
        finalize(out, request, cbox::CboxError::OK);
        startFirmwareUpdate(in);
        return; // already finalized
    default:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    }

    finalize(out, request, status);
}

void communicate()
{
    getConnectionPool().process([](cbox::DataIn& in, cbox::DataOut& out) {
        while (in.peek() >= 0) {
            handleCommand(in, out);
        }
    });
}

void update()
{
    cbox::update(ticks.millis());
#if PLATFORM_ID == PLATFORM_GCC
    ticks.delayMillis(10); // prevent 100% cpu usage
#endif
}

void reset(bool exitFlag, UserResetReason reason)
{
    if (exitFlag) {
#if PLATFORM_ID == PLATFORM_GCC
        exit(0);
#else
        System.reset(reason, RESET_NO_WAIT);
#endif
    }
}

} // end namespace app
