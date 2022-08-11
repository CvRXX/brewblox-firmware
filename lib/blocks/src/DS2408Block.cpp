/*
 * Copyright 2019 BrewPi B.V.
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

#include "blocks/DS2408Block.hpp"
#include "cbox/PayloadConversion.hpp"

static constexpr uint8_t NUM_ACTUATOR_CHANNELS = 8;
static constexpr uint8_t NUM_VALVE_CHANNELS = 2;

cbox::CboxError
DS2408Block::read(const cbox::PayloadCallback& callback) const
{
    blox_DS2408_Block message = blox_DS2408_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(device.address());
    message.connected = device.connected();
    message.connectMode = connectMode;
    if (connectMode == blox_DS2408_PinConnectMode_CONNECT_ACTUATOR) {
        message.channels_count = NUM_ACTUATOR_CHANNELS;
        auto caps = device.getChannelCapabilities(1); // same for all channels
        for (uint8_t i = 0; i < NUM_ACTUATOR_CHANNELS; ++i) {
            uint8_t id = blox_DS2408_ChannelId_DS2408_CHAN_A + i;
            message.channels[i].capabilities = caps.all;
            message.channels[i].id = id;
            message.channels[i].claimedBy = device.getChannelClaimerId(id);
        }
    } else {
        message.channels_count = NUM_VALVE_CHANNELS;
        auto caps = device.getChannelCapabilities(1);
        caps.flags.bidirectional = 1;

        message.channels[0].capabilities = caps.all;
        message.channels[0].id = blox_DS2408_ChannelId_DS2408_VALVE_A;
        message.channels[0].claimedBy = device.getChannelClaimerId(1);

        message.channels[1].capabilities = caps.all;
        message.channels[1].id = blox_DS2408_ChannelId_DS2408_VALVE_B;
        message.channels[1].claimedBy = device.getChannelClaimerId(2);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DS2408_Block_fields,
                     blox_DS2408_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
DS2408Block::readStored(const cbox::PayloadCallback& callback) const
{
    blox_DS2408_Block message = blox_DS2408_Block_init_zero;

    message.oneWireBusId = getBusId();
    message.address = uint64_t(device.address());
    message.connectMode = connectMode;

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_DS2408_Block_fields,
                     blox_DS2408_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
DS2408Block::write(const cbox::Payload& payload)
{
    blox_DS2408_Block message = blox_DS2408_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_DS2408_Block_fields)) {
        if (parser.hasField(blox_DS2408_Block_oneWireBusId_tag)) {
            if (message.oneWireBusId) {
                busPtr().setId(message.oneWireBusId);
            }
        }
        if (parser.hasField(blox_DS2408_Block_address_tag)) {
            device.address(OneWireAddress(message.address));
        }
        if (parser.hasField(blox_DS2408_Block_connectMode_tag)) {
            connectMode = message.connectMode;
        }
    }

    return parser.status();
}

cbox::update_t
DS2408Block::updateHandler(cbox::update_t now)
{
    device.update();
    return next_update_1s(now);
}

void* DS2408Block::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
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
