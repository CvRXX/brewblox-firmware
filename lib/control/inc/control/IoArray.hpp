/*
 * Copyright 2019 BrewPi/Elco Jacobs.
 *
 * This file is part of BrewBlox.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "control/ActuatorDigitalBase.hpp"
#include <inttypes.h>
#include <optional>
#include <vector>

/*
 * Abstract interface to an array of digital inputs and/or outputs
 */
class IoArray {
public:
    using State = ActuatorDigitalBase::State;
    IoArray(uint8_t size)
        : channels(size, {ChannelType::UNUSED, 0, 0})
    {
    }

    IoArray(const IoArray&) = delete;
    IoArray& operator=(const IoArray&) = delete;

    virtual ~IoArray() = default;

    enum class ChannelType {
        UNUSED = 0,
        OUTPUT_DIGITAL = 1,
        OUTPUT_PWM = 2,
        OUTPUT_DIGITAL_BIDIRECTIONAL = 3,
        OUTPUT_PWM_BIDIRECTIONAL = 4,
        INPUT_DIGITAL = 10,
        UNKNOWN = 255,
    };

    using ChannelValue = std::optional<int16_t>;

    bool validChannel(uint8_t channel) const
    {
        // first channel is 1, because 0 is used as 'unconfigured'
        return channel > 0 && channel <= size();
    }

    ChannelType getChannelType(uint8_t channel) const
    {
        if (validChannel(channel)) {
            return channels[channel - 1].type;
        }
        return ChannelType::UNKNOWN;
    }

    bool setChannelType(uint8_t channel, ChannelType chanType, ChannelType currentTypeCheck)
    {
        bool success = false;
        if (currentTypeCheck == ChannelType::UNKNOWN || getChannelType(channel) == currentTypeCheck) {
            success = setChannelTypeImpl(channel, chanType);
            if (success) {
                channels[channel - 1].type = chanType;
            }
        }
        return success;
    }

    ChannelValue readChannel(uint8_t channel) const
    {
        if (validChannel(channel)) {
            return readChannelImpl(channel);
        }
        return ChannelValue{};
    }

    // returns actual value after write, or nullopt if write failed
    ChannelValue writeChannel(uint8_t channel, ChannelValue val)
    {
        if (validChannel(channel)) {
            channels[channel - 1].desired = val;
            channels[channel - 1].actual = writeChannelImpl(channel, val);
        }
        return ChannelValue{};
    }

    // const auto& readChannels() const
    // {
    //     return channels;
    // }

    uint8_t size() const
    {
        return channels.size();
    }

protected:
    virtual ChannelValue readChannelImpl(uint8_t channel) const = 0;
    virtual ChannelValue writeChannelImpl(uint8_t channel, ChannelValue value) = 0;
    virtual bool setChannelTypeImpl(uint8_t channel, ChannelType type) = 0;

    struct Channel {
        ChannelType type = ChannelType::UNUSED;
        ChannelValue desired = ChannelValue{};
        ChannelValue actual = ChannelValue{};
    };

    mutable std::vector<Channel> channels;
};
