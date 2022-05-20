/*
 * Copyright 2018 BrewPi B.V.
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

#include "blocks/DS2413Block.hpp"
#include "proto/DS2413.pb.h"

cbox::CboxError
DS2413Block::read(const cbox::PayloadCallback& callback) const
{
    blox_DS2413_Block message = blox_DS2413_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(device.address());
    message.connected = device.connected();

    message.channels_count = 2;
    message.channels[0].id = blox_DS2413_ChannelId_DS2413_CHAN_A;
    message.channels[1].id = blox_DS2413_ChannelId_DS2413_CHAN_B;

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_DS2413_Block_fields,
                           blox_DS2413_Block_size);
}

cbox::CboxError
DS2413Block::readStored(const cbox::PayloadCallback& callback) const
{
    blox_DS2413_Block message = blox_DS2413_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(device.address());

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_DS2413_Block_fields,
                           blox_DS2413_Block_size);
}

cbox::CboxError
DS2413Block::write(const cbox::Payload& payload)
{
    blox_DS2413_Block message = blox_DS2413_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_DS2413_Block_fields);

    if (res == cbox::CboxError::OK) {
        if (message.oneWireBusId) {
            busPtr().setId(message.oneWireBusId);
        }
        device.address(OneWireAddress(message.address));
    }

    return res;
}

cbox::update_t
DS2413Block::updateHandler(const cbox::update_t& now)
{
    device.update();
    return next_update_1s(now);
}

void* DS2413Block::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface
        IoArray* ptr = &device;
        return ptr;
    }
    if (iface == cbox::interfaceId<OneWireDevice>()) {
        // return the member that implements the interface
        DS2413* dsPtr = &device;
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
