#include "AppBox.h"
#include "AppTicks.h"
#include "cbox/Base64.h"
#include "cbox/Box.h"
#include "cbox/Connections.h"
#include "cbox/DataStream.h"
#include "delay_hal.h"
#include "deviceid_hal.h"
#include "platforms.h"
#include "proto/controlbox.pb.h"
#include "rgbled.h"
#include "spark/Board.h"
#include "spark/Brewblox.h"
#include "spark/ConnectionsTcp.h"
#include "spark_wiring_stream.h"
#include "spark_wiring_usbserial.h"
#include <pb_decode.h>
#include <pb_encode.h>

namespace app {

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
    controlbox_Payload submsg = controlbox_Payload_init_zero;

    submsg.blockId = payload->blockId;
    submsg.objtype = brewblox_BlockType(uint16_t(payload->blockType));
    submsg.subtype = payload->subtype;
    submsg.data.funcs.encode = &encodePayloadContent;
    submsg.data.arg = *arg;

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    if (!pb_encode_submessage(stream, controlbox_Payload_fields, &submsg)) {
        return false;
    }

    return true;
}

cbox::CboxError encodeResponse(const cbox::Payload& payload, std::vector<uint8_t>& protoBytes)
{
    controlbox_Response message = controlbox_Response_init_zero;
    size_t actualSize(0);

    // Don't set message ID yet. The response is invalid until finalized
    message.payload.funcs.encode = &encodePayload;
    message.payload.arg = const_cast<cbox::Payload*>(&payload); // will be cast to a const ptr in handlers

    if (!pb_get_encoded_size(&actualSize, controlbox_Response_fields, &message)) {
        return cbox::CboxError::OUTPUT_STREAM_ENCODING_ERROR;
    }

    protoBytes.resize(actualSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

    if (!pb_encode(&stream, controlbox_Response_fields, &message)) {
        return cbox::CboxError::OUTPUT_STREAM_ENCODING_ERROR;
    }

    return cbox::CboxError::OK;
}

class AppCommand : public cbox::Command {
private:
    cbox::DataOut& out;
    std::unique_ptr<cbox::Payload> requestPtr;

public:
    const uint32_t msgId;
    const controlbox_Opcode opcode;

    AppCommand(uint32_t _msgId,
               controlbox_Opcode _opcode,
               cbox::DataOut& _out,
               cbox::Payload&& _request)
        : out(_out)
        , requestPtr(std::make_unique<cbox::Payload>(std::move(_request)))
        , msgId(_msgId)
        , opcode(_opcode)
    {
    }

    AppCommand(uint32_t _msgId,
               controlbox_Opcode _opcode,
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
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        out.write(',');
        return cbox::CboxError::OK;
    }

    void finalize(cbox::CboxError status)
    {
        controlbox_Response message = controlbox_Response_init_zero;
        message.msgId = msgId;
        message.error = controlbox_ErrorCode(status);

        size_t actualSize;
        pb_get_encoded_size(&actualSize, controlbox_Response_fields, &message);

        auto protoBytes = std::vector<uint8_t>(actualSize);
        auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

        if (!pb_encode(&stream, controlbox_Response_fields, &message)) {
            out.write('\n');
        }

        auto b64Bytes = std::vector<uint8_t>();
        base64_encode(protoBytes, b64Bytes);

        out.writeBuffer(b64Bytes.data(), b64Bytes.size());
        out.write('\n');
    }
};

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

    controlbox_Request message = controlbox_Request_init_zero;
    std::vector<uint8_t> payloadBytes;

    message.payload.data.funcs.decode = &decodePayloadContent;
    message.payload.data.arg = &payloadBytes;

    auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
    if (!pb_decode(&stream, controlbox_Request_fields, &message)) {
        return std::nullopt;
    }

    // no payload
    if (message.payload.blockId == 0 && message.payload.objtype == 0) {
        return std::make_optional<AppCommand>(message.msgId,
                                              message.opcode,
                                              out);
    }

    auto payload = cbox::Payload(message.payload.blockId,
                                 message.payload.objtype,
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
    case controlbox_Opcode_OPCODE_NONE:
        status = cbox::CboxError::OK;
        cbox::connectionStarted(out);
        break;
    case controlbox_Opcode_OPCODE_READ_OBJECT:
        status = cbox::readObject(cmd);
        break;
    case controlbox_Opcode_OPCODE_WRITE_OBJECT:
        status = cbox::writeObject(cmd);
        break;
    case controlbox_Opcode_OPCODE_CREATE_OBJECT:
        status = cbox::createObject(cmd);
        break;
    case controlbox_Opcode_OPCODE_DELETE_OBJECT:
        status = cbox::deleteObject(cmd);
        break;
    case controlbox_Opcode_OPCODE_LIST_OBJECTS:
        status = cbox::listActiveObjects(cmd);
        break;
    case controlbox_Opcode_OPCODE_READ_STORED_OBJECT:
        status = cbox::readStoredObject(cmd);
        break;
    case controlbox_Opcode_OPCODE_LIST_STORED_OBJECTS:
        status = cbox::listStoredObjects(cmd);
        break;
    case controlbox_Opcode_OPCODE_CLEAR_OBJECTS:
        status = cbox::clearObjects(cmd);
        break;
    case controlbox_Opcode_OPCODE_REBOOT:
        cmd.finalize(cbox::CboxError::OK);
        reset(true, UserResetReason::CBOX_RESET);
        return; // already finalized
    case controlbox_Opcode_OPCODE_FACTORY_RESET:
        cmd.finalize(cbox::CboxError::OK);
        cbox::objects.clear();
        reset(true, UserResetReason::CBOX_FACTORY_RESET);
        return; // already finalized
    case controlbox_Opcode_OPCODE_DISCOVER_OBJECTS:
        status = cbox::discoverNewObjects(cmd);
        break;
    case controlbox_Opcode_OPCODE_FIRMWARE_UPDATE:
        cmd.finalize(cbox::CboxError::OK);
        startFirmwareUpdate(in);
        return; // already finalized
    default:
        status = cbox::CboxError::INVALID_COMMAND;
        break;
    }

    cmd.finalize(status);
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
