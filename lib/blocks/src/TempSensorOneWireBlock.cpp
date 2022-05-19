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

#include "blocks/TempSensorOneWireBlock.hpp"
#include "blocks/FieldTags.hpp"
#include "proto/TempSensorOneWire.pb.h"

TempSensorOneWireBlock::TempSensorOneWireBlock()
    : OneWireDeviceBlock()
    , sensor(owBus)
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::obj_id_t busId)
    : OneWireDeviceBlock(busId)
    , sensor(owBus)
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::obj_id_t busId, OneWireAddress addr)
    : OneWireDeviceBlock(busId)
    , sensor(owBus, std::move(addr))
{
}

cbox::CboxError
TempSensorOneWireBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    FieldTags stripped;

    if (sensor.valid()) {
        message.value = cnl::unwrap((sensor.value()));
    } else {
        stripped.add(blox_TempSensorOneWire_Block_value_tag);
    }

    message.oneWireBusId = owBus.getId();
    message.address = sensor.address();
    message.offset = cnl::unwrap(sensor.getCalibration());

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_TempSensorOneWire_Block_fields,
                           blox_TempSensorOneWire_Block_size);
}

cbox::CboxError
TempSensorOneWireBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;

    message.oneWireBusId = owBus.getId();
    message.address = sensor.address();
    message.offset = cnl::unwrap(sensor.getCalibration());

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_TempSensorOneWire_Block_fields,
                           blox_TempSensorOneWire_Block_size);
}

cbox::CboxError
TempSensorOneWireBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_TempSensorOneWire_Block_fields);

    if (res == cbox::CboxError::OK) {
        if (message.oneWireBusId) {
            owBus.setId(message.oneWireBusId);
        }
        sensor.address(OneWireAddress(message.address));
        sensor.setCalibration(cnl::wrap<temp_t>(message.offset));
    }

    return res;
}

cbox::update_t TempSensorOneWireBlock::updateHandler(const cbox::update_t& now)
{
    sensor.update();
    return next_update_1s(now);
}

void* TempSensorOneWireBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        // return the member that implements the interface in this case
        DS18B20* dallasPtr = &sensor;
        TempSensor* sensorPtr = dallasPtr;
        return sensorPtr;
    }
    if (iface == cbox::interfaceId<OneWireDevice>()) {
        // return the member that implements the interface in this case
        DS18B20* dallasPtr = &sensor;
        OneWireDevice* devicePtr = dallasPtr;
        return devicePtr;
    }
    if (iface == cbox::interfaceId<OneWireDeviceBlock>()) {
        // return the base that implements the interface
        OneWireDeviceBlock* ptr = this;
        return ptr;
    }
    return nullptr;
}
