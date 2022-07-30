/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewPi.
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

#include "spark/SparkIoBase.hpp"
#include "control/ActuatorDigital.hpp"
#include "spark/Board.hpp"

namespace platform::particle {

// generic ArrayIO interface
IoValue::variant SparkIoBase::readChannelImpl(uint8_t channel) const
{
    auto pin = channelToPin(channel);
    if (pin == static_cast<decltype(pin)>(-1)) {
        return IoValue::Error::INVALID_CHANNEL;
    }
    return pinReadFast(pin) != 0 ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
}

// prevent inlining of hal function to save code size
void pinMode(pin_t pin, PinMode setMode)
{
    HAL_Pin_Mode(pin, setMode);
}

IoValue::variant SparkIoBase::writeChannelImpl(uint8_t channel, IoValue::variant val)
{
    auto pin = channelToPin(channel);
    if (pin == static_cast<decltype(pin)>(-1)) {
        return IoValue::Error::INVALID_CHANNEL;
    }

    if (auto* v = std::get_if<IoValue::Digital>(&val)) {
        auto state = v->state();
        if (state == IoValue::State::Active) {
            pinSetFast(pin);
            return IoValue::Digital{state};
        } else if (state == IoValue::State::Inactive) {
            pinResetFast(pin);
            return IoValue::Digital{state};
        }
        return IoValue::Error::UNSUPPORTED_VALUE;
    }
    return IoValue::Error::UNSUPPORTED_VALUE;
}

IoValue::Setup::variant SparkIoBase::setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup)
{
    auto pin = channelToPin(channel);
    if (pin == static_cast<decltype(pin)>(-1)) {
        return IoValue::Error::INVALID_CHANNEL;
    }
    if (std::holds_alternative<IoValue::Setup::OutputDigital>(setup)) {
#if defined(PIN_V3_TOP1_DIR)
        if (pin == PIN_V3_TOP1) {
            // will also set pin mode, smaller code size than HAL_Pin_Mode and pinSetFast due to inlining
            HAL_GPIO_Write(PIN_V3_TOP1_DIR, LOW);
        }
#endif
#if defined(PIN_V3_TOP2_DIR)
        if (pin == PIN_V3_TOP2) {
            HAL_GPIO_Write(PIN_V3_TOP2_DIR, LOW);
        }
#endif
        HAL_GPIO_Write(pin, LOW);
        return setup;
    }
    if (std::holds_alternative<IoValue::Setup::InputDigital>(setup)) {
        // support inputs on top 1 and top 2 of spark 3
#if defined(PIN_V3_TOP1_DIR)
        if (pin == PIN_V3_TOP1) {
            pinMode(pin, INPUT_PULLDOWN);
            return setup;
        }
#endif
#if defined(PIN_V3_TOP2_DIR)
        if (pin == PIN_V3_TOP2) {
            pinMode(pin, INPUT_PULLDOWN);
            return setup;
        }
#endif
        return IoValue::Error::UNSUPPORTED_SETUP;
    }
    if (std::holds_alternative<IoValue::Setup::Unused>(setup)) {
        pinMode(pin, INPUT_PULLDOWN);
        return setup;
    }
    return IoValue::Error::UNSUPPORTED_SETUP;
}
} // end namespace platform::particle
