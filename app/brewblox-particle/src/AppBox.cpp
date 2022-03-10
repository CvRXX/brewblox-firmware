#include "AppBox.h"
#include "AppTicks.h"
#include "ConnectionsTcp.h"
#include "cbox/Base64.h"
#include "cbox/Box.h"
#include "cbox/Connections.h"
#include "cbox/DataStream.h"
#include "delay_hal.h"
#include "deviceid_hal.h"
#include "platforms.h"
#include "proto/controlbox.pb.h"
#include "reset.h"
#include "rgbled.h"
#include "spark/Board.h"
#include "spark/Brewblox.h"
#include "spark_wiring_stream.h"
#include "spark_wiring_usbserial.h"
#include <pb_decode.h>
#include <pb_encode.h>

namespace app {

class SerializedPayload {
public:
    uint32_t blockId;
    brewblox_BlockType blockType;
    uint16_t subtype;
    std::vector<uint8_t> encodedContent;

    SerializedPayload(const cbox::Payload& src)
        : blockId(src.blockId)
        , blockType((brewblox_BlockType)uint16_t(src.blockType))
        , subtype(src.subtype)
    {
        base64_encode(src.content, encodedContent);
    }

    virtual ~SerializedPayload() = default;
};

bool decodePayloadContent(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    auto content = reinterpret_cast<std::vector<uint8_t>*>(*arg);
    auto encoded = std::vector<uint8_t>(stream->bytes_left);
    if (!pb_read(stream, encoded.data(), stream->bytes_left)) {
        return false;
    }
    base64_decode(encoded, *content);
    return true;
}

bool encodeSerializedPayloadContent(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto serialized = reinterpret_cast<SerializedPayload*>(*arg);
    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }
    if (!pb_encode_string(stream, serialized->encodedContent.data(), serialized->encodedContent.size())) {
        return false;
    }
    return true;
}

bool encodeSerializedPayload(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto serialized = reinterpret_cast<SerializedPayload*>(*arg);
    controlbox_Payload submsg = controlbox_Payload_init_zero;

    submsg.blockId = serialized->blockId;
    submsg.objtype = serialized->blockType;
    submsg.subtype = serialized->subtype;
    submsg.data.funcs.encode = &encodeSerializedPayloadContent;
    submsg.data.arg = serialized;

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    if (!pb_encode_submessage(stream, controlbox_Payload_fields, &submsg)) {
        return false;
    }

    return true;
}

class AppCommand : public cbox::Command {
private:
    uint32_t _msgId;
    controlbox_Opcode _opcode;
    std::unique_ptr<cbox::Payload> _request;
    cbox::DataOut& _out;

public:
    AppCommand(uint32_t msgId,
               controlbox_Opcode opcode,
               cbox::Payload&& request,
               cbox::DataOut& out)
        : _msgId(msgId)
        , _opcode(opcode)
        , _request(std::make_unique<cbox::Payload>(std::move(request)))
        , _out(out)
    {
    }

    AppCommand(uint32_t msgId,
               controlbox_Opcode opcode,
               cbox::DataOut& out)
        : _msgId(msgId)
        , _opcode(opcode)
        , _out(out)
    {
    }

    virtual ~AppCommand() = default;

    virtual cbox::Payload* request() override final
    {
        return _request.get();
    }

    cbox::CboxError encodeResponse(const cbox::Payload& payload, std::vector<uint8_t>& protoEncoded)
    {
        size_t actualSize;
        auto serialized = SerializedPayload(payload);
        controlbox_Response message = controlbox_Response_init_zero;

        // Don't set message ID yet. The response is invalid until finalized
        message.payload.funcs.encode = &encodeSerializedPayload;
        message.payload.arg = &serialized;

        if (!pb_get_encoded_size(&actualSize, controlbox_Response_fields, &message)) {
            return cbox::CboxError::OUTPUT_STREAM_ENCODING_ERROR;
        }

        protoEncoded.resize(actualSize);
        auto stream = pb_ostream_from_buffer(protoEncoded.data(), protoEncoded.size());

        if (!pb_encode(&stream, controlbox_Response_fields, &message)) {
            return cbox::CboxError::OUTPUT_STREAM_ENCODING_ERROR;
        }

        return cbox::CboxError::OK;
    }

    virtual cbox::CboxError respond(const cbox::Payload& payload) override final
    {
        auto protoEncoded = std::vector<uint8_t>();
        auto b64Encoded = std::vector<uint8_t>();

        auto status = encodeResponse(payload, protoEncoded);
        if (status != cbox::CboxError::OK) {
            return status;
        }

        base64_encode(protoEncoded, b64Encoded);

        if (!_out.writeBuffer(b64Encoded.data(), b64Encoded.size())) {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }

        _out.write(',');
        return cbox::CboxError::OK;
    }

    void finalize(cbox::CboxError status)
    {
        auto protoEncoded = std::vector<uint8_t>();
        auto b64Encoded = std::vector<uint8_t>();

        controlbox_Response message = controlbox_Response_init_zero;
        message.msgId = _msgId;
        message.error = controlbox_ErrorCode(status);

        size_t actualSize;
        pb_get_encoded_size(&actualSize, controlbox_Response_fields, &message);
        protoEncoded.resize(actualSize);

        auto stream = pb_ostream_from_buffer(protoEncoded.data(), protoEncoded.size());
        if (!pb_encode(&stream, controlbox_Response_fields, &message)) {
            _out.write('\n');
        }

        base64_encode(protoEncoded, b64Encoded);

        _out.writeBuffer(b64Encoded.data(), b64Encoded.size());
        _out.write('\n');
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
                System.reset(success ? RESET_USER_REASON::FIRMWARE_UPDATE_SUCCESS : RESET_USER_REASON::FIRMWARE_UPDATE_FAILED, RESET_NO_WAIT);
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
    System.reset(RESET_USER_REASON::FIRMWARE_UPDATE_FAILED, RESET_NO_WAIT);
#endif
}

bool parseMessage(cbox::DataIn& in, cbox::DataOut& out, controlbox_Request* message)
{
    std::vector<uint8_t> b64Encoded;
    std::vector<uint8_t> protoEncoded;
    b64Encoded.reserve(200);

    while (true) {
        auto c = in.read();

        if (c < 0 || c == '\n') {
            break;
        }

        b64Encoded.push_back((uint8_t)c);
    }

    while (true) {
        auto c = in.peek();
        if (c < 0 || (c >= '+' && c <= 'z')) {
            break;
        }
        in.read();
    }

    if (b64Encoded.size() == 0) {
        return false;
    }

    base64_decode(b64Encoded, protoEncoded);
    auto stream = pb_istream_from_buffer(protoEncoded.data(), protoEncoded.size());
    return pb_decode(&stream, controlbox_Request_fields, message);
}

void handleCommand(cbox::DataIn& in, cbox::DataOut& out)
{
    controlbox_Request message = controlbox_Request_init_zero;
    std::vector<uint8_t> content;

    message.payload.data.funcs.decode = &decodePayloadContent;
    message.payload.data.arg = &content;

    if (!parseMessage(in, out, &message)) {
        return;
    }

    auto payload = cbox::Payload(message.payload.blockId,
                                 message.payload.objtype,
                                 message.payload.subtype,
                                 std::move(content));

    auto cmd = AppCommand(
        message.msgId,
        message.opcode,
        std::move(payload),
        out);

    auto status = cbox::CboxError::UNKNOWN_ERROR;

    switch (message.opcode) {
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
        ::handleReset(true, 2);
        return; // unreachable
    case controlbox_Opcode_OPCODE_FACTORY_RESET:
        cmd.finalize(cbox::CboxError::OK);
        cbox::getObjects().clear();
        ::handleReset(true, 3);
        return; // unreachable
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

} // end namespace app
