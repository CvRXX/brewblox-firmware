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
#include "blocks/FieldTags.hpp"
#include "proto/SetpointSensorPair.pb.h"

cbox::CboxError
SetpointSensorPairBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;
    FieldTags stripped;

    message.sensorId = sensor.getId();
    message.settingEnabled = pair.settingValid();
    message.storedSetting = cnl::unwrap(pair.setting());
    if (pair.valueValid()) {
        message.value = cnl::unwrap(pair.value());
    } else {
        stripped.add(blox_SetpointSensorPair_Block_value_tag);
    }
    if (pair.settingValid()) {
        message.setting = cnl::unwrap(pair.setting());
    } else {
        stripped.add(blox_SetpointSensorPair_Block_setting_tag);
    };
    if (pair.sensorValid()) {
        message.valueUnfiltered = cnl::unwrap(pair.valueUnfiltered());
    } else {
        stripped.add(blox_SetpointSensorPair_Block_valueUnfiltered_tag);
    }

    message.filter = blox_SetpointSensorPair_FilterChoice(pair.filterChoice());
    message.filterThreshold = cnl::unwrap(pair.filterThreshold());

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 3);

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_SetpointSensorPair_Block_fields,
                           blox_SetpointSensorPair_Block_size);
}

cbox::CboxError
SetpointSensorPairBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;

    message.sensorId = sensor.getId();
    message.storedSetting = cnl::unwrap(pair.setting());
    message.settingEnabled = pair.settingValid();
    message.filter = blox_SetpointSensorPair_FilterChoice(pair.filterChoice());
    message.filterThreshold = cnl::unwrap(pair.filterThreshold());

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_SetpointSensorPair_Block_fields,
                           blox_SetpointSensorPair_Block_size);
}

cbox::CboxError
SetpointSensorPairBlock::write(const cbox::Payload& payload)
{
    blox_SetpointSensorPair_Block message = blox_SetpointSensorPair_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_SetpointSensorPair_Block_fields);

    if (res == cbox::CboxError::OK) {
        pair.setting(cnl::wrap<temp_t>(message.storedSetting));
        pair.settingValid(message.settingEnabled);
        pair.filterChoice(uint8_t(message.filter));
        pair.filterThreshold(cnl::wrap<fp12_t>(message.filterThreshold));

        if (message.resetFilter || sensor.getId() != message.sensorId) {
            sensor.setId(message.sensorId);
            pair.resetFilter();
        }
        pair.update(); // force an update that bypasses the update interval
    }

    return res;
}

cbox::update_t
SetpointSensorPairBlock::update(const cbox::update_t& now)
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
    if (iface == brewblox_BlockType_SetpointSensorPair) {
        return this; // me!
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
    return nullptr;
}
