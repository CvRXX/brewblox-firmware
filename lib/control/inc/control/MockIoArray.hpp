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

#include "control/IoArray.hpp"

class MockIoArray : public IoArray {
public:
    uint8_t pinStates = 0;  // 1 = high, 0 is low
    uint8_t pinModes = 0;   // 1 = ouput, 0 is input
    uint8_t errorState = 0; // error for specific channel
    bool isConnected = true;

    MockIoArray()
        : IoArray(8)
    {
    }
    MockIoArray(const MockIoArray&) = delete;
    MockIoArray& operator=(const MockIoArray&) = delete;

    virtual ~MockIoArray() = default;

    virtual ChannelValue readChannelImpl(uint8_t channel) const override final
    {
        // valid channel check already performed in base class
        if (isConnected && ((getMask(channel) & errorState) == 0)) {
            switch (getChannelType(channel)) {
            case ChannelType::OUTPUT_DIGITAL:
            case ChannelType::INPUT_DIGITAL:
                return pinStates & getMask(channel);
            case ChannelType::OUTPUT_PWM:
                // Return result of last write
                return channels[channel - 1].actual;
            case ChannelType::OUTPUT_DIGITAL_BIDIRECTIONAL:
            case ChannelType::OUTPUT_PWM_BIDIRECTIONAL:
            case ChannelType::UNKNOWN:
            case ChannelType::UNUSED:
                return ChannelValue{}; // not supported
            }
        }
        return ChannelValue{};
    }

    virtual ChannelValue writeChannelImpl(uint8_t channel, ChannelValue val) override final
    {
        // valid channel check already performed in base class
        if (isConnected && val.has_value()) {
            uint8_t mask = getMask(channel);
            switch (getChannelType(channel)) {
            case ChannelType::OUTPUT_DIGITAL:
                if (*val > 0) {
                    pinStates |= mask;
                    return 1;
                }
                pinStates &= ~mask;
                return 0;
            case ChannelType::OUTPUT_PWM:
                // just return val to indicate that pwm was successfully set
                return val;
            case ChannelType::INPUT_DIGITAL:
            case ChannelType::OUTPUT_DIGITAL_BIDIRECTIONAL:
            case ChannelType::OUTPUT_PWM_BIDIRECTIONAL:
            case ChannelType::UNKNOWN:
            case ChannelType::UNUSED:
                return ChannelValue{}; // write not supported
            }
        }
        return ChannelValue{};
    }

    virtual bool setChannelTypeImpl(uint8_t channel, ChannelType chanType) override final
    {
        switch (chanType) {
        case ChannelType::OUTPUT_DIGITAL:
        case ChannelType::OUTPUT_PWM:
            pinModes |= getMask(channel);
            return true;
        case ChannelType::INPUT_DIGITAL:
            pinModes &= getMask(channel);
            return true;
        case ChannelType::OUTPUT_DIGITAL_BIDIRECTIONAL:
        case ChannelType::OUTPUT_PWM_BIDIRECTIONAL:
        case ChannelType::UNKNOWN:
        case ChannelType::UNUSED:
            return false;
        }
        return false;
    }

    void connected(bool v)
    {
        isConnected = v;
    }

    void setChannelError(uint8_t chan, bool isError)
    {
        uint8_t mask = getMask(chan);
        if (isError) {
            errorState |= mask;
        } else {
            errorState &= mask;
        }
    }

private:
    uint8_t static getMask(uint8_t channel)
    {
        return 0x1 << (channel - 1);
    }
};
