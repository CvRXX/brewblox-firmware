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
    blox_ExpOwGpio newData = blox_ExpOwGpio_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_ExpOwGpio_fields, blox_ExpOwGpio_size);
    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
    }
    return res;
}

cbox::CboxError
ExpOwGpioBlock::streamTo(cbox::DataOut& out) const
{
    blox_ExpOwGpio message = blox_ExpOwGpio_init_zero;

    message.address = drivers.address();
    message.channels_count = 0;
    for (auto chan_it = drivers.cbegin(); chan_it < drivers.cend(); chan_it++) {
        message.channels[message.channels_count].id = chan_it->id;
        message.channels[message.channels_count].type = blox_GpioChannel_Type(chan_it->type);
        message.channels[message.channels_count].pins = chan_it->pins().all;
        message.channels[message.channels_count].when_active = chan_it->when_active().all;
        message.channels[message.channels_count].when_inactive = chan_it->when_inactive().all;
        message.channels[message.channels_count].pwm_duty = chan_it->pwm_duty;
        ++message.channels_count;
    }

    message.status = drivers.status();
    message.drive = drivers.drive().all;
    message.overcurrent = drivers.overcurrent().all;
    message.openload = drivers.openload().all;

    return streamProtoTo(out, &message, blox_ExpOwGpio_fields, blox_ExpOwGpio_size);
}

cbox::CboxError
ExpOwGpioBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_ExpOwGpio message = blox_ExpOwGpio_init_zero;

    return streamProtoTo(out, &message, blox_ExpOwGpio_fields, blox_ExpOwGpio_size);
}

cbox::update_t
ExpOwGpioBlock::update(const cbox::update_t& now)
{
    // device.update();
    return update_1s(now);
}

void* ExpOwGpioBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_ExpOwGpio) {
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
    return nullptr;
}
