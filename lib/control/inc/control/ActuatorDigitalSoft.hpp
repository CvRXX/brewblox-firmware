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
    ControlPtr<IoArray>& m_target;
    bool m_invert = false;
    uint8_t m_channel = 0;
    uint8_t m_desiredChannel = 0;
    duration_millis_t m_transitionDuration = 0;
    ticks_millis_t m_lastUpdateTime = 0;
    duty_t m_duty = 0;
    State m_desired = State::Inactive;
    State m_actual = State::Unknown;

public:
    explicit ActuatorDigitalSoft(ControlPtr<IoArray>& target, uint8_t chan)
        : m_target(target)
    {
        channel(chan);
    }

    ActuatorDigitalSoft(const ActuatorDigitalSoft&) = delete;
    ActuatorDigitalSoft(ActuatorDigitalSoft&&) = default;
    ActuatorDigitalSoft& operator=(const ActuatorDigitalSoft&) = delete;
    ActuatorDigitalSoft& operator=(ActuatorDigitalSoft&&) = delete;

    virtual ~ActuatorDigitalSoft()
    {
        channel(0); // release channel before destruction
    }

    void state(State v) final;

    [[nodiscard]] State state() const override final
    {
        return m_actual;
    }

    [[nodiscard]] bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        auto active = state();
        m_invert = inv;
        state(active);
    }

    [[nodiscard]] uint8_t channel() const
    {
        return m_desiredChannel;
    }

    void channel(uint8_t newChannel)
    {
        m_desiredChannel = newChannel;
        update(0);
    }

    bool claimChannel();

    [[nodiscard]] bool channelReady() const
    {
        return m_desiredChannel == m_channel;
    }

    ticks_millis_t update(ticks_millis_t now);

    void transitionTime(duration_millis_t arg)
    {
        if (arg >= 100) {
            m_transitionDuration = arg;
        } else {
            m_transitionDuration = 0;
        }
    };

    [[nodiscard]] auto transitionTime()
    {
        return m_transitionDuration;
    };
};
