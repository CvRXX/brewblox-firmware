/*
 * Copyright 2018 BrewPi B.V.
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

#include "control/ActuatorAnalog.hpp"
#include "control/ControlPtr.hpp"
#include "control/Enabler.hpp"
#include "control/IoArray.hpp"
#include "control/TicksTypes.hpp"
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>

#if 0
/**
    FastPWM directly drives a PWM capable IO channel, bypassing DigitalActuator, so without support for digital constraints
 */
class FastPwm final : public ActuatorAnalog {
public:
    using value_t = ActuatorAnalog::value_t;
    using duty_t = IoValue::PWM::duty_t;
    using update_t = ticks_millis_t;

private:
    ControlPtr<IoArray>& m_target;
    bool m_invert = false;
    uint8_t m_channel = 0;
    uint8_t m_desiredChannel = 0;
    duty_t m_desiredDuty = 0;
    duty_t m_actualDuty = 0;

    static constexpr auto maxDuty = duty_t{100};

public:
    // separate flag for manually disabling the pwm actuator
    Enabler enabler;

    explicit FastPwm(ControlPtr<IoArray>& target, uint8_t chan)
        : m_target(target)
    {
        channel(chan);
    }

    FastPwm(const FastPwm&) = delete;
    FastPwm& operator=(const FastPwm&) = delete;

    virtual ~FastPwm()
    {
        channel(0); // release channel before destruction
    }

    [[nodiscard]] value_t value() const final
    {
        return m_actualDuty.value_or(0);
    }

    [[nodiscard]] value_t setting() const final
    {
        m_desiredDuty.value_or(0);
    }

    void setting(const value_t& val) final;

    [[nodiscard]] duration_millis_t period() const;

    void period(const duration_millis_t& p);

    [[nodiscard]] bool valueValid() const final;

    [[nodiscard]] bool settingValid() const final;

    void settingValid(bool v) final;

    ticks_millis_t update(ticks_millis_t now);

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

    [[nodiscard]] bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        if (m_invert != inv) {
            m_invert = inv;
            update(0);
        }
    }
};
#endif
