/*
 * Copyright 2013 BrewPi/Elco Jacobs.
 * Copyright 2013 Matthew McGowan
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

#include "control/ActuatorDigital.hpp"
#include "control/ActuatorDigitalBase.hpp"
#include "control/IoArray.hpp"
#include <functional>
#include <memory>

using State = ActuatorDigitalBase::State;

void ActuatorDigital::state(const State& v)
{
    if (channelReady()) {
        if (auto devPtr = m_target()) {
            auto newState = v;
            if (m_invert) {
                newState = invertState(v);
            }
            IoArray::ChannelConfig config = newState == State::Active ? IoArray::ChannelConfig::DRIVING_ON : IoArray::ChannelConfig::DRIVING_OFF;
            devPtr->writeChannelConfig(m_channel, config);
        }
    }
}

State ActuatorDigital::state() const
{
    if (channelReady()) {
        if (auto devPtr = m_target()) {
            State result = State::Unknown;
            if (devPtr->senseChannel(m_channel, result)) {
                if (m_invert) {
                    result = invertState(result);
                }
                return result;
            }
        }
    }

    return State::Unknown;
}

void ActuatorDigital::claimChannel()
{
    if (auto devPtr = m_target()) {
        if (m_channel != 0) {
            if (!devPtr->releaseChannel(m_channel)) {
                return;
            }
        }

        if (m_desiredChannel == 0) {
            m_channel = 0;
            return;
        }
        if (devPtr->claimChannel(m_desiredChannel, IoArray::ChannelConfig::DRIVING_OFF)) {
            m_channel = m_desiredChannel;
        }
    }
}

bool ActuatorDigital::supportsFastIo() const
{
    if (auto devPtr = m_target()) {
        return devPtr->supportsFastIo();
    }
    return false;
}
