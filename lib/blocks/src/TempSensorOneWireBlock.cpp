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
#include "cbox/PayloadConversion.hpp"
#include "proto/TempSensorOneWire.pb.h"

TempSensorOneWireBlock::TempSensorOneWireBlock()
    : OneWireDeviceBlock(0)
    , sensor(busPtr())
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::obj_id_t busId)
    : OneWireDeviceBlock(busId)
    , sensor(busPtr())
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::obj_id_t busId, OneWireAddress addr)
    : OneWireDeviceBlock(busId)
    , sensor(busPtr(), std::move(addr))
{
}

cbox::CboxError
TempSensorOneWireBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    if (auto val = sensor.value()) {
        message.value = cnl::unwrap(*val);
    } else {
        excluded.push_back(blox_TempSensorOneWire_Block_value_tag);
    }

    message.oneWireBusId = getBusId();
    message.address = uint64_t(sensor.address());
    message.offset = cnl::unwrap(sensor.getCalibration());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorOneWire_Block_fields,
                     blox_TempSensorOneWire_Block_size)
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorOneWireBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(sensor.address());
    message.offset = cnl::unwrap(sensor.getCalibration());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorOneWire_Block_fields,
                     blox_TempSensorOneWire_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorOneWireBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TempSensorOneWire_Block_fields)) {
        if (parser.hasField(blox_TempSensorOneWire_Block_oneWireBusId_tag)) {
            if (message.oneWireBusId) {
                busPtr().setId(message.oneWireBusId);
            }
        }
        if (parser.hasField(blox_TempSensorOneWire_Block_address_tag)) {
            sensor.address(OneWireAddress(message.address));
        }
        if (parser.hasField(blox_TempSensorOneWire_Block_offset_tag)) {
            sensor.setCalibration(cnl::wrap<temp_t>(message.offset));
        }
    }

    return parser.status();
}

cbox::update_t TempSensorOneWireBlock::updateHandler(cbox::update_t now)
{
    return sensor.update(now);
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
