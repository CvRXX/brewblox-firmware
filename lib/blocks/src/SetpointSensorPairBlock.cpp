/*
 * Copyright 2020 BrewPi B.V.
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
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/SetpointSensorPairBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/SetpointSensorPair.pb.h"

cbox::CboxError
SetpointSensorPairBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.enabled = pair.enabler.get();
    message.sensorId = sensor.getId();
    message.storedSetting = cnl::unwrap(pair.setting().value_or(0));
    if (auto val = pair.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_SetpointSensorPair_Block_value_tag);
    }
    message.enabled = pair.enabler.get();
    if (auto val = pair.setting()) {
        message.setting = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_SetpointSensorPair_Block_setting_tag);
    }
    if (auto val = pair.valueUnfiltered()) {
        message.valueUnfiltered = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_SetpointSensorPair_Block_valueUnfiltered_tag);
    }

    message.filter = blox_SetpointSensorPair_FilterChoice(pair.filterChoice());
    message.filterThreshold = cnl::unwrap(pair.filterThreshold());
    message.claimedBy = claim.claimedBy();

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_SetpointSensorPair_Block_fields,
                     blox_SetpointSensorPair_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
SetpointSensorPairBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;

    message.sensorId = sensor.getId();
    message.enabled = pair.enabler.get();
    if (auto val = pair.setting()) {
        message.storedSetting = cnl::unwrap(*val);
    } else {
        message.storedSetting = 0;
        message.enabled = false;
    }
    message.filter = blox_SetpointSensorPair_FilterChoice(pair.filterChoice());
    message.filterThreshold = cnl::unwrap(pair.filterThreshold());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_SetpointSensorPair_Block_fields,
                     blox_SetpointSensorPair_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
SetpointSensorPairBlock::write(const cbox::Payload& payload)
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_SetpointSensorPair_Block_fields)) {
        bool filterResetRequired = false;

        if (parser.hasField(blox_SetpointSensorPair_Block_storedSetting_tag)) {
            pair.setting(cnl::wrap<temp_t>(message.storedSetting));
        }
        if (parser.hasField(blox_SetpointSensorPair_Block_filter_tag)) {
            pair.filterChoice(uint8_t(message.filter));
        }
        if (parser.hasField(blox_SetpointSensorPair_Block_filterThreshold_tag)) {
            pair.filterThreshold(cnl::wrap<fp12_t>(message.filterThreshold));
        }
        if (parser.hasField(blox_SetpointSensorPair_Block_resetFilter_tag)) {
            filterResetRequired = filterResetRequired || message.resetFilter;
        }
        if (parser.hasField(blox_SetpointSensorPair_Block_sensorId_tag)) {
            if (sensor.getId() != message.sensorId) {
                sensor.setId(message.sensorId);
                filterResetRequired = true;
            }
        }
        if (parser.hasField(blox_SetpointSensorPair_Block_enabled_tag)) {
            pair.enabler.set(message.enabled);
        }

        if (filterResetRequired) {
            pair.resetFilter();
        }

        // force an update that bypasses the update interval
        pair.update();
    }

    return parser.status();
}

cbox::update_t
SetpointSensorPairBlock::updateHandler(cbox::update_t now)
{
    bool doUpdate = false;
    auto nextUpdate = m_intervalHelper.update(now, doUpdate);

    if (doUpdate) {
        pair.update();
    }
    return nextUpdate;
}

void* SetpointSensorPairBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<cbox::Claimable>()) {
        cbox::Claimable* ptr = &claim;
        return ptr;
    }
    if (iface == cbox::interfaceId<ProcessValue<temp_t>>()) {
        // return the member that implements the interface in this case
        ProcessValue<temp_t>* ptr = &pair;
        return ptr;
    }
    if (iface == cbox::interfaceId<SetpointSensorPair>()) {
        SetpointSensorPair* ptr = &pair;
        return ptr;
    }
    if (iface == cbox::interfaceId<Enabler>()) {
        Enabler* ptr = &pair.enabler;
        return ptr;
    }
    return nullptr;
}
