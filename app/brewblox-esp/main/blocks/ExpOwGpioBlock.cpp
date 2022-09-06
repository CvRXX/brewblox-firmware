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

#include "./ExpOwGpioBlock.hpp"
#include "cbox/PayloadConversion.hpp"

cbox::CboxError ExpOwGpioBlock::handleRead(const cbox::PayloadCallback& callback, bool includeNotPersisted) const
{
    blox_OneWireGpioModule_Block message = blox_OneWireGpioModule_Block_init_zero;

    message.modulePosition = drivers.modulePosition();
    message.channels_count = 0;
    message.useExternalPower = drivers.externalPowerEnabled();

    for (uint8_t i = 1; i <= 8; i++) {
        auto& c = drivers.getFlexChannel(i);
        if (c.deviceType != blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE) {
            uint8_t ci = message.channels_count;
            ++message.channels_count;
            message.channels[ci].id = i;
            message.channels[ci].deviceType = c.deviceType;
            message.channels[ci].width = c.width;
            message.channels[ci].pinsMask = c.pins();
            if (includeNotPersisted) {
                message.channels[ci].capabilities = drivers.getChannelCapabilities(i).all;
                message.channels[ci].claimedBy = drivers.getChannelClaimerId(i);
            }
            auto entry = std::find_if(channelNames.begin(), channelNames.end(), [i](const ChannelNameEntry& e) {
                return e.id == i;
            });
            if (entry != channelNames.end()) {
                entry->name.copy(message.channels[ci].name, sizeof(message.channels[ci].name));
            }
        }
    }

    if (includeNotPersisted) {
        message.moduleStatus = drivers.status().all;
        message.pullUpDesired = drivers.pullUpDesired();
        message.pullUpStatus = drivers.pullUpStatus();
        message.pullUpWhenActive = drivers.pullUpWhenActive();
        message.pullUpWhenInactive = drivers.pullUpWhenInactive();
        message.pullDownDesired = drivers.pullDownDesired();
        message.pullDownStatus = drivers.pullDownStatus();
        message.pullDownWhenActive = drivers.pullDownWhenActive();
        message.pullDownWhenInactive = drivers.pullDownWhenInactive();
        message.overCurrent = drivers.overCurrent();
        message.openLoad = drivers.openLoad();
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_OneWireGpioModule_Block_fields,
                     blox_OneWireGpioModule_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError ExpOwGpioBlock::read(const cbox::PayloadCallback& callback) const
{
    return handleRead(callback, true);
}

cbox::CboxError ExpOwGpioBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return handleRead(callback, false);
}

cbox::CboxError ExpOwGpioBlock::write(const cbox::Payload& payload)
{
    blox_OneWireGpioModule_Block message = blox_OneWireGpioModule_Block_init_zero;
    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_OneWireGpioModule_Block_fields)) {
        if (parser.hasField(blox_OneWireGpioModule_Block_modulePosition_tag)) {
            drivers.modulePosition(message.modulePosition);
        }
        if (parser.hasField(blox_OneWireGpioModule_Block_clearFaults_tag)) {
            if (message.clearFaults) {
                drivers.clearFaults();
            }
        }
        if (parser.hasField(blox_OneWireGpioModule_Block_useExternalPower_tag)) {
            drivers.externalPowerEnabled(message.useExternalPower);
        }
        if (parser.hasField(blox_OneWireGpioModule_Block_channels_tag)) {
            // first dedode to new array, so deleted channels are overwritten with an unused channel
            std::array<ExpOwGpio::FlexChannel, 8> newChannels{};
            channelNames.clear();

            // copy variable length array from proto to positions
            for (uint8_t c = 0; c < message.channels_count && c < 8; c++) {
                if (message.channels[c].id > 0 && message.channels[c].id <= 8) {
                    uint8_t idx = message.channels[c].id - 1;
                    newChannels[idx] = ExpOwGpio::FlexChannel(
                        message.channels[c].deviceType,
                        message.channels[c].width,
                        message.channels[c].pinsMask);
                }
                channelNames.push_back({message.channels[c].id, std::string(message.channels[c].name)});
            }

            // copy to drivers, resulting zeroing omitted channels
            for (uint8_t i = 0; i < 8; i++) {
                drivers.setupFlexChannel(i + 1, newChannels[i]);
            }
        }
    }

    return parser.status();
}

cbox::update_t
ExpOwGpioBlock::updateHandler(cbox::update_t now)
{
    // Update is called any time a channel is set,
    // but only talks to the driver when the cached value doesn't match the desired value
    // Every second, force a fresh read from the driver
    drivers.update(true);
    return next_update_1s(now);
}

void* ExpOwGpioBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }

    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        ExpOwGpio* drvPtr = &drivers;
        IoArray* ptr = drvPtr; // get base class ptr
        return ptr;
    }
    if (iface == cbox::interfaceId<OneWire>()) {
        // return the member that implements the interface in this case
        return drivers.oneWireBus();
    }

    if (iface == cbox::interfaceId<IoModule>()) {
        // return the member that implements the interface in this case
        ExpOwGpio* drvPtr = &drivers;
        IoModule* ptr = drvPtr; // get base class ptr
        return ptr;
    }

    return nullptr;
}
