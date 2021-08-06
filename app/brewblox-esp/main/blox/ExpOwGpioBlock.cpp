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
        drivers.clearChannels();
        for (uint8_t c = 0; c < newData.channels_count; c++) {
            ExpOwGpio::ChanBits pins;
            ExpOwGpio::ChanBits when_active;
            ExpOwGpio::ChanBits when_inactive;
            pins.all = newData.channels[c].pins;
            when_active.all = newData.channels[c].whenActive;
            when_inactive.all = newData.channels[c].whenInactive;

            drivers.addChannel(ExpOwGpio::FlexChannel(
                newData.channels[c].id,
                IoArray::ChannelConfig(newData.channels[c].config),
                pins,
                when_active,
                when_inactive));
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
        message.channels[message.channels_count].config = blox_ChannelConfig(chan_it->config);
        message.channels[message.channels_count].pins = chan_it->pins().all;
        message.channels[message.channels_count].whenActive = chan_it->when_active().all;
        message.channels[message.channels_count].whenInactive = chan_it->when_inactive().all;
        message.channels[message.channels_count].pwmDuty = chan_it->pwm_duty;
        ++message.channels_count;
    }

    if (includeNotPersisted) {
        message.status = drivers.status();
        message.drive = drivers.drive().all;
        message.overCurrent = drivers.overcurrent().all;
        message.openLoad = drivers.openload().all;
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
