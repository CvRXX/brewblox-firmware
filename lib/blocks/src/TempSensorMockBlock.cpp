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

#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/TempSensorMock.pb.h"

bool TempSensorMockBlock::encodeFluctuations(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    const std::vector<Fluctuation>* flucts = reinterpret_cast<std::vector<Fluctuation>*>(*arg);
    for (const auto& f : *flucts) {
        auto submsg = blox_TempSensorMock_Fluctuation();
        submsg.amplitude = cnl::unwrap(f.amplitude);
        submsg.period = f.period;
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_submessage(stream, blox_TempSensorMock_Fluctuation_fields, &submsg)) {
            return false;
        }
    }
    return true;
}

bool TempSensorMockBlock::decodeFluctuations(pb_istream_t* stream, const pb_field_t*, void** arg)
{
    std::vector<Fluctuation>* newFlucts = reinterpret_cast<std::vector<Fluctuation>*>(*arg);

    if (stream->bytes_left) {
        blox_TempSensorMock_Fluctuation submsg = blox_TempSensorMock_Fluctuation_init_zero;
        if (!pb_decode(stream, blox_TempSensorMock_Fluctuation_fields, &submsg)) {
            return false;
        }
        newFlucts->push_back(Fluctuation{
            cnl::wrap<decltype(Fluctuation::amplitude)>(submsg.amplitude), submsg.period});
    }
    return true;
}

size_t TempSensorMockBlock::protoSize() const
{
    return (blox_TempSensorMock_Fluctuation_size + 2) * sensor.fluctuations().size()
           + 6 // value
           + 3 // connected
           + 6 // setting
        ;
}

cbox::CboxError
TempSensorMockBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;
    std::vector<cbox::obj_field_tag_t> excluded;

    message.fluctuations.funcs.encode = &encodeFluctuations;
    message.fluctuations.arg = const_cast<std::vector<Fluctuation>*>(&sensor.fluctuations());

    message.setting = cnl::unwrap((sensor.setting()));
    message.connected = sensor.connected();

    if (auto val = sensor.value()) {
        message.value = cnl::unwrap((*val));
    } else {
        excluded.push_back(blox_TempSensorMock_Block_value_tag);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorMock_Block_fields,
                     protoSize())
        .withMask(cbox::MaskMode::EXCLUSIVE, std::move(excluded))
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorMockBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;

    message.fluctuations.funcs.encode = &encodeFluctuations;
    message.fluctuations.arg = const_cast<std::vector<Fluctuation>*>(&sensor.fluctuations());

    message.setting = cnl::unwrap((sensor.setting()));
    message.connected = sensor.connected();

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_TempSensorMock_Block_fields,
                     protoSize())
        .respond(callback)
        .status();
}

cbox::CboxError
TempSensorMockBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;
    std::vector<Fluctuation> newFlucts;
    message.fluctuations.funcs.decode = &decodeFluctuations;
    message.fluctuations.arg = &newFlucts;

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_TempSensorMock_Block_fields)) {
        if (parser.hasField(blox_TempSensorMock_Block_fluctuations_tag)) {
            sensor.fluctuations(std::move(newFlucts));
        }
        if (parser.hasField(blox_TempSensorMock_Block_setting_tag)) {
            sensor.setting(cnl::wrap<temp_t>(message.setting));
        }
        if (parser.hasField(blox_TempSensorMock_Block_connected_tag)) {
            sensor.connected(message.connected);
        }
    }

    return parser.status();
}

cbox::update_t TempSensorMockBlock::updateHandler(cbox::update_t now)
{
    return sensor.update(now);
}

void* TempSensorMockBlock::implements(cbox::obj_type_t iface)
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
