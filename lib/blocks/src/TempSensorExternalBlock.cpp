/*
 * Copyright 2022 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
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

#include "blocks/TempSensorExternalBlock.hpp"
#include "AppTicks.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/TempSensorExternal.pb.h"

cbox::CboxError
TempSensorExternalBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorExternal_Block message = blox_TempSensorExternal_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.enabled = _enabler.get();
    message.timeout = _timeout;
    message.lastUpdated = _lastUpdated;
    message.setting = cnl::unwrap(_setting);

    if (valid()) {
        message.value = cnl::unwrap(_setting);
    } else {
        excluded.push_back(blox_TempSensorExternal_Block_value_tag);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorExternal_Block_fields,
                     blox_TempSensorExternal_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorExternalBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorExternal_Block message = blox_TempSensorExternal_Block_init_zero;

    message.enabled = _enabler.get();
    message.timeout = _timeout;
    message.lastUpdated = _lastUpdated;
    message.setting = cnl::unwrap(_setting);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorExternal_Block_fields,
                     blox_TempSensorExternal_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorExternalBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorExternal_Block message = blox_TempSensorExternal_Block_init_zero;

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TempSensorExternal_Block_fields)) {
        auto hasLastUpdated = parser.hasField(blox_TempSensorExternal_Block_lastUpdated_tag);
        auto hasSetting = parser.hasField(blox_TempSensorExternal_Block_setting_tag);
        auto utc = ticks.utc();

        if (parser.hasField(blox_TempSensorExternal_Block_enabled_tag)) {
            _enabler.set(message.enabled);
        }
        if (parser.hasField(blox_TempSensorExternal_Block_timeout_tag)) {
            if (message.timeout > MIN_VALID_UTC) {
                /**
                 * If timeout > UTC and UTC > MIN_VALID_UTC,
                 * The validity check in updateHandler() will wrap around.
                 * This would cause a false result if users try and use uint32_t(-1)
                 * as "infinite" timeout.
                 *
                 * 0 already serves as infinite timeout, and MIN_VALID_UTC is 31.5 years.
                 * Restricting timeout to a range of 1s-31.5y is an acceptable tradeoff
                 * to prevent the footgun configuration value.
                 */
                return cbox::CboxError::INVALID_BLOCK_CONTENT;
            }
            _timeout = message.timeout;
        }
        if (hasLastUpdated || hasSetting) {
            if (message.lastUpdated > MIN_VALID_UTC) {
                _lastUpdated = message.lastUpdated;
            } else if (utc > MIN_VALID_UTC) {
                _lastUpdated = utc;
            } else {
                _lastUpdated = 0;
            }
        }
        if (hasSetting) {
            _setting = cnl::wrap<temp_t>(message.setting);
        }
    }

    return parser.status();
}

cbox::update_t TempSensorExternalBlock::updateHandler(const cbox::update_t& now)
{
    auto utc = ticks.utc();
    _settingValid = _timeout == 0
                    || (utc > MIN_VALID_UTC && utc - _timeout < _lastUpdated);
    return next_update_1s(now);
}

void* TempSensorExternalBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        TempSensor* ptr = this;
        return ptr;
    }
    if (iface == cbox::interfaceId<Enabler>()) {
        Enabler* ptr = &_enabler;
        return ptr;
    }
    return nullptr;
}
