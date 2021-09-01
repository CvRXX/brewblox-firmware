/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewBlox
 *
 * BrewBlox is free software: you can redistribute it and/or modify
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
 * along with BrewBlox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "DS2408Block.h"

cbox::CboxError
DS2408Block::streamFrom(cbox::DataIn& in)
{
    blox_DS2408 newData = blox_DS2408_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_DS2408_fields, blox_DS2408_size);
    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
        owBus.setId(newData.oneWireBusId);
        device.address(OneWireAddress(newData.address));
        connectMode = newData.connectMode;
    }
    return res;
}

cbox::CboxError
DS2408Block::streamTo(cbox::DataOut& out) const
{
    blox_DS2408 message = blox_DS2408_init_zero;

    message.oneWireBusId = owBus.getId();
    message.address = device.address();
    message.connected = device.connected();
    message.connectMode = connectMode;
    if (connectMode == blox_DS2408_PinConnectMode_CONNECT_ACTUATOR) {
        message.channels_count = 8;
        message.channels[0].id = 1;
        message.channels[1].id = 2;
        message.channels[2].id = 3;
        message.channels[3].id = 4;
        message.channels[4].id = 5;
        message.channels[5].id = 6;
        message.channels[6].id = 7;
        message.channels[7].id = 8;
    } else {
        message.channels_count = 2;
        message.channels[0].id = 1;
        message.channels[1].id = 5;
    }

    return streamProtoTo(out, &message, blox_DS2408_fields, blox_DS2408_size);
}

cbox::CboxError
DS2408Block::streamPersistedTo(cbox::DataOut& out) const
{
    blox_DS2408 message = blox_DS2408_init_zero;

    message.oneWireBusId = owBus.getId();
    message.address = device.address();
    message.connectMode = connectMode;
    return streamProtoTo(out, &message, blox_DS2408_fields, blox_DS2408_size);
}

cbox::update_t
DS2408Block::update(const cbox::update_t& now)
{
    device.update();
    return update_1s(now);
}

void* DS2408Block::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_DS2408) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = &device;
        return ptr;
    }
    if (iface == cbox::interfaceId<DS2408>()) {
        // return the member that implements the interface in this case
        return &device;
    }
    if (iface == cbox::interfaceId<OneWireDevice>()) {
        // return the member that implements the interface in this case
        DS2408* dsPtr = &device;
        OneWireDevice* devicePtr = dsPtr;
        return devicePtr;
    }
    if (iface == cbox::interfaceId<OneWireDeviceBlock>()) {
        // return the base that implements the interface
        OneWireDeviceBlock* ptr = this;
        return ptr;
    }
    return nullptr;
}
