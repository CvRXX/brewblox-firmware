/*
 * Copyright 2018 BrewPi B.V.
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

#pragma once

#include "blocks/Block.h"
#include "cbox/DataStream.h"
#include "control/Ticks.h"
#include "proto/Ticks.pb.h"

// provides a protobuf interface to the ticks object
template <typename T>
class TicksBlock : public Block<brewblox_BlockType_Ticks> {
    T& ticks;

public:
    TicksBlock(T& _ticks)
        : ticks(_ticks)
    {
    }
    virtual ~TicksBlock() = default;

    virtual cbox::CboxError toResponse(cbox::Command& cmd) const override final
    {
        blox_Ticks_Block message = blox_Ticks_Block_init_zero;

        message.secondsSinceEpoch = ticks.utc();
        message.millisSinceBoot = ticks.millis();

        message.avgCommunicationTask = ticks.taskTime(0);
        message.avgBlocksUpdateTask = ticks.taskTime(1);
        message.avgDisplayTask = ticks.taskTime(2);
        message.avgSystemTask = ticks.taskTime(3);

        return serializeResponsePayload(cmd,
                                        objectId,
                                        staticTypeId(),
                                        0,
                                        &message,
                                        blox_Ticks_Block_fields,
                                        blox_Ticks_Block_size);
    }

    virtual cbox::CboxError toStoredResponse(cbox::Command&) const override final
    {
        return cbox::CboxError::PERSISTING_NOT_NEEDED;
    }

    virtual cbox::CboxError fromRequest(cbox::Command& cmd) override final
    {
        blox_Ticks_Block message = blox_Ticks_Block_init_zero;
        auto res = parseRequestPayload(cmd, &message, blox_Ticks_Block_fields);

        if (res == cbox::CboxError::OK) {
            ticks.setUtc(message.secondsSinceEpoch);
        }

        return res;
    }

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return cbox::Object::update_never(now);
    }

    T& get()
    {
        return ticks;
    }

    const T& const_get() const
    {
        return ticks;
    }
};
