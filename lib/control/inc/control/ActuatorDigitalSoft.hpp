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

#include "FastPwm.hpp"
#include "control/ActuatorDigitalBase.hpp"
#include "control/ControlPtr.hpp"
#include "control/IoArray.hpp"
#include "control/TicksTypes.hpp"

/*
 * A digital actuator that toggles a channel of an ArrayIo object.
 *
 */
class ActuatorDigitalSoft : public ActuatorDigitalBase {
public:
    using duty_t = IoValue::PWM::duty_t;

private:
    FastPwm pwm;
    State m_desired = State::Inactive;
    State m_actual = State::Unknown;

public:
    explicit ActuatorDigitalSoft(ControlPtr<IoArray>& target, uint8_t chan)
        : pwm(target, chan)
    {
    }

    ActuatorDigitalSoft(const ActuatorDigitalSoft&) = delete;
    ActuatorDigitalSoft(ActuatorDigitalSoft&&) = default;
    ActuatorDigitalSoft& operator=(const ActuatorDigitalSoft&) = delete;
    ActuatorDigitalSoft& operator=(ActuatorDigitalSoft&&) = default;

    virtual ~ActuatorDigitalSoft() = default;

    void state(State v) final
    {
        if (v == State::Active) {
            m_desired = State::Active;
            pwm.setting(100);
        } else {
            m_desired = State::Inactive;
            pwm.setting(0);
        }
        if (auto v = pwm.value()) {
            if (v == FastPwm::minDuty || v == FastPwm::maxDuty) {
                // do one immediate update if the actuator was at 0 or max to ensure the state will be active
                pwm.update();
            }
        }
    }

    [[nodiscard]] State state() const override final
    {
        if (auto v = pwm.value()) {
            return (*v != 0) ? State::Active : State::Inactive;
        }
        return State::Unknown;
    }

    [[nodiscard]] bool invert() const
    {
        return pwm.invert();
    }

    void invert(bool inv)
    {
        pwm.invert(inv);
    }

    [[nodiscard]] uint8_t channel() const
    {
        return pwm.channel();
    }

    void channel(uint8_t newChannel)
    {
        pwm.channel(newChannel);
        update();
    }

    ticks_millis_t update(ticks_millis_t now)
    {
        return pwm.update(now);
    }
    ticks_millis_t update()
    {
        return pwm.update();
    }

    void transitionTime(duration_millis_t arg)
    {
        pwm.transitionTime(arg);
    };

    [[nodiscard]] auto transitionTime() const
    {
        return pwm.transitionTime();
    };
};
