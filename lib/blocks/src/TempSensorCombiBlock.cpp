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
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/TempSensorCombiBlock.hpp"
#include "cbox/PayloadConversion.hpp"

void TempSensorCombiBlock::encodeStoredMessage(blox_TempSensorCombi_Block& message) const
{
    message.sensors_count = inputs.size();
    message.combineFunc = blox_TempSensorCombi_SensorCombiFunc(sensor.func);
    for (uint8_t i = 0; i < message.sensors_count && i < 8; i++) {
        message.sensors[i] = inputs[i].getId();
    }
}

cbox::CboxError
TempSensorCombiBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorCombi_Block message = blox_TempSensorCombi_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    encodeStoredMessage(message);

    if (auto val = sensor.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_TempSensorCombi_Block_value_tag);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorCombi_Block_fields,
                     blox_TempSensorCombi_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorCombiBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorCombi_Block message = blox_TempSensorCombi_Block_init_zero;
    encodeStoredMessage(message);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorCombi_Block_fields,
                     blox_TempSensorCombi_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorCombiBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorCombi_Block message = blox_TempSensorCombi_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TempSensorCombi_Block_fields)) {
        if (parser.hasField(blox_TempSensorCombi_Block_combineFunc_tag)) {
            sensor.func = TempSensorCombi::CombineFunc(message.combineFunc);
        }
        if (parser.hasField(blox_TempSensorCombi_Block_sensors_tag)) {
            sensor.inputs.clear();
            sensor.inputs.reserve(message.sensors_count);
            inputs.clear();
            inputs.reserve(message.sensors_count);
            for (uint8_t i = 0; i < message.sensors_count && i < 8; i++) {
                auto& input = inputs.emplace_back(message.sensors[i]);
                sensor.inputs.emplace_back(input);
            }
        }
    }

    return parser.status();
}

cbox::update_t TempSensorCombiBlock::updateHandler(const cbox::update_t& now)
{
    sensor.update();
    return next_update_1s(now);
}

void* TempSensorCombiBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        // return the member that implements the interface in this case
        TempSensor* ptr = &sensor;
        return ptr;
    }
    return nullptr;
}
