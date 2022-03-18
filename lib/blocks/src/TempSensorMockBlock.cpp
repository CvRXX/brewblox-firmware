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

#include "blocks/TempSensorMockBlock.h"
#include "proto/TempSensorMock.pb.h"

bool TempSensorMockBlock::streamFluctuationsOut(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
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

bool TempSensorMockBlock::streamFluctuationsIn(pb_istream_t* stream, const pb_field_t*, void** arg)
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
           + 4 // strippedFields
        ;
}

void TempSensorMockBlock::writeMessage(blox_TempSensorMock_Block& message) const
{
    FieldTags stripped;

    message.fluctuations.funcs.encode = &streamFluctuationsOut;
    message.fluctuations.arg = const_cast<std::vector<Fluctuation>*>(&sensor.fluctuations());

    if (sensor.valid()) {
        message.value = cnl::unwrap((sensor.value()));
    } else {
        stripped.add(blox_TempSensorMock_Block_value_tag);
    }

    message.setting = cnl::unwrap((sensor.setting()));
    message.connected = sensor.connected();
    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);
}

cbox::CboxError
TempSensorMockBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;

    writeMessage(message);

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_TempSensorMock_Block_fields,
                           protoSize());
}

cbox::CboxError
TempSensorMockBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;

    writeMessage(message);
    message.value = 0; // value does not need persisting

    return callWithMessage(callback,
                           objectId,
                           staticTypeId(),
                           0,
                           &message,
                           blox_TempSensorMock_Block_fields,
                           protoSize());
}

cbox::CboxError
TempSensorMockBlock::write(const cbox::Payload& payload)
{
    blox_TempSensorMock_Block message = blox_TempSensorMock_Block_init_zero;
    std::vector<Fluctuation> newFlucts;
    message.fluctuations.funcs.decode = &streamFluctuationsIn;
    message.fluctuations.arg = &newFlucts;

    auto res = payloadToMessage(payload, &message, blox_TempSensorMock_Block_fields);

    if (res == cbox::CboxError::OK) {
        sensor.fluctuations(std::move(newFlucts));
        sensor.setting(cnl::wrap<temp_t>(message.setting));
        sensor.connected(message.connected);
    }

    return res;
}

cbox::update_t TempSensorMockBlock::update(const cbox::update_t& now)
{
    return sensor.update(now);
}

void* TempSensorMockBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_TempSensorMock) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<TempSensor>()) {
        // return the member that implements the interface in this case
        TempSensor* ptr = &sensor;
        return ptr;
    }
    return nullptr;
}
