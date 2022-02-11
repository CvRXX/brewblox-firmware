/*
 * Copyright 2020 BrewPi B.V.
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
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "TempSensorCombiBlock.h"
#include "FieldTags.h"

cbox::CboxError TempSensorCombiBlock::streamFrom(cbox::DataIn& in)
{
    blox_TempSensorCombi_Block newData = blox_TempSensorCombi_Block_init_zero;
    cbox::CboxError result = streamProtoFrom(in, &newData, blox_TempSensorCombi_Block_fields, blox_TempSensorCombi_Block_size);
    if (result == cbox::CboxError::OK) {
        sensor.func = TempSensorCombi::CombineFunc(newData.combineFunc);
        inputs.clear();
        sensor.inputs.clear();
        inputs.reserve(newData.sensors_count);
        sensor.inputs.reserve(newData.sensors_count);
        for (uint8_t i = 0; i < newData.sensors_count && i < 8; i++) {
            inputs.emplace_back(objectsRef, newData.sensors[i]);
        }
        for (auto& i : inputs) {
            sensor.inputs.push_back(i.lockFunctor());
        }
    }
    return result;
}

void TempSensorCombiBlock::writeMessage(blox_TempSensorCombi_Block& message, bool includeReadOnly) const
{
    FieldTags stripped;

    message.sensors_count = sensor.inputs.size();
    message.combineFunc = blox_TempSensorCombi_SensorCombiFunc(sensor.func);
    for (uint8_t i = 0; i < message.sensors_count && i < 8; i++) {
        message.sensors[i] = inputs[i].getId();
    }

    if (includeReadOnly) {
        if (sensor.valid()) {
            message.value = cnl::unwrap((sensor.value()));
        } else {
            stripped.add(blox_TempSensorCombi_Block_value_tag);
        }
    }
    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);
}

cbox::CboxError TempSensorCombiBlock::streamTo(cbox::DataOut& out) const
{
    blox_TempSensorCombi_Block message = blox_TempSensorCombi_Block_init_zero;
    writeMessage(message, true);

    return streamProtoTo(out, &message, blox_TempSensorCombi_Block_fields, blox_TempSensorCombi_Block_size);
}

cbox::CboxError TempSensorCombiBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_TempSensorCombi_Block message = blox_TempSensorCombi_Block_init_zero;
    writeMessage(message, false);
    return streamProtoTo(out, &message, blox_TempSensorCombi_Block_fields, blox_TempSensorCombi_Block_size);
}

cbox::update_t TempSensorCombiBlock::update(const cbox::update_t& now)
{
    sensor.update();
    return update_1s(now);
}

void* TempSensorCombiBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_TempSensorCombi) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        // return the member that implements the interface in this case
        TempSensor* ptr = &sensor;
        return ptr;
    }
    return nullptr;
}