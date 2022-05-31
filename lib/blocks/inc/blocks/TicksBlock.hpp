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

#include "blocks/Block.hpp"
#include "cbox/Cache.hpp"
#include "control/Ticks.hpp"
#include "proto/Ticks.pb.h"

struct __attribute__((packed)) TicksCacheLayout {
    uint32_t secondsSinceEpoch{0};
};

// provides a protobuf interface to the ticks object
template <typename T>
class TicksBlock final : public Block<brewblox_BlockType_Ticks> {
    T& ticks;

private:
    static constexpr utc_seconds_t minValidUtc = 1'000'000'000; // mid-2001
    static constexpr cbox::update_t updateInterval = 5000;
    static constexpr uint8_t estimatedRebootTimeS = 5;

public:
    explicit TicksBlock(T& _ticks)
        : ticks(_ticks)
    {
    }
    ~TicksBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        blox_Ticks_Block message = blox_Ticks_Block_init_zero;

        message.secondsSinceEpoch = ticks.utc();
        message.millisSinceBoot = ticks.millis();

        message.avgCommunicationTask = ticks.taskTime(0);
        message.avgBlocksUpdateTask = ticks.taskTime(1);
        message.avgDisplayTask = ticks.taskTime(2);
        message.avgSystemTask = ticks.taskTime(3);

        return callWithMessage(callback,
                               objectId(),
                               staticTypeId(),
                               0,
                               &message,
                               blox_Ticks_Block_fields,
                               blox_Ticks_Block_size);
    }

    cbox::CboxError readStored(const cbox::PayloadCallback&) const override
    {
        return cbox::CboxError::OK;
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        blox_Ticks_Block message = blox_Ticks_Block_init_zero;
        auto res = payloadToMessage(payload, &message, blox_Ticks_Block_fields);

        if (res == cbox::CboxError::OK) {
            // Only accept UTC time from block write if we don't already have a value
            if (ticks.utc() < minValidUtc && message.secondsSinceEpoch > minValidUtc) {
                ticks.setUtc(message.secondsSinceEpoch);
            }
        }

        return res;
    }

    cbox::CboxError
    loadFromCache() override
    {
        if (auto loaded = cbox::loadFromCache<TicksCacheLayout>(objectId(), staticTypeId())) {
            ticks.setUtc(loaded.value().secondsSinceEpoch + estimatedRebootTimeS);
        }
        return cbox::CboxError::OK;
    }

    cbox::update_t
    updateHandler(const cbox::update_t& now) override
    {
        TicksCacheLayout cached = {
            .secondsSinceEpoch = ticks.utc() + (ticks.millis() / 1000)};
        cbox::saveToCache(objectId(), staticTypeId(), cached);

        return now + updateInterval;
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
