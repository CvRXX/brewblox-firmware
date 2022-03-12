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

#include "blocks/MockPinsBlock.h"
#include "proto/MockPins.pb.h"

cbox::CboxError
MockPinsBlock::toResponse(cbox::Command& cmd) const
{
    blox_MockPins_Block message = blox_MockPins_Block_init_zero;

    // looks a bit silly, but this way it is implemented the same as the Spark2 and Spark3 blocks
    message.channels_count = 8;
    message.channels[0].id = 1;
    message.channels[1].id = 2;
    message.channels[2].id = 3;
    message.channels[3].id = 4;
    message.channels[4].id = 5;
    message.channels[5].id = 6;
    message.channels[6].id = 7;
    message.channels[7].id = 8;

    return serializeResponsePayload(cmd,
                                    objectId,
                                    staticTypeId(),
                                    0,
                                    &message,
                                    blox_MockPins_Block_fields,
                                    blox_MockPins_Block_size);
}

cbox::CboxError
MockPinsBlock::toStoredResponse(cbox::Command& cmd) const
{
    // We have no persisted data
    return serializeResponsePayload(cmd, objectId, staticTypeId(), 0);
}

cbox::CboxError
MockPinsBlock::fromRequest(cbox::Command&)
{
    return cbox::CboxError::OK;
}

void* MockPinsBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_MockPins) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<IoArray>()) {
        // return the member that implements the interface in this case
        return &mocks;
    }
    return nullptr;
}
