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

void ActuatorDigital::state(State v)
{
    if (channelReady()) {
        if (auto devPtr = m_target.lock()) {
            if (v != State::Active) {
                v = State::Inactive;
            }
            if (m_invert) {
                v = invertState(v);
            }
            devPtr->writeChannel(m_channel, IoValue::Digital{v});
        }
    }
}

State ActuatorDigital::state() const
{
    if (channelReady()) {
        if (auto devPtr = m_target.lock()) {
            State result = State::Unknown;
            auto val = devPtr->readChannel(m_channel);
            if (auto* v = std::get_if<IoValue::Digital>(&val)) {
                result = v->state();
                if (m_invert) {
                    result = invertState(result); // todo: handle pwm transitions for inversion
                }
                return result;
            }
        }
    }

    return State::Unknown;
}

void ActuatorDigital::claimChannel()
{
    if (auto devPtr = m_target.lock()) {
        if (m_channel != 0) {
            // release old channel
            devPtr->setupChannel(m_channel, IoValue::Setup::Unused{});
        }

        if (m_desiredChannel == 0) {
            m_channel = 0;
            return;
        }
        // claim new channel
        auto result = devPtr->setupChannel(m_desiredChannel, IoValue::Setup::OutputDigital{});
        if (std::holds_alternative<IoValue::Setup::OutputDigital>(result)) {
            m_channel = m_desiredChannel;
        }
    }
}
