/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/Command.h"
#include "cbox/ConnectionPool.h"
#include "cbox/DataStream.h"
#include "proto/controlbox.pb.h"

class OneWire;

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

    virtual cbox::Payload* request() override final;
    virtual cbox::CboxError respond(const cbox::Payload& payload) override final;
    void finalize(cbox::CboxError status);
};

// static objects are created on first call
cbox::ConnectionPool& theConnectionPool();
OneWire& theOneWire();

void setupSystemBlocks();
void logEvent(const std::string& event);
void update();
void communicate();

enum AppTrace : uint8_t {
    UPDATE_DISPLAY = 101,
    SYSTEM_TASKS = 102,
    MANAGE_CONNECTIVITY = 103,
    MDNS_START = 104,
    MDNS_PROCESS = 105,
    HTTP_START = 106,
    HTTP_STOP = 107,
    HTTP_RESPONSE = 108,
    WIFI_CONNECT = 109,
    FIRMWARE_UPDATE_STARTED = 110,
};
