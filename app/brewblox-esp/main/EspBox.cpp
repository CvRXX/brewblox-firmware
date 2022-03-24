#include "EspBox.hpp"
#include "AppTicks.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "cbox/Serialization.hpp"
#include "esp_system.h"
#include "esp_wifi.h"

enum Separator : char {
    NONE = 0,
    CHUNK = ',',
    MESSAGE = '\n',
};

cbox::CboxError respond(ResponseWriter& out, const cbox::Payload& payload)
{
    auto response = cbox::encodeResponse(payload);
    if (!response) {
        return response.error();
    }

    bool writeOk = out.write(response.value()) && out.write(Separator::CHUNK);
    out.commit();

    if (writeOk) {
        return cbox::CboxError::OK;
    } else {
        return cbox::CboxError::NETWORK_WRITE_ERROR;
    }
}

void finalize(ResponseWriter& out, uint32_t msgId, cbox::CboxError status)
{
    if (auto response = cbox::encodeResponse(msgId, status)) {
        out.write(response.value());
    }

    out.write(Separator::MESSAGE);
    out.commit();
}

void handleCommand(ResponseWriter& out, const std::string& message)
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
        out.writeLog(cbox::handshakeMessage());
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
        esp_restart();
        return; // already finalized
    case cbox::Opcode::CLEAR_BLOCKS:
        status = cbox::clearBlocks();
        break;
    case cbox::Opcode::CLEAR_WIFI:
        status = cbox::CboxError::OK; // TODO(Bob)
        break;
    case cbox::Opcode::FACTORY_RESET:
        finalize(out, request.msgId, cbox::CboxError::OK);
        ticks.delayMillis(100);
        cbox::unloadBlocks();
        cbox::getStorage().clear();
        esp_wifi_disconnect();
        // TODO(Bob) clear wifi credentials
        esp_restart();
        return; // already finalized
    case cbox::Opcode::FIRMWARE_UPDATE:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    default:
        status = cbox::CboxError::INVALID_OPCODE;
        break;
    }

    finalize(out, request.msgId, status);
}
