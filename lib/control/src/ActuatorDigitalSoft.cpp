/*
 * Copyright 2022 BrewPi/Elco Jacobs.
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

#include "control/ActuatorDigitalSoft.hpp"
#include <algorithm>

using State = ActuatorDigitalBase::State;

void ActuatorDigitalSoft::state(State v)
{
    if (v != State::Active) {
        v = State::Inactive;
    }
    if (m_invert) {
        v = invertState(v);
    }

    m_desired = v;
    // update(0);
}

State ActuatorDigitalSoft::state() const
{
    return m_actual;
}

ticks_millis_t ActuatorDigitalSoft::update(ticks_millis_t now)
{
    if (!channelReady()) {
        if (!claimChannel()) {
            m_actual = State::Unknown;
            return now + 1000;
        }
    }

    if (auto devPtr = m_target.lock()) {
        auto duty = m_duty;
        if (m_desired == State::Active) {
            duty = std::min(decltype(duty){duty + 10}, decltype(duty){100});
        } else if (m_desired == State::Inactive) {
            duty = std::max(decltype(duty){duty - 10}, decltype(duty){0});
        }

        auto result = devPtr->writeChannel(m_desiredChannel, IoValue::PWM{duty});
        if (const auto* pVal = std::get_if<IoValue::PWM>(&result)) {
            m_duty = pVal->duty();
            m_actual = m_duty != 0 ? State::Active : State::Inactive;
            return now + 25;
        }
    }

    m_actual = State::Unknown;
    return now + 1000;
}

bool ActuatorDigitalSoft::claimChannel()
{
    if (auto devPtr = m_target.lock()) {
        if (m_channel != 0) {
            // release old channel
            devPtr->setupChannel(m_channel, IoValue::Setup::Unused{});
        }

        if (m_desiredChannel == 0) {
            m_channel = 0;
            return true;
        }
        // claim new channel
        auto result = devPtr->setupChannel(m_desiredChannel, IoValue::Setup::OutputPwm{
                                                                 .frequency = IoValue::Setup::Frequency::FREQ_200HZ});
        if (std::holds_alternative<IoValue::Setup::OutputPwm>(result)) {
            m_channel = m_desiredChannel;
            return true;
        }
    }
    return false;
}
