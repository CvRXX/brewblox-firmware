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
#include "reset.h"
#include "rgbled.h"
#include "spark/Board.h"
#include "spark/Brewblox.h"
#include "spark_wiring_stream.h"
#include "spark_wiring_usbserial.h"
#include <pb.h>
#include <pb_decode.h>
#include <pb_encode.h>

namespace app {

/* This binds the pb_ostream_t into the DataOut stream, which is passed as state in pb_ostream */
bool dataOutStreamCallback(pb_ostream_t* stream, const pb_byte_t* buf, size_t count)
{
    auto out = static_cast<cbox::DataOut*>(stream->state);
    return out->writeBuffer(buf, count);
}

bool encodePayloadContent(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto content = reinterpret_cast<std::vector<uint8_t>*>(*arg);
    auto encoded = base64_encode(*content);
    return pb_write(stream, (const uint8_t*)encoded.c_str(), encoded.size());
}

bool decodePayloadContent(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    auto content = reinterpret_cast<std::vector<uint8_t>*>(*arg);
    auto buf = std::vector<uint8_t>(stream->bytes_left);
    if (!pb_read(stream, buf.data(), stream->bytes_left)) {
        return false;
    }
    auto decoded = base64_decode(buf);
    buf.clear();
    content->reserve(decoded.size());
    content->insert(content->end(), decoded.begin(), decoded.end());
    return true;
}

bool encodePayloadField(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = reinterpret_cast<cbox::Payload*>(*arg);
    controlbox_Payload submsg = controlbox_Payload_init_zero;

    submsg.blockId = payload->blockId;
    submsg.objtype = brewblox_BlockType(uint16_t(payload->blockType));
    submsg.subtype = payload->subtype;
    submsg.data.funcs.encode = &encodePayloadContent;
    submsg.data.arg = &payload->content;

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

    virtual cbox::CboxError respond(const cbox::Payload& payload) override final
    {
        // Don't set message ID yet. The response is invalid until finalized
        controlbox_Response message = controlbox_Response_init_zero;
        message.payload.funcs.encode = &encodePayloadField;
        message.payload.arg = (void*)&payload;

        pb_ostream_t stream = {dataOutStreamCallback, &_out, PB_SIZE_MAX, 0};
        bool success = pb_encode(&stream, controlbox_Response_fields, &message);

        if (success) {
            _out.write(',');
            return cbox::CboxError::OK;
        } else {
            return cbox::CboxError::OUTPUT_STREAM_WRITE_ERROR;
        }
    }

    void finalize(cbox::CboxError status)
    {
        controlbox_Response message = controlbox_Response_init_zero;
        message.msgId = _msgId;
        message.error = controlbox_ErrorCode(status);

        pb_ostream_t stream = {dataOutStreamCallback, &_out, PB_SIZE_MAX, 0};
        pb_encode(&stream, controlbox_Response_fields, &message);
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

void handleCommand(cbox::DataIn& in, cbox::DataOut& out)
{
    uint32_t msgId = 0;
    controlbox_Opcode opcode = controlbox_Opcode_OPCODE_NONE;
    uint32_t blockId = 0;
    brewblox_BlockType blockType = brewblox_BlockType_Invalid;
    uint32_t subtype = 0;
    std::vector<uint8_t> content;

    {
        std::string serialized;
        serialized.reserve(200);

        while (int16_t c = in.read() >= 0) {
            if (c == '\n') {
                break;
            }

            // TODO(Bob): what is a sane max request size?
            // TODO(Bob): is serialized.size() performance acceptable?
            if (serialized.size() > 1000) {
                in.spool();
                return;
            }

            serialized.push_back((uint8_t)c);
        }

        auto raw = base64_decode(serialized);
        serialized.clear();
        serialized.shrink_to_fit();

        controlbox_Request message = controlbox_Request_init_zero;
        message.payload.data.funcs.decode = &decodePayloadContent;
        message.payload.data.arg = &content;

        auto stream = pb_istream_from_buffer(raw.data(), raw.size());
        bool success = pb_decode(&stream, controlbox_Request_fields, &message);
        if (!success) {
            // We don't even have message ID, so can't return an error
            return;
        }

        msgId = message.msgId;
        opcode = message.opcode;
        blockId = message.payload.blockId;
        blockType = message.payload.objtype;
        subtype = message.payload.subtype;
        // content is set by the callback
    }

    auto cmd = AppCommand(
        msgId,
        opcode,
        std::move(cbox::Payload(blockId, blockType, subtype, std::move(content))),
        out);

    auto status = cbox::CboxError::UNKNOWN_ERROR;

    switch (opcode) {
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
