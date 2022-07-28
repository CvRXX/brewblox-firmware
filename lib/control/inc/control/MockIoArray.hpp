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
#include <array>

class MockIoArray : public IoArray {
public:
    uint8_t pinStates = 0;  // 1 = high, 0 is low
    uint8_t errorState = 0; // error for specific channel
    bool isConnected = true;
    std::array<IoValue::PWM::duty_t, 8> pwmSettings = {0};

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
            return IoValue::Digital(pinStates & mask ? State::Active : State::Inactive);
        } else if (std::holds_alternative<IoValue::PWM>(setting)) {
            return IoValue::PWM{pwmSettings[channel - 1]};
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

        if (const auto* v = std::get_if<IoValue::Digital>(&val)) {
            if (v->state() == IoValue::State::Active) {
                pinStates |= mask;
                return *v;
            } else if (v->state() == IoValue::State::Inactive) {
                pinStates &= ~mask;
                return *v;
            } else {
                return IoValue::Error::UNSUPPORTED_VALUE;
            }
        } else if (const auto* v = std::get_if<IoValue::PWM>(&val)) {
            pwmSettings[channel - 1] = v->duty();
            return val;
        }
        return IoValue::Error::UNSUPPORTED_VALUE;
    }

    IoValue::Setup::variant setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup) override final
    {
        uint8_t mask = getMask(channel);
        if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)) {
            pinStates &= ~mask;
            return setup;
        }
        if (std::holds_alternative<IoValue::Setup::OutputPwm>(setup)) {
            pinStates &= ~mask;
            return setup;
        } else {
            return IoValue::Error::UNSUPPORTED_SETUP;
        }
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
