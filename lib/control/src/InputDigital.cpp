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

#include "control/InputDigital.hpp"
#include "control/IoArray.hpp"
#include <functional>
#include <memory>

using State = InputDigital::State;

State InputDigital::state() const
{
    if (channelReady()) {
        if (auto devPtr = m_target.lock()) {
            auto ioValue = devPtr->readChannel(m_channel);
            if (auto v = std::get_if<IoValue::Digital>(&ioValue)) {
                return m_invert ? invertState(v->state()) : v->state();
            }
        }
    }
    return State::Unknown;
}

void InputDigital::claimChannel()
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
        auto result = devPtr->setupChannel(m_desiredChannel, IoValue::Setup::InputDigital{});
        if (std::holds_alternative<IoValue::Setup::InputDigital>(result)) {
            m_channel = m_desiredChannel;
        }
    }
}
