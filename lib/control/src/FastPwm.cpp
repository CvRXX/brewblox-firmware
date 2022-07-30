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

#include "control/FastPwm.hpp"
#include <algorithm>

#if 0
using duty_t = FastPwm::duty_t;

ticks_millis_t FastPwm::update(ticks_millis_t now)
{
    if (!channelReady()) {
        if (!claimChannel()) {
            m_actualDuty = 0;
            return now + 1000;
        }
    }

    if (auto devPtr = m_target.lock()) {
        auto duty = m_duty;
        if (m_transitionDuration) {
            // change max 25% in case update interval was long
            auto elapsed = std::min(now - m_lastUpdateTime, m_transitionDuration / 4);
            duty_t increment = (duty_t{25} * elapsed) / (m_transitionDuration / 4);

            if (m_desired == State::Active) {
                // use duty of at least 1% when active
                duty += increment;
                if (duty <= duty_t{0}) {
                    duty = duty_t{1};
                }
                if (duty > duty_t{100}) {
                    duty = 100;
                }
            } else {
                duty -= increment;
                if (duty < duty_t{0}) {
                    duty = duty_t{0};
                }
            }
        } else {
            duty = m_desired == State::Active ? duty_t{100} : duty_t{0};
        }
        m_lastUpdateTime = now;
        auto result = devPtr->writeChannel(m_channel, IoValue::PWM{duty});
        if (const auto* pVal = std::get_if<IoValue::PWM>(&result)) {
            m_duty = pVal->duty();
            m_actual = m_duty != 0 ? State::Active : State::Inactive;
            return now + 25;
        }
    }

    m_actual = State::Unknown;

    return now + 1000;
}

bool FastPwm::claimChannel()
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
        auto channelFlags = devPtr->getChannelCapabilities(m_desiredChannel);
        auto setup = IoValue::Setup::OutputPwm{};
        if (channelFlags.flags.pwm2000Hz) {
            setup.frequency = IoValue::Setup::Frequency::FREQ_2000HZ;
        } else if (channelFlags.flags.pwm100Hz) { // currently no devices that support 200hz but don't support 2khz
            setup.frequency = IoValue::Setup::Frequency::FREQ_100HZ;
        } else {
            return false;
        }

        auto result = devPtr->setupChannel(m_desiredChannel, std::move(setup));
        if (std::holds_alternative<IoValue::Setup::OutputPwm>(result)) {
            m_channel = m_desiredChannel;
            return true;
        }
    }
    return false;
}
#endif
