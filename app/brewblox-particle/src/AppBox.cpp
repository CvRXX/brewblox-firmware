#include "AppBox.h"
#include "AppTicks.h"
#include "ConnectionsTcp.h"
#include "cbox/Box.h"
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

namespace app {

class Command : public cbox::Command {
private:
    uint32_t _msgId;
    controlbox_Opcode _opcode;
    std::unique_ptr<cbox::Payload> _request;
    cbox::DataOut& _out;

public:
    Command(uint32_t msgId,
            controlbox_Opcode opcode,
            cbox::Payload&& request,
            cbox::DataOut& out)
        : _msgId(msgId)
        , _opcode(opcode)
        , _request(std::make_unique<cbox::Payload>(std::move(request)))
        , _out(out)
    {
    }

    Command(uint32_t msgId,
            controlbox_Opcode opcode,
            cbox::DataOut& out)
        : _msgId(msgId)
        , _opcode(opcode)
        , _out(out)
    {
    }

    virtual ~Command() = default;

    virtual cbox::Payload* request() override final
    {
        return _request.get();
    }

    virtual cbox::CboxError respond(const cbox::Payload& payload) override final
    {
        return cbox::CboxError::OK;
    }

    void finalize(cbox::CboxError status)
    {
    }
};

cbox::CboxError reboot(Command& cmd)
{
    return cbox::CboxError::OK;
}

cbox::CboxError factoryReset(Command& cmd)
{
    return cbox::CboxError::OK;
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

void changeLedColor()
{
    LED_SetRGBColor(RGB_COLOR_MAGENTA);
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

void handleCommand(cbox::DataIn& in, cbox::DataOut& out)
{
    // TODO(Bob)
    // grab until newline
    // create proto request
    // handle app-level opcodes
    // delegate cbox-level opcodes
    // finalize response
    // have a snack
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

// namespace cbox {
// // handler for custom commands outside of controlbox
// bool applicationCommand(uint8_t cmdId, cbox::DataIn& in, cbox::EncodedDataOut& out)
// {
//     switch (cmdId) {
//     case 100: // firmware update
//     {
//         CboxError status = CboxError::OK;
//         in.spool();
//         if (out.crc()) {
//             status = CboxError::CRC_ERROR_IN_COMMAND;
//         }
//         out.writeResponseSeparator();
//         out.write(asUint8(status));
//         out.endMessage();
//         ticks.delayMillis(10);
//         if (status == CboxError::OK) {
//             changeLedColor();
//             brewbloxBox().disconnect();
//             ticks.delayMillis(10);
// #if PLATFORM_ID != PLATFORM_GCC
//             updateFirmwareFromStream(in.streamType());
//             // reset in case the firmware update failed
//             System.reset(RESET_USER_REASON::FIRMWARE_UPDATE_FAILED, RESET_NO_WAIT);
// #endif
//         }
//         return true;
//     }
//     }
//     return false;
// }
// } // end namespace cbox
