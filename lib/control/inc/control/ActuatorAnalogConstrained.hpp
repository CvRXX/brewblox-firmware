/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
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
#include <memory>
#include <vector>

namespace AAConstraints {
using value_t = ActuatorAnalog::value_t;

class Base {
public:
    // constraints are movable but not copyable
    Base() = default;
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;

    virtual ~Base() = default;

    virtual value_t constrain(const value_t& val) const = 0;

    virtual uint8_t id() const = 0;

    virtual uint8_t order() const = 0;
};

template <uint8_t ID>
class Minimum : public Base {
private:
    value_t m_min;

public:
    explicit Minimum(const value_t& v)
        : m_min(v)
    {
    }

    value_t constrain(const value_t& val) const final
    {
        return std::max(val, m_min);
    }

    uint8_t id() const final
    {
        return ID;
    }

    value_t min() const
    {
        return m_min;
    }

    uint8_t order() const final
    {
        return 0;
    }
};

template <uint8_t ID>
class Maximum : public Base {
private:
    value_t m_max;

public:
    explicit Maximum(const value_t& v)
        : m_max(v)
    {
    }

    value_t constrain(const value_t& val) const final
    {
        return std::min(val, m_max);
    }

    uint8_t id() const final
    {
        return ID;
    }

    value_t max() const
    {
        return m_max;
    }

    uint8_t order() const final
    {
        return 1;
    }
};
}

/*
 * An ActuatorAnalog has a range output
 */

class ActuatorAnalogConstrained : public ActuatorAnalog {
public:
    using Constraint = AAConstraints::Base;

private:
    std::vector<std::unique_ptr<Constraint>> constraints;
    ActuatorAnalog& actuator;
    uint8_t m_limiting = 0x00;
    std::optional<value_t> m_desiredSetting = 0;
    std::optional<value_t> m_setting = 0;

public:
    explicit ActuatorAnalogConstrained(ActuatorAnalog& act)
        : actuator(act)
    {
    }

    ActuatorAnalogConstrained(const ActuatorAnalogConstrained&) = delete;
    ActuatorAnalogConstrained& operator=(const ActuatorAnalogConstrained&) = delete;

    virtual ~ActuatorAnalogConstrained() = default;

    void addConstraint(std::unique_ptr<Constraint>&& newConstraint);

    void removeAllConstraints();

    value_t constrain(const value_t& val);

    void setting(std::optional<value_t> val) final;

    void update()
    {
        if (actuator.setting().has_value()) {
            setting(m_desiredSetting); // re-apply constraints
        }
    }

    virtual std::optional<value_t> setting() const final
    {
        return m_setting;
    }

    virtual std::optional<value_t> value() const final
    {
        return actuator.value();
    }

    std::optional<value_t> desiredSetting() const
    {
        return m_desiredSetting;
    }

    uint8_t limiting() const
    {
        return m_limiting;
    }

    const auto& constraintsList() const
    {
        return constraints;
    }
};
