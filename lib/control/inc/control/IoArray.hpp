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
#include <inttypes.h>
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
};

class Setup {
public:
    enum class Type : uint8_t {
        UNUSED = 0,
        OUTPUT_DIGITAL = 1,
        OUTPUT_PWM = 2,
        OUTPUT_DIGITAL_BIDIRECTIONAL = 3,
        OUTPUT_PWM_BIDIRECTIONAL = 4,
        INPUT_DIGITAL = 10,
        UNKNOWN = 255,
    };

    Setup(Type t)
        : type(t)
    {
    }
    Type type;
};

struct Transition {
    uint16_t current = 0;
    uint16_t target = 0;
};

class Base {
private:
    std::optional<Transition> _transition;

public:
    Base(std::optional<Transition> t = {})
        : _transition{t}
    {
    }

    virtual State state() const = 0;
    std::optional<Transition> transition() const
    {
        return _transition;
    }
};

class Digital : public Base {
private:
    State _state;

public:
    Digital(State s)
        : _state(s)
    {
    }
    Digital(bool s)
        : _state{State(s)}
    {
    }

    State state() const override
    {
        return _state;
    }
};

class PWM : public Base {
public:
    using duty_t = ActuatorAnalog::value_t;

private:
    duty_t _duty = 0;

public:
    PWM(duty_t d)
        : _duty{d}
    {
    }

    State state() const override
    {
        if (_duty > 0) {
            return State::Active;
        } else if (_duty < 0) {
            return State::Reverse;
        }
        return State::Inactive;
    }
};

class DigitalBidir : public Digital {
    using Digital::Digital;
};

class PWMBidir : public PWM {
    using PWM::PWM;
};

using variant = std::variant<Error, Setup, Digital, PWM, DigitalBidir, PWMBidir>;
};

/*
 * Abstract interface to an array of digital inputs and/or outputs
 */
class IoArray {
public:
    using State = ActuatorDigitalBase::State;
    IoArray(uint8_t size)
        : channels(size)
    {
    }

    IoArray(const IoArray&) = delete;
    IoArray& operator=(const IoArray&) = delete;

    virtual ~IoArray() = default;

    bool validChannel(uint8_t channel) const
    {
        // first channel is 1, because 0 is used as 'unconfigured'
        return channel > 0 && channel <= size();
    }

    // writes default value of type to channel
    void defaultConfig(uint8_t channel)
    {
        if (std::holds_alternative<IoValue::Digital>(channels[channel].desired)) {
            writeChannelImpl(channel, IoValue::Digital(State::Inactive));
        } else if (std::holds_alternative<IoValue::DigitalBidir>(channels[channel].desired)) {
            writeChannelImpl(channel, IoValue::Digital(State::Inactive));
        } else if (std::holds_alternative<IoValue::DigitalBidir>(channels[channel].desired)) {
            writeChannelImpl(channel, IoValue::PWM(0));
        } else if (std::holds_alternative<IoValue::DigitalBidir>(channels[channel].desired)) {
            writeChannelImpl(channel, IoValue::PWMBidir(0));
        }
    }

    // returns written value or error
    IoValue::variant writeChannel(uint8_t channel, IoValue::variant val)
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        auto& chan = channels[channel - 1];

        // for setup values handle claiming/releasing the channel
        if (auto* v = std::get_if<IoValue::Setup>(&val)) {
            // check if new value is a channel release
            if (v->type == IoValue::Setup::Type::UNUSED) {
                defaultConfig(channel);
            } else {
                // only allow setup on unused channels
                if (auto* current = std::get_if<IoValue::Error>(&chan.desired)) {
                    if (*current != IoValue::Error::NOT_CONFIGURED) {
                        return IoValue::Error::CHANNEL_IN_USE;
                    }
                }
            }
        } else if (val.index() != chan.desired.index()) {
            // only allow to write values of the same type
            return IoValue::Error::UNSUPPORTED_VALUE;
        }
        auto result = writeChannelImpl(channel, val);
        if (std::holds_alternative<IoValue::Error>(result)) {
            chan.actual = result;
            chan.desired = val;
        } else {
            chan.desired = result;
        }
        return result;
    }

    IoValue::variant readChannel(uint8_t channel) const
    {
        if (!validChannel(channel)) {
            return IoValue::Error::INVALID_CHANNEL;
        }
        return readChannelImpl(channel);
    }

    uint8_t size() const
    {
        return channels.size();
    }

protected:
    virtual IoValue::variant readChannelImpl(uint8_t channel) const = 0;
    virtual IoValue::variant writeChannelImpl(uint8_t channel, IoValue::variant value) = 0;

    IoValue::variant desired(uint8_t channel) const
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
    };

    mutable std::vector<Channel> channels;
};
