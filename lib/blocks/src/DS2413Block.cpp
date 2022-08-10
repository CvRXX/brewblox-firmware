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
#include "cbox/PayloadConversion.hpp"
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
    message.channels[0].capabilities = device.getChannelCapabilities(1).all;
    message.channels[1].capabilities = device.getChannelCapabilities(2).all;
    message.channels[0].claimedBy = device.claimedBy(1);
    message.channels[1].claimedBy = device.claimedBy(2);

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DS2413_Block_fields,
                     blox_DS2413_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
DS2413Block::readStored(const cbox::PayloadCallback& callback) const
{
    blox_DS2413_Block message = blox_DS2413_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(device.address());

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DS2413_Block_fields,
                     blox_DS2413_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
DS2413Block::write(const cbox::Payload& payload)
{
    blox_DS2413_Block message = blox_DS2413_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_DS2413_Block_fields)) {
        if (parser.hasField(blox_DS2413_Block_oneWireBusId_tag)) {
            if (message.oneWireBusId) {
                busPtr().setId(message.oneWireBusId);
            }
        }
        if (parser.hasField(blox_DS2413_Block_address_tag)) {
            device.address(OneWireAddress(message.address));
        }
    }

    return parser.status();
}

cbox::update_t
DS2413Block::updateHandler(cbox::update_t now)
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
