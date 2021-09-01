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

#include "./ExpOwGpioBlock.hpp"

cbox::CboxError
ExpOwGpioBlock::streamFrom(cbox::DataIn& in)
{
    blox_OneWireGpioModule newData = blox_OneWireGpioModule_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_OneWireGpioModule_fields, blox_OneWireGpioModule_size);

    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
        drivers.modulePosition(newData.modulePosition);
        drivers.externalPowerEnabled(newData.useExternalPower);

        // first dedode to new array, so deleted channels are overwritten with an unused channel
        std::array<ExpOwGpio::FlexChannel, 8> newChannels{};
        channelNames.clear();

        // copy variable length array from proto to positions
        for (uint8_t c = 0; c < newData.channels_count && c < 8; c++) {
            if (newData.channels[c].id > 0 && newData.channels[c].id <= 8) {
                uint8_t idx = newData.channels[c].id - 1;
                newChannels[idx] = ExpOwGpio::FlexChannel(
                    newData.channels[c].deviceType,
                    newData.channels[c].width,
                    newData.channels[c].pinsMask);
            }
            channelNames.push_back({newData.channels[c].id, std::string(newData.channels[c].name)});
        }

        // copy to drivers, resulting zeroing omitted channels
        for (uint8_t i = 0; i < 8; i++) {
            drivers.setupChannel(i + 1, newChannels[i]);
        }
    }

    return res;
}

void ExpOwGpioBlock::writeMessage(blox_OneWireGpioModule& message, bool includeNotPersisted) const
{
    message.modulePosition = drivers.modulePosition();
    message.channels_count = 0;
    message.useExternalPower = drivers.externalPowerEnabled();

    for (uint8_t i = 1; i <= 8; i++) {
        auto& c = drivers.getChannel(i);
        if (c.deviceType != blox_GpioDeviceType_GPIO_DEV_NONE) {
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

cbox::CboxError
ExpOwGpioBlock::streamTo(cbox::DataOut& out) const
{
    blox_OneWireGpioModule message = blox_OneWireGpioModule_init_zero;
    writeMessage(message, true);

    return streamProtoTo(out, &message, blox_OneWireGpioModule_fields, blox_OneWireGpioModule_size);
}

cbox::CboxError
ExpOwGpioBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_OneWireGpioModule message = blox_OneWireGpioModule_init_zero;
    writeMessage(message, false);

    return streamProtoTo(out, &message, blox_OneWireGpioModule_fields, blox_OneWireGpioModule_size);
}

cbox::update_t
ExpOwGpioBlock::update(const cbox::update_t& now)
{
    // Update is called any time a channel is set,
    // but only talks to the driver when the cached value doesn't match the desired value
    // Every second, force a fresh read from the driver
    drivers.update(true);
    return update_1s(now);
}

void* ExpOwGpioBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_OneWireGpioModule) {
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
        return &drivers.oneWireBus();
    }

    if (iface == cbox::interfaceId<IoModule>()) {
        // return the member that implements the interface in this case
        ExpOwGpio* drvPtr = &drivers;
        IoModule* ptr = drvPtr; // get base class ptr
        return ptr;
    }

    return nullptr;
}