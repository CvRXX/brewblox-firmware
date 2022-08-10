/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#include "blocks/MockPinsBlock.hpp"
#include "cbox/PayloadConversion.hpp"
#include "proto/MockPins.pb.h"

cbox::CboxError
MockPinsBlock::read(const cbox::PayloadCallback& callback) const
{
    blox_MockPins_Block message = blox_MockPins_Block_init_zero;

    // looks a bit silly, but this way it is implemented the same as the Spark2 and Spark3 blocks
    message.channels_count = 8;
    for (uint8_t i = 0; i < 8; ++i) {
        message.channels[i].id = i + 1;
        message.channels[i].capabilities = mocks.getChannelCapabilities(i + 1).all;
        message.channels[i].claimedBy = mocks.claimedBy(i + 1);
    }

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_MockPins_Block_fields,
                     blox_MockPins_Block_size)
        .respond(callback)
        .status();
}

cbox::CboxError
MockPinsBlock::readStored(const cbox::PayloadCallback& callback) const
{
    // We have no persisted data
    return cbox::PayloadBuilder(*this)
        .respond(callback)
        .status();
}

cbox::CboxError
MockPinsBlock::write(const cbox::Payload&)
{
    return cbox::CboxError::OK;
}

void* MockPinsBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        return &mocks;
    }
    return nullptr;
}
