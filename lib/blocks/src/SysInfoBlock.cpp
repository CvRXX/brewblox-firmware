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

#include "intellisense.hpp"

#include "AppTicks.hpp"
#include "blocks/SysInfoBlock.hpp"
#include "blox_hal/hal_network.hpp"
#include "cbox/PayloadConversion.hpp"
#include "intellisense.hpp"
#include "proto/proto_version.h"
#include <cstring>

cbox::CboxError
SysInfoBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_SysInfo_Block message = blox_SysInfo_Block_init_zero;

    auto written = device_id_func(static_cast<uint8_t*>(&message.deviceId.bytes[0]), 12);
    message.deviceId.size = written;

    strncpy(message.version, GIT_VERSION, 12);
    message.platform = blox_SysInfo_Platform(PLATFORM_ID);

    strncpy(message.protocolVersion, COMPILED_PROTO_VERSION, 12);
    strncpy(message.releaseDate, GIT_DATE, 12);
    strncpy(message.protocolDate, COMPILED_PROTO_DATE, 12);

    message.ip = network::ip4();
    message.uptime = ticks.millis();
    message.updatesPerSecond = _updateRate;
    message.systemTime = ticks.utc();
    strncpy(message.timeZone, _settings.timeZone.c_str(), _settings.timeZone.size());
    message.tempUnit = blox_SysInfo_TemperatureUnit(_settings.tempUnit);
    message.displayBrightness = _settings.displayBrightness;

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_SysInfo_Block_fields,
                     blox_SysInfo_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
SysInfoBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_SysInfo_Block message = blox_SysInfo_Block_init_zero;

    strncpy(message.timeZone, _settings.timeZone.c_str(), _settings.timeZone.size());
    message.tempUnit = blox_SysInfo_TemperatureUnit(_settings.tempUnit);
    message.displayBrightness = _settings.displayBrightness;

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_SysInfo_Block_fields,
                     blox_SysInfo_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
SysInfoBlock::write(const cbox::Payload& payload)
{
    blox_SysInfo_Block message = blox_SysInfo_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_SysInfo_Block_fields)) {
        if (parser.hasField(blox_SysInfo_Block_systemTime_tag)) {
            // Only accept UTC time from block write if we don't already have a value
            if (ticks.utc() < MIN_VALID_UTC && message.systemTime > MIN_VALID_UTC) {
                ticks.setUtc(message.systemTime);
            }
        }
        if (parser.hasField(blox_SysInfo_Block_timeZone_tag)) {
            _newSettingsReceived = true;
            _settings.timeZone = std::string(message.timeZone);
        }
        if (parser.hasField(blox_SysInfo_Block_tempUnit_tag)) {
            _newSettingsReceived = true;
            _settings.tempUnit = TempUnit(message.tempUnit);
        }
        if (parser.hasField(blox_SysInfo_Block_displayBrightness_tag)) {
            _newSettingsReceived = true;
            _settings.displayBrightness = message.displayBrightness;
        }
    }

    return parser.status();
}

cbox::update_t SysInfoBlock::updateHandler(cbox::update_t now)
{
    // group per 3.5 seconds
    // Short enough to have unique data for every default interval poll (5s)
    static constexpr auto interval = cbox::update_t{3'500};
    _lastUpdate = now;
    auto elapsed = now - _updateCounterStart;
    if (elapsed >= interval) {
        // update rate is scaled in proto
        _updateRate = (uint64_t{_updateCounter} * 1'000'000) / elapsed;
        _updateCounter = 0;
        _updateCounterStart = now;
    }
    _updateCounter++;
    return now + 1;
}

SystemSettings SysInfoBlock::_settings = SystemSettings{};
bool SysInfoBlock::_newSettingsReceived = false;
