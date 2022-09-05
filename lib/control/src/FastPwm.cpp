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
    if (val.has_value()) {
        m_desiredDuty = std::clamp(*val, minDuty(), maxDuty());
    } else {
        if (m_desiredDuty.has_value()) {
            // set to zero once if the setting is cleared
            if (auto devPtr = m_target.lock()) {
                devPtr->writeChannel(m_channel, IoValue::PWM{m_invert ? maxDuty() : minDuty()});
            }
            m_desiredDuty = std::nullopt;
        }
    }
}

ticks_millis_t FastPwm::update(ticks_millis_t now)
{
    auto nextUpdate = now + 1000;
    m_actualDuty = std::nullopt;

    if (!enabler.get()) {
        m_target.release();
        return nextUpdate;
    }

    if (!channelReady()) {
        if (!claimChannel()) {
            return nextUpdate;
        }
    }

    if (auto devPtr = m_target.lock()) {
        auto desired = m_desiredDuty.value_or(0);
        if (m_transitionTime) {
            // change max 25% in case update interval was long
            // change min 1 bit of duty_t
            duration_millis_t elapsed = now ? now - m_lastUpdateTime : 0;
            int32_t rawIncrement = (int64_t{cnl::unwrap(maxDuty())} * elapsed) / m_transitionTime;
            duty_t increment = (rawIncrement > cnl::unwrap(maxIncrease)) ? maxIncrease : cnl::wrap<duty_t>(rawIncrement);
            if (m_transitionDuty < desired) {
                m_transitionDuty += increment;
                if (m_transitionDuty > desired) {
                    m_transitionDuty = desired;
                }
            } else if (m_transitionDuty > desired) {
                m_transitionDuty -= increment;
                if (m_transitionDuty < desired) {
                    m_transitionDuty = desired;
                }
            }
            if (desired > 0 && m_transitionDuty == 0) {
                // ensure active state
                m_transitionDuty = cnl::wrap<duty_t>(int32_t{1});
            }
        } else {
            m_transitionDuty = desired;
        }
        auto writtenValue = m_invert ? duty_t{maxDuty() - m_transitionDuty} : m_transitionDuty;
        auto result = devPtr->writeChannel(m_channel, IoValue::PWM{writtenValue});
        auto actual = devPtr->readChannel(m_channel);
        if (const auto* pVal = std::get_if<IoValue::PWM>(&actual)) {
            m_actualDuty = m_invert ? duty_t{maxDuty() - pVal->duty()} : pVal->duty();
            nextUpdate = now + 10;
        }
    }
    if (now) {
        m_lastUpdateTime = now;
    }
    return nextUpdate;
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
            setup.frequency = m_frequency;
        } else if (channelFlags.flags.pwm100Hz) { // currently no devices that support 200hz but don't support 2khz
            setup.frequency = IoValue::Setup::Frequency::FREQ_100HZ;
            m_frequency = IoValue::Setup::Frequency::FREQ_100HZ;
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

duration_millis_t FastPwm::transitionTimeFromPreset(SoftTransitionsPreset preset, duration_millis_t custom)
{
    switch (preset) {
    case ST_OFF:
        return 0;
    case ST_FAST:
        return 250;
    case ST_MEDIUM:
        return 750;
    case ST_SLOW:
        return 2000;
    case ST_CUSTOM:
        return custom;
    }
    return 0;
}

duty_t FastPwm::minDuty() const
{
    if (auto devPtr = m_target.lock()) {
        if (devPtr->getChannelCapabilities(m_channel).flags.bidirectional) {
            return maxReverseDuty;
        }
    }
    return zeroDuty;
}
