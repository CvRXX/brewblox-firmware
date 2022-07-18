/*
 * Copyright 2013 BrewPi/Elco Jacobs.
 * Copyright 2013 Matthew McGowan
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

#pragma once

#include <cstdint>

/*
 * A digital actuator that toggles a channel of an ArrayIo object.
 *
 */
class ActuatorDigitalBase {
public:
    enum class State : uint8_t {
        Inactive = 0,
        Active = 1,
        Unknown = 2,
        Reverse = 3,
    };

    virtual void state(const State& v) = 0;

    [[nodiscard]] virtual State state() const = 0;

protected:
    ~ActuatorDigitalBase() = default;
    ActuatorDigitalBase() = default;
    ActuatorDigitalBase(const ActuatorDigitalBase&) = default;
    ActuatorDigitalBase(ActuatorDigitalBase&&) noexcept = default;
    ActuatorDigitalBase& operator=(const ActuatorDigitalBase&) = default;
    ActuatorDigitalBase& operator=(ActuatorDigitalBase&&) noexcept = default;
};

inline ActuatorDigitalBase::State invertState(ActuatorDigitalBase::State s)
{
    if (s == ActuatorDigitalBase::State::Active) {
        return ActuatorDigitalBase::State::Inactive;
    }
    if (s == ActuatorDigitalBase::State::Inactive) {
        return ActuatorDigitalBase::State::Active;
    }
    return ActuatorDigitalBase::State::Unknown;
}
