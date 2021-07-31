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

#include "./ExpansionGpioBlock.h"
#include "blox/IoArrayHelpers.h"

cbox::CboxError
ExpansionGpioBlock::streamFrom(cbox::DataIn& in)
{
    blox_ExpansionGpio newData = blox_ExpansionGpio_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_ExpansionGpio_fields, blox_ExpansionGpio_size);
    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
    }
    return res;
}

cbox::CboxError
ExpansionGpioBlock::streamTo(cbox::DataOut& out) const
{
    blox_ExpansionGpio message = blox_ExpansionGpio_init_zero;

    message.address = gpio.address();
    message.channels_count = 0;
    for (auto chan_it = gpio.cbegin(); chan_it < gpio.cend(); chan_it++) {
        message.channels[message.channels_count].id = chan_it->id;
        message.channels[message.channels_count].type = blox_GpioChannel_Type(chan_it->type);
        message.channels[message.channels_count].pins = chan_it->pins().all;
        message.channels[message.channels_count].when_active = chan_it->when_active().all;
        message.channels[message.channels_count].when_inactive = chan_it->when_inactive().all;
        message.channels[message.channels_count].pwm_duty = chan_it->pwm_duty;
        ++message.channels_count;
    }

    message.status = gpio.status();
    message.drive = gpio.drive().all;
    message.overcurrent = gpio.overcurrent().all;
    message.openload = gpio.openload().all;

    return streamProtoTo(out, &message, blox_ExpansionGpio_fields, blox_ExpansionGpio_size);
}

cbox::CboxError
ExpansionGpioBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_ExpansionGpio message = blox_ExpansionGpio_init_zero;

    return streamProtoTo(out, &message, blox_ExpansionGpio_fields, blox_ExpansionGpio_size);
}

cbox::update_t
ExpansionGpioBlock::update(const cbox::update_t& now)
{
    // device.update();
    return update_1s(now);
}

void* ExpansionGpioBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == BrewBloxTypes_BlockType_ExpansionGpio) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        IoArray* ptr = &gpio;
        return ptr;
    }
    if (iface == cbox::interfaceId<ExpansionGpio>()) {
        // return the member that implements the interface in this case
        return &gpio;
    }
    return nullptr;
}
