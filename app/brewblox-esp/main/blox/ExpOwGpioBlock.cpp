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
#include "blox/IoArrayHelpers.h"

cbox::CboxError
ExpOwGpioBlock::streamFrom(cbox::DataIn& in)
{
    blox_OneWireGpioModule newData = blox_OneWireGpioModule_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_OneWireGpioModule_fields, blox_OneWireGpioModule_size);

    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
        drivers.modulePosition(newData.modulePosition);

        // first dedode to new array, so deleted channels are overwritten with an unused channel
        std::array<ExpOwGpio::FlexChannel, 8> newChannels;

        for (uint8_t c = 0; c < newData.channels_count; c++) {
            if (newData.channels[c].id > 0 && newData.channels[c].id <= 8) {
                uint8_t idx = newData.channels[c].id - 1;
                newChannels[idx] = ExpOwGpio::FlexChannel(
                    newData.channels[c].deviceType,
                    newData.channels[c].pinsMask);
            }
        }
        for (uint8_t i = 0; i < 8; i++) {
            drivers.setupChannel()
        }

    }

    return res;
}

void ExpOwGpioBlock::writeMessage(blox_OneWireGpioModule& message, bool includeNotPersisted) const
{
    message.modulePosition = drivers.modulePosition();
    message.channels_count = 0;
    for (auto chan_it = drivers.cbegin(); chan_it < drivers.cend(); chan_it++) {
        message.channels[message.channels_count].id = chan_it->id;
        message.channels[message.channels_count].deviceType = chan_it->deviceType;
        message.channels[message.channels_count].pinsMask = chan_it->pins();

        if (includeNotPersisted) {
            message.channels[message.channels_count].config = blox_ChannelConfig(chan_it->config);
            message.channels[message.channels_count].status = drivers.channelStatus(chan_it->id);
            message.channels[message.channels_count].pwmDuty = chan_it->pwm_duty;
            message.channels[message.channels_count].state = drivers.channelState(chan_it->id);
        }
        ++message.channels_count;
    }

    if (includeNotPersisted) {
        message.moduleStatus = drivers.status().all;
        message.pullUp = drivers.pullUp();
        message.pullUpWhenActive = drivers.pullUpWhenActive();
        message.pullUpWhenInactive = drivers.pullUpWhenInactive();
        message.pullDown = drivers.pullDown();
        message.pullDownWhenActive = drivers.pullDownWhenActive();
        message.pullDownWhenInactive = drivers.pullDownWhenInactive();
        message.pullUpOverCurrent = drivers.pullUpOverCurrent();
        message.pullDownOverCurrent = drivers.pullDownOverCurrent();
        message.pullUpOpenLoad = drivers.pullUpOpenLoad();
        message.pullDownOpenLoad = drivers.pullDownOpenLoad();
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
    drivers.update();
    return update_1s(now);
}

void* ExpOwGpioBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_OneWireGpioModule) {
        return this; // me!
    }

    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = &drivers;
        return ptr;
    }
    if (iface == cbox::interfaceId<OneWire>()) {
        // return the member that implements the interface in this case
        return &drivers.oneWireBus();
    }

    if (iface == cbox::interfaceId<IoModule>()) {
        // return the member that implements the interface in this case
        IoModule* ptr = &drivers;
        return ptr;
    }

    return nullptr;
}
