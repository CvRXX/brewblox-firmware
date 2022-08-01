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

using duty_t = FastPwm::duty_t;

FastPwm::FastPwm(ControlPtr<IoArray>& target, uint8_t chan)
    : m_target(target)
    , enabler(true, [this](bool arg) {
        if (!arg && this->enabler.get()) {
            this->setting(std::nullopt);
        }
        return arg;
    })
{
    channel(chan);
}

void FastPwm::setting(std::optional<value_t> val)
{
    if (!val) {
        if (m_desiredDuty) {
            // set to zero once if the setting is cleared
            if (auto devPtr = m_target.lock()) {
                devPtr->writeChannel(m_channel, IoValue::PWM{0});
            }
        }
        m_desiredDuty = std::nullopt;
    } else {
        m_desiredDuty = std::clamp(*val, minDuty, maxDuty);
    }
}

ticks_millis_t FastPwm::update(ticks_millis_t now)
{
    if (!m_desiredDuty) {
        return now + 1000;
    }

    if (!channelReady()) {
        if (!claimChannel()) {
            m_actualDuty = 0;
            return now + 1000;
        }
    }

    if (auto devPtr = m_target.lock()) {
        auto duty = m_actualDuty.value_or(0);
        if (m_transitionDuration) {
            // change max 25% in case update interval was long
            auto elapsed = std::min(now - m_lastUpdateTime, m_transitionDuration / 4);
            // use 1 bit as minimum increment
            duty_t increment = std::max(duty_t{(maxIncrease * elapsed) / (m_transitionDuration / 4)},
                                        cnl::numeric_limits<duty_t>::min());
            if (duty < *m_desiredDuty) {
                duty = std::min(duty_t{duty + increment}, *m_desiredDuty);
            } else {
                duty = std::max(duty_t{duty - increment}, *m_desiredDuty);
            }
        } else {
            duty = *m_desiredDuty;
        }
        m_lastUpdateTime = now;
        auto result = devPtr->writeChannel(m_channel, IoValue::PWM{duty});
        if (const auto* pVal = std::get_if<IoValue::PWM>(&result)) {
            m_actualDuty = pVal->duty();
            return now + std::max(duration_millis_t{10}, m_transitionDuration / 16); // use 16 steps, but at least 10 ms
        }
    }

    m_actualDuty = std::nullopt;

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
