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

    virtual IoValue::variant readChannelImpl(uint8_t channel) const override final
    {
        // valid channel check already performed in base class
        if (!isConnected) {
            return IoValue::Error::DISCONNECTED;
        }
        auto mask = getMask(channel);

        if ((mask & errorState) != 0) {
            return IoValue::Error::IO_ERROR;
        }

        const auto setting = desired(channel);
        if (std::holds_alternative<IoValue::Digital>(setting)) {
            return IoValue::Digital(pinStates & mask);
        } else if (std::holds_alternative<IoValue::PWM>(setting)) {
            // just return desired value
            return setting;
        }
        return IoValue::Error::UNSUPPORTED_VALUE;
    }

    virtual IoValue::variant
    writeChannelImpl(uint8_t channel, IoValue::variant val) override final
    {
        // valid channel check already performed in base class
        if (!isConnected) {
            return IoValue::Error::DISCONNECTED;
        }
        uint8_t mask = getMask(channel);

        if (auto* v = std::get_if<IoValue::Digital>(&val)) {
            if (v->state() == IoValue::State::Active) {
                pinStates |= mask;
                return *v;
            } else if (v->state() == IoValue::State::Inactive) {
                pinStates &= ~mask;
                return *v;
            } else {
                return IoValue::Error::UNSUPPORTED_VALUE;
            }
        } else if (std::holds_alternative<IoValue::PWM>(val)) {
            // just return val to indicate that pwm was successfully set
            return val;
        } else if (auto* v = std::get_if<IoValue::Setup>(&val)) {
            if (v->type == IoValue::Setup::Type::OUTPUT_DIGITAL) {
                pinStates &= ~mask;
                return IoValue::Digital(State::Inactive);
            }
            if (v->type == IoValue::Setup::Type::OUTPUT_DIGITAL) {
                pinStates &= ~mask;
                return IoValue::PWM{0};
            } else {
                return IoValue::Error::UNSUPPORTED_SETUP;
            }
        }
        return IoValue::Error::UNSUPPORTED_VALUE;
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
