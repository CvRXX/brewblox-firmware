/*
 * Copyright 2022 BrewPi B.V.
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

enum SoftTransitionsPreset : uint8_t {
    ST_OFF = 0,
    ST_FAST = 1,
    ST_MEDIUM = 2,
    ST_SLOW = 3,
    ST_CUSTOM = 4,
};

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
    std::optional<value_t> m_desiredDuty = 0;
    std::optional<value_t> m_actualDuty = 0;
    value_t m_transitionDuty = 0;
    ticks_millis_t m_lastUpdateTime = 0;
    IoValue::Setup::Frequency m_frequency = IoValue::Setup::Frequency::FREQ_100HZ;
    duration_millis_t m_transitionTime = 0;

    bool ensureChannelSetup(std::shared_ptr<IoArray>& devPtr);

public:
    static constexpr auto maxForwardDuty = duty_t{100};
    static constexpr auto maxReverseDuty = duty_t{-100};
    static constexpr auto maxIncrease = duty_t{25};
    static constexpr auto zeroDuty = duty_t{0};

    // separate flag for manually disabling the pwm actuator
    Enabler enabler;

    explicit FastPwm(ControlPtr<IoArray>& target, uint8_t chan);

    FastPwm(const FastPwm&) = delete;
    FastPwm& operator=(const FastPwm&) = delete;

    [[nodiscard]] std::optional<value_t> value() const final
    {
        return m_actualDuty;
    }

    [[nodiscard]] std::optional<value_t> setting() const final
    {
        return m_desiredDuty;
    }

    void setting(std::optional<value_t> val) final;

    [[nodiscard]] duration_millis_t period() const;

    ticks_millis_t update(ticks_millis_t now);

    ticks_millis_t update()
    {
        return update(m_lastUpdateTime);
    }

    [[nodiscard]] uint8_t channel() const
    {
        return m_channel;
    }

    void channel(uint8_t newChannel)
    {
        m_channel = newChannel;
    }

    [[nodiscard]] bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        m_invert = inv;
    }

    static duration_millis_t transitionTimeFromPreset(SoftTransitionsPreset preset, duration_millis_t custom);

    void setTransitionTime(duration_millis_t time)
    {
        m_transitionTime = time;
    }

    duration_millis_t getTransitionTime() const
    {
        return m_transitionTime;
    }

    IoValue::Setup::Frequency frequency() const
    {
        return m_frequency;
    };

    void frequency(IoValue::Setup::Frequency f)
    {
        m_frequency = f;
    };

    duty_t minDuty() const;

    static constexpr duty_t maxDuty()
    {
        return maxForwardDuty;
    };
};
