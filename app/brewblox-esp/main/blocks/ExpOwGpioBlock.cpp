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

void ExpOwGpioBlock::writeMessage(blox_OneWireGpioModule_Block& message, bool includeNotPersisted) const
{
    message.modulePosition = drivers.modulePosition();
    message.channels_count = 0;
    message.useExternalPower = drivers.externalPowerEnabled();

    for (uint8_t i = 1; i <= 8; i++) {
        auto& c = drivers.getChannel(i);
        if (c.deviceType != blox_OneWireGpioModule_GpioDeviceType_GPIO_DEV_NONE) {
            message.channels[message.channels_count].id = i;
            message.channels[message.channels_count].deviceType = c.deviceType;
            message.channels[message.channels_count].width = c.width;
            message.channels[message.channels_count].pinsMask = c.pins();
            for (auto& entry : channelNames) {
                if (entry.id == i) {
                    entry.name.copy(message.channels[message.channels_count].name, sizeof(message.channels[message.channels_count].name));
                    break;
                }
            }
            ++message.channels_count;
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
}

cbox::CboxError ExpOwGpioBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_OneWireGpioModule_Block message = blox_OneWireGpioModule_Block_init_zero;
    writeMessage(message, true);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_OneWireGpioModule_Block_fields,
                           blox_OneWireGpioModule_Block_size);
}

cbox::CboxError ExpOwGpioBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_OneWireGpioModule_Block message = blox_OneWireGpioModule_Block_init_zero;
    writeMessage(message, false);

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_OneWireGpioModule_Block_fields,
                           blox_OneWireGpioModule_Block_size);
}

cbox::CboxError ExpOwGpioBlock::write(const cbox::Payload& payload)
{
    blox_OneWireGpioModule_Block message = blox_OneWireGpioModule_Block_init_zero;
    auto res = payloadToMessage(payload, &message, blox_OneWireGpioModule_Block_fields);

    if (res == cbox::CboxError::OK) {
        drivers.modulePosition(message.modulePosition);
        drivers.externalPowerEnabled(message.useExternalPower);

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
            drivers.setupChannel(i + 1, newChannels[i]);
        }
    }

    return res;
}

cbox::update_t
ExpOwGpioBlock::updateHandler(const cbox::update_t& now)
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
