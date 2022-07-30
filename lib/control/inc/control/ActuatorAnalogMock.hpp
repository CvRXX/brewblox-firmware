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
#include <cstdint>

/*
 * A range actuator that simply remembers the set value. This is primary used for testing.
 */
class ActuatorAnalogMock : public ActuatorAnalog {
private:
    // clipping for setting
    value_t m_minSetting = cnl::numeric_limits<value_t>::lowest();
    value_t m_maxSetting = cnl::numeric_limits<value_t>::max();

    // clipping for value (actuator can't reach setpoint)
    value_t m_minValue = cnl::numeric_limits<value_t>::lowest();
    value_t m_maxValue = cnl::numeric_limits<value_t>::max();

    std::optional<value_t> m_setting = 0;

public:
    // construct without arguments, val = invalid, min and max are defaults
    ActuatorAnalogMock() {}
    ActuatorAnalogMock(const ActuatorAnalogMock&) = delete;
    ActuatorAnalogMock& operator=(const ActuatorAnalogMock&) = delete;

    // construct with just val, min and max are defaults
    explicit ActuatorAnalogMock(const value_t& initial)
        : m_setting(initial)
    {
    }

    // construct with val, min, max
    ActuatorAnalogMock(const value_t& initial, const value_t& minVal, const value_t& maxVal)
        : m_minSetting(minVal)
        , m_maxSetting(maxVal)
    {
        setting(initial);
    }

    virtual ~ActuatorAnalogMock() = default;

    void setting(std::optional<value_t> val) final
    {
        if (val.has_value()) {
            m_setting = std::clamp(*val, m_minSetting, m_maxSetting);
        } else {
            m_setting = std::nullopt;
        }
    }
    std::optional<value_t> setting() const final
    {
        return m_setting;
    }

    std::optional<value_t> value() const final
    {
        if (m_setting.has_value()) {
            return std::clamp(*m_setting, m_minValue, m_maxValue);
        } else {
            return std::nullopt;
        }
    }

    value_t minSetting() const
    {
        return m_minSetting;
    }

    void minSetting(value_t arg)
    {
        m_minSetting = arg;
    }

    value_t maxSetting() const
    {
        return m_maxSetting;
    }

    void maxSetting(value_t arg)
    {
        m_maxSetting = arg;
    }

    value_t minValue() const
    {
        return m_minValue;
    }

    void minValue(value_t arg)
    {
        m_minValue = arg;
    }

    value_t maxValue() const
    {
        return m_maxValue;
    }

    void maxValue(value_t arg)
    {
        m_maxValue = arg;
    }
};
