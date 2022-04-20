/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Controlbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/SysInfoBlock.hpp"
#include "proto/proto_version.h"
#include <cstring>

#ifndef GIT_VERSION
#error GIT_VERSION not set
#endif

// Intellisense fails to consider the quotes around the defined value
#ifdef __INTELLISENSE__
#define GIT_VERSION ""
#define GIT_DATE ""
#endif

cbox::CboxError
SysInfoBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_SysInfo_Block message = blox_SysInfo_Block_init_zero;

    auto written = device_id_func(static_cast<uint8_t*>(&message.deviceId.bytes[0]), 12);
    message.deviceId.size = written;

    strncpy(message.version, GIT_VERSION, 12);
    strncpy(message.protocolVersion, COMPILED_PROTO_VERSION, 12);
    strncpy(message.releaseDate, GIT_DATE, 12);
    strncpy(message.protocolDate, COMPILED_PROTO_DATE, 12);

    message.platform = blox_SysInfo_Platform(PLATFORM_ID);

    command = Command::NONE;

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_SysInfo_Block_fields,
                           blox_SysInfo_Block_size);
}

cbox::CboxError
SysInfoBlock::readStored(const cbox::PayloadCallback&) const
{
    return cbox::CboxError::OK;
}

cbox::CboxError
SysInfoBlock::write(const cbox::Payload& payload)
{
    blox_SysInfo_Block message = blox_SysInfo_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_SysInfo_Block_fields);

    if (res == cbox::CboxError::OK) {
        command = Command(message.command);
    }

    return res;
}
