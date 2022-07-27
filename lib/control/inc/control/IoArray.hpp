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

#include "control/ActuatorAnalog.hpp"
#include "control/ActuatorDigitalBase.hpp"
#include <cinttypes>
#include <optional>
#include <variant>
#include <vector>

namespace IoValue {
using State = ActuatorDigitalBase::State;
enum class Error : uint8_t {
    UNKNOWN,
    NOT_CONFIGURED,
    INVALID_CHANNEL,
    UNSUPPORTED_VALUE,
    UNSUPPORTED_SETUP,
    CHANNEL_IN_USE,
    IO_ERROR,
    DISCONNECTED,
    CHANNEL_TYPE_NOT_SET,
    CHANNEL_PINS_NOT_SET,
    NOT_IMPLEMENTED,
};

namespace Setup {
    enum class Frequency : uint8_t {
        FREQ_NONE,
        FREQ_100HZ,
        FREQ_200HZ,
        FREQ_2000HZ,
    };

    enum SoftTransitions : uint8_t {
        NOT_SUPPORTED,
        OFF,
        ON_250MS,
    };

    struct Unused {
    };
    struct OutputDigital {
    };
    struct OutputPwm {
        Frequency frequency = Frequency::FREQ_NONE;
    };
    struct InputDigital {};

    using variant = std::variant<Unused,
                                 Error,
                                 OutputDigital,
                                 OutputPwm,
                                 InputDigital>;
}; // end snamespace IoValue::Setup

class Digital {
private:
    State _state;

public:
    explicit Digital(State s)
        : _state(s)
    {
    }

    [[nodiscard]] State state() const
    {
        return _state;
    }
};

class PWM {
public:
    using duty_t = ActuatorAnalog::value_t;

private:
    duty_t _duty = 0;

public:
    explicit PWM(duty_t d)
        : _duty{d}
    {
    }

    [[nodiscard]] State state() const
    {
        if (_duty > 0) {
            return State::Active;
        }
        if (_duty < 0) {
            return State::Reverse;
        }
        return State::Inactive;
    }

    [[nodiscard]] duty_t duty() const
    {
        return _duty;
    }
};

using variant = std::variant<Error,
                             Digital,
                             PWM>;

inline bool operator==(const variant& v, const Digital& t)
{
    if (auto* val = std::get_if<Digital>(&v)) {
        return val->state() == t.state();
    };
    return false;
}
};

/*
 * Abstract interface to an array of digital inputs and/or outputs
 */
class IoArray {
public:
    using State = ActuatorDigitalBase::State;
    explicit IoArray(uint8_t size)
        : channels{size}
    {
    }

    IoArray(const IoArray&) = delete;
    IoArray& operator=(const IoArray&) = delete;
    IoArray(IoArray&&) = default;
    IoArray& operator=(IoArray&&) = default;

    virtual ~IoArray() = default;

    [[nodiscard]] bool validChannel(uint8_t channel) const
    {
        // first channel is 1, because 0 is used as 'unconfigured'
        return channel > 0 && channel <= size();
    }

    // returns written value or error
    IoValue::Setup::variant setupChannel(uint8_t channel, IoValue::Setup::variant setup)
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        auto& chan = channels[channel - 1];
        // allow setup if the new value is a release of if the channel is not in use
        if (std::holds_alternative<IoValue::Setup::Unused>(setup)
            || std::holds_alternative<IoValue::Setup::Unused>(chan.setupDesired)) {
            chan.setupDesired = setup;
            chan.setup = setupChannelImpl(channel, setup);
            return chan.setup;
        }
        return IoValue::Error::CHANNEL_IN_USE;
    }

    // returns written value or error
    IoValue::variant writeChannel(uint8_t channel, IoValue::variant val)
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        auto& chan = channels[channel - 1];

        auto result = writeChannelImpl(channel, val);
        if (std::holds_alternative<IoValue::Error>(result)) {
            chan.actual = result;
            chan.desired = val;
        } else {
            chan.desired = result;
        }
        return result;
    }

    [[nodiscard]] IoValue::variant readChannel(uint8_t channel) const
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        return readChannelImpl(channel);
    }

    [[nodiscard]] size_t size() const
    {
        return channels.size();
    }

protected:
    [[nodiscard]] virtual IoValue::variant readChannelImpl(uint8_t channel) const = 0;
    [[nodiscard]] virtual IoValue::variant writeChannelImpl(uint8_t channel, IoValue::variant value) = 0;
    [[nodiscard]] virtual IoValue::Setup::variant setupChannelImpl(uint8_t channel, IoValue::Setup::variant value) = 0;

    [[nodiscard]] IoValue::variant desired(uint8_t channel) const
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        return channels[channel - 1].desired;
    }

private:
    struct Channel {
        IoValue::variant desired = IoValue::Error::NOT_CONFIGURED;
        IoValue::variant actual = IoValue::Error::NOT_CONFIGURED;
        IoValue::Setup::variant setup = IoValue::Setup::Unused{};
        IoValue::Setup::variant setupDesired = IoValue::Setup::Unused{};
        IoValue::PWM::duty_t duty_current = 0;
        IoValue::PWM::duty_t duty_target = 0;
    };

    std::vector<Channel> channels;
};
