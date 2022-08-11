/*
 * Copyright 2015 BrewPi/Elco Jacobs.
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
#include "control/SetpointSensorPair.hpp"
#include <functional>
#include <memory>

/*
 * An analog actuator that sets a target to reference value + offset
 */
class ActuatorOffset final : public ActuatorAnalog {
public:
    enum ReferenceKind {
        SETTING,
        VALUE
    };

private:
    ControlPtr<SetpointSensorPair>& m_target;
    ControlPtr<SetpointSensorPair>& m_reference;
    std::optional<value_t> m_desiredSetting;
    std::optional<value_t> m_value;
    std::optional<value_t> m_targetSetting;

    ReferenceKind m_selectedReference = ReferenceKind::SETTING;

public:
    Enabler enabler;

    explicit ActuatorOffset(
        ControlPtr<SetpointSensorPair>& target,    // process value to manipulate
        ControlPtr<SetpointSensorPair>& reference) // process value to offset from
        : m_target(target)
        , m_reference(reference)
        , enabler(true, [this](bool arg) {
            if (arg != this->enabler.get()) {
                this->update();
            }
            return arg;
        })
    {
    }
    ActuatorOffset(const ActuatorOffset&) = delete;
    ActuatorOffset& operator=(const ActuatorOffset&) = delete;

    virtual ~ActuatorOffset() = default;

    void setting(std::optional<value_t> val) final
    {
        m_desiredSetting = val;
        update();
    }

    std::optional<value_t> setting() const final
    {
        if (enabler.get()) {
            return m_desiredSetting;
        }
        return std::nullopt;
    }

    // value() returns the actually achieved offset
    // By returning the actually achieved value, instead of the difference between the setpoints,
    // a PID can read back the actual actuator value and perform integrator anti-windup
    std::optional<value_t> value() const final
    {
        return m_value;
    }

    void selectedReference(const ReferenceKind& sel)
    {
        m_selectedReference = sel;
        update();
    }

    ReferenceKind selectedReference() const
    {
        return m_selectedReference;
    }

    void update()
    {
        // scenarios:
        // ref valid, setting valid -> write actuator
        // ref invalid, setting valid -> write invalid to actuator the first time
        // ref valid, setting invalid -> write invalid to actuator the first time
        // ref invalid, setting invalid -> write invalid to actuator the first time

        std::optional<value_t> newTargetSetting = std::nullopt;
        if (auto targetPtr = m_target.lock()) {
            if (auto refPtr = m_reference.lock()) {
                if (auto ref = m_selectedReference == ReferenceKind::SETTING ? refPtr->setting() : refPtr->value()) {
                    if (enabler.get()) {
                        if (auto set = setting()) {
                            newTargetSetting = *ref + *set;
                        }
                    }
                    if (auto val = targetPtr->value()) {
                        m_value = *val - *ref;
                    } else {
                        m_value = std::nullopt;
                    }
                } else {
                    m_value = std::nullopt;
                }
            }
            // if old setting was valid or new setting is valid, apply to actuator
            // this ensures invalid is only applied once
            if (m_targetSetting || newTargetSetting) {
                targetPtr->setting(newTargetSetting);
                m_targetSetting = newTargetSetting;
            }
        }
        if (!enabler.get()) {
            m_target.release();
        }
    }
};
