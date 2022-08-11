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
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/Enabler.hpp"
#include "control/FixedPoint.hpp"
#include <cstdint>
#include <functional>
#include <memory>

/**
    ActuatorPWM drives a (change logged) digital actuator and makes it available as range actuator, by quickly turning it on and off repeatedly.
 */
class ActuatorPwm final : public ActuatorAnalog {
public:
    using value_t = ActuatorAnalog::value_t;
    using State = ActuatorDigitalBase::State;
    using update_t = ticks_millis_t;

private:
    ControlPtr<ActuatorDigitalConstrained>& m_target;
    duration_millis_t m_period;
    duration_millis_t m_dutyTime = 0;
    std::optional<value_t> m_dutySetting = 0;
    std::optional<value_t> m_dutyAchieved = 0;

    static constexpr auto maxDuty = value_t{100};

    safe_elastic_fixed_point<2, 28> dutyFraction() const;

public:
    // separate flag for manually disabling the pwm actuator
    Enabler enabler;

    /** Constructor.
     *  @param _m_
     target Digital actuator to be toggled with PWM
     *  @param _period PWM period in milliseconds
     *  @sa getPeriod(), setPeriod(), getTarget(), setTarget()
     */
    explicit ActuatorPwm(
        ControlPtr<ActuatorDigitalConstrained>& target,
        duration_millis_t period = 4000);

    ActuatorPwm(const ActuatorPwm&) = delete;
    ActuatorPwm& operator=(const ActuatorPwm&) = delete;

    virtual ~ActuatorPwm()
    {
        // ensure that interrupts are removed before destruction.
        enabler.set(false);
    }

    /** ActuatorPWM keeps track of the last high and low transition.
     *  This function returns the actually achieved value. This can differ from
     *  the set value, because the m_
     target actuator is not toggling.
     *
     * @return achieved duty cycle in fixed point.
     */
    [[nodiscard]] std::optional<value_t> value() const final;

    /** Returns the set duty cycle
     * @return duty cycle setting in fixed point
     */
    [[nodiscard]] std::optional<value_t> setting() const final
    {
        return m_dutySetting;
    }

    /** Sets a new duty cycle
     * @param val new duty cycle in fixed point
     */
    void setting(std::optional<value_t>) final;

    //** Calculates whether the m_target should toggle and tries to toggle it if necessary
    /** Each update, the PWM actuator checks whether it should toggle to achieve the set duty cycle.
     * It checks wether the output pin toggled and updates it's internal counters to keep track of
     * the achieved duty cycle. When it toggles late, it tries to compensate for this in the next cycle.
     * To maintain the correct duty cycle average, it can make the next high time shorter or longer.
     * If needed, it can even skip going high or low. This will happen, for example, when the m_
     target is
     * a time limited actuator with a minimum on and/or off time.
     */
    update_t update(update_t now);

    /** returns the PWM period
     * @return PWM period in milliseconds
     */
    [[nodiscard]] duration_millis_t period() const;

    /** sets the PWM period
     * @param p new period in milliseconds
     */
    void period(const duration_millis_t& p);
};
