#include "ParticleBox.hpp"
#include "AppTicks.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "cbox/Connection.hpp"
#include "cbox/Serialization.hpp"
#include "delay_hal.h"
#include "deviceid_hal.h"
#include "platforms.h"
#include "proto/command.pb.h"
#include "rgbled.h"
#include "spark/Board.hpp"
#include "spark/Brewblox.hpp"
#include "spark/ConnectionSourceTcp.hpp"
#include "spark/Connectivity.hpp"
#include "spark_wiring_stream.h"
#include "spark_wiring_usbserial.h"

namespace app {

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

void startFirmwareUpdate(cbox::ConnectionOut& out)
{
    LED_SetRGBColor(RGB_COLOR_MAGENTA);
    getConnectionPool().disconnect();
    ticks.delayMillis(10);
#if PLATFORM_ID != PLATFORM_GCC
    updateFirmwareFromStream(out.streamType());
    // reset in case the firmware update failed
    reset(true, UserResetReason::FIRMWARE_UPDATE_FAILED);
#endif
}

cbox::CboxError respond(cbox::ConnectionOut& out, const cbox::Payload& payload)
{
    auto response = cbox::encodeResponse(payload);
    if (!response) {
        return response.error();
    }

    bool writeOk = out.write(response.value()) && out.write(cbox::Separator::CHUNK);
    out.commit();

    if (writeOk) {
        return cbox::CboxError::OK;
    } else {
        return cbox::CboxError::NETWORK_WRITE_ERROR;
    }
}

void finalize(cbox::ConnectionOut& out, uint32_t msgId, cbox::CboxError status)
{
    auto response = cbox::encodeResponse(msgId, status);
    if (response) {
        out.write(response.value());
    }

    out.write(cbox::Separator::MESSAGE);
    out.commit();
}

void handleCommand(cbox::ConnectionOut& out, const std::string& message)
{
    auto parsed = cbox::parseRequest(message);

    if (!parsed) {
        return;
    }

    auto& request = parsed.value();
    auto status = cbox::CboxError::UNKNOWN_ERROR;

    auto callback = [&out](const cbox::Payload& payload) -> cbox::CboxError {
        return respond(out, payload);
    };

    switch (request.opcode) {
    case cbox::Opcode::NONE:
    case cbox::Opcode::VERSION:
        status = cbox::CboxError::OK;
        out.write(cbox::handshakeMessage());
        out.commit();
        break;
    case cbox::Opcode::BLOCK_READ:
        status = cbox::readBlock(request.payload, callback);
        break;
    case cbox::Opcode::BLOCK_READ_ALL:
        status = cbox::readAllBlocks(callback);
        break;
    case cbox::Opcode::BLOCK_WRITE:
        status = cbox::writeBlock(request.payload, callback);
        break;
    case cbox::Opcode::BLOCK_CREATE:
        status = cbox::createBlock(request.payload, callback);
        break;
    case cbox::Opcode::BLOCK_DELETE:
        status = cbox::deleteBlock(request.payload);
        break;
    case cbox::Opcode::BLOCK_DISCOVER:
        status = cbox::discoverBlocks(callback);
        break;
    case cbox::Opcode::STORAGE_READ:
        status = cbox::readStoredBlock(request.payload, callback);
        break;
    case cbox::Opcode::STORAGE_READ_ALL:
        status = cbox::readAllStoredBlocks(callback);
        break;
    case cbox::Opcode::REBOOT:
        finalize(out, request.msgId, cbox::CboxError::OK);
        ticks.delayMillis(100);
        reset(true, UserResetReason::CBOX_RESET);
        return; // already finalized
    case cbox::Opcode::CLEAR_BLOCKS:
        status = cbox::clearBlocks();
        break;
    case cbox::Opcode::CLEAR_WIFI:
        status = cbox::CboxError::OK;
        clearWifiCredentials();
        break;
    case cbox::Opcode::FACTORY_RESET:
        finalize(out, request.msgId, cbox::CboxError::OK);
        cbox::unloadBlocks();
        cbox::getStorage().clear();
        clearWifiCredentials();
        ticks.delayMillis(100);
        reset(true, UserResetReason::CBOX_FACTORY_RESET);
        return; // already finalized
    case cbox::Opcode::FIRMWARE_UPDATE:
        finalize(out, request.msgId, cbox::CboxError::OK);
        startFirmwareUpdate(out);
        return; // already finalized
    default:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    }

    finalize(out, request.msgId, status);
}

void communicate()
{
    getConnectionPool().process(handleCommand);
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
