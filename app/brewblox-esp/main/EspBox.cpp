#include "EspBox.hpp"
#include "Brewblox.hpp"
#include "cbox/Application.hpp"
#include "cbox/Connection.hpp"
#include "cbox/Serialization.hpp"
#include "esp_system.h"
#include "network/CboxConnection.hpp"

cbox::CboxExpected<cbox::Request> parseRequest(cbox::RegionDataIn& in)
{
    if (in.available() == 0) {
        return tl::make_unexpected(cbox::CboxError::NETWORK_READ_ERROR);
    }

    auto b64Bytes = std::vector<uint8_t>(in.available());
    in.readBytes(b64Bytes.data(), b64Bytes.size());

    return cbox::parseRequest(b64Bytes);
}

cbox::CboxError respond(cbox::DataOut& out, const cbox::Payload& payload)
{
    auto response = cbox::encodeResponse(payload);
    if (!response) {
        return response.error();
    }

    auto& encoded = response.value();
    if (out.writeBuffer(encoded.data(), encoded.size())
        && out.write(',')) {
        return cbox::CboxError::OK;
    } else {
        return cbox::CboxError::NETWORK_WRITE_ERROR;
    }
}

void finalize(cbox::DataOut& out, uint32_t msgId, cbox::CboxError status)
{
    auto response = cbox::encodeResponse(msgId, status);
    if (!response) {
        out.write('\n');
        return;
    }

    auto& encoded = response.value();
    out.writeBuffer(encoded.data(), encoded.size());
    out.write('\n');
}

void handleCommand(cbox::RegionDataIn& in, cbox::DataOut& out)
{
    auto parsed = parseRequest(in);

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
        cbox::connectionStarted(out);
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
        esp_restart();
        return; // already finalized
    case cbox::Opcode::CLEAR_BLOCKS:
        status = cbox::clearBlocks();
        break;
    case cbox::Opcode::CLEAR_WIFI:
        status = cbox::CboxError::OK; // TODO(Bob)
        break;
    case cbox::Opcode::FACTORY_RESET:
        status = cbox::clearBlocks(); // TODO(Bob)
        finalize(out, request.msgId, status);
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
