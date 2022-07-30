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

#include "control/ControlPtr.hpp"
#include "control/Enabler.hpp"
#include "control/FixedPoint.hpp"
#include "control/FpFilterChain.hpp"
#include "control/ProcessValue.hpp"
#include "control/TempSensor.hpp"
#include "control/Temperature.hpp"
#include <functional>
#include <memory>

/*
 * A process value has a setting and an current value
 */
class SetpointSensorPair : public ProcessValue<temp_t> {
public:
    using derivative_t = safe_elastic_fixed_point<1, 23>;

private:
    std::optional<temp_t> m_setting = std::nullopt;
    ControlPtr<TempSensor>& m_sensor;
    FpFilterChain<temp_t> m_filter;
    uint8_t m_sensorFailureCount = 255; // force a reset on init
    static constexpr auto m_failureThreshold = uint8_t{10};
    uint8_t m_filterNr = 1;

public:
    Enabler enabler;

    explicit SetpointSensorPair(
        ControlPtr<TempSensor>& _sensor)
        : m_sensor(_sensor)
        , m_filter(1)
        , enabler(false)
    {
        update();
    }

    SetpointSensorPair(const SetpointSensorPair&) = delete;
    SetpointSensorPair& operator=(const SetpointSensorPair&) = delete;

    virtual ~SetpointSensorPair() = default;

    void setting(std::optional<temp_t> setting) final
    {
        m_setting = setting;
    }

    std::optional<temp_t> setting() const final
    {
        return m_setting;
    }

    std::optional<temp_t> value() const final
    {
        if (m_sensorFailureCount <= m_failureThreshold) {
            if (m_filterNr == 0) {
                return m_filter.readLastInput();
            }
            return m_filter.read(m_filterNr - 1);
        }
        return std::nullopt;
    }

    std::optional<temp_t> valueUnfiltered() const
    {
        if (auto sPtr = m_sensor.lock()) {
            return sPtr->value();
        }
        return std::nullopt;
    }

    auto filterChoice() const
    {
        return m_filterNr;
    }

    auto filterThreshold() const
    {
        return m_filter.getStepThreshold();
    }

    void filterChoice(uint8_t choice)
    {
        m_filterNr = choice;
    }

    auto filterThreshold(temp_t threshold)
    {
        if (threshold == 0) {
            threshold = 5;
        }
        m_filter.setStepThreshold(threshold);
    }

    void update()
    {
        if (auto val = valueUnfiltered()) {
            if (m_sensorFailureCount > m_failureThreshold) {
                m_filter.reset(*val);
            }
            m_filter.add(*val);
            m_sensorFailureCount = 0;
        } else {
            if (m_sensorFailureCount < 255) {
                m_sensorFailureCount++;
            }
        }
    }

    std::optional<temp_t> error()
    {
        if (auto s = setting()) {
            if (auto v = value()) {
                return *s - *v;
            }
        };
        return std::nullopt;
    }

    derivative_t readDerivative(uint8_t filterNr)
    {
        if (m_sensorFailureCount > m_failureThreshold) {
            return 0;
        }
        if (filterNr < 1) {
            filterNr = 1;
        }
        return m_filter.readDerivative<derivative_t>(filterNr - 1);
    }

    auto filterLength()
    {
        return m_filter.length();
    }

    auto resizeFilterIfNeeded(uint8_t filterNr)
    {
        m_filter.expandStages(filterNr);
    }

    void resetFilter()
    {
        if (auto val = valueUnfiltered()) {
            m_filter.reset(*val);
            m_sensorFailureCount = 0;
        }
    }
};
