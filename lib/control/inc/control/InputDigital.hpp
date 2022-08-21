/*
 * Copyright 2021 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "ActuatorDigitalBase.hpp"
#include "ControlPtr.hpp"
#include "IoArray.hpp"
#include <cstdint>
#include <memory>

/*
 * A digital input that reads a channel of an ArrayIo object.
 *
 */
class InputDigital {
public:
    using State = ActuatorDigitalBase::State;

private:
    ControlPtr<IoArray>& m_target;
    bool m_invert = false;
    uint8_t m_channel = 0;
    uint8_t m_desiredChannel = 0;

public:
    explicit InputDigital(ControlPtr<IoArray>& target, uint8_t chan)
        : m_target(target)
    {
        channel(chan);
    }

    InputDigital(const InputDigital&) = delete;
    InputDigital& operator=(const InputDigital&) = delete;

    virtual ~InputDigital()
    {
        channel(0); // release channel before destruction
    }

    State state() const;

    bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        m_invert = inv;
    }

    uint8_t channel() const
    {
        return m_desiredChannel;
    }

    void claimChannel();

    bool channelReady() const
    {
        return m_desiredChannel == m_channel;
    }

    void update()
    {
        if (!channelReady()) {
            // Periodic retry to claim channel in case target didn't exist
            // at earlier tries
            claimChannel();
        }
    }

    void channel(uint8_t newChannel)
    {
        m_desiredChannel = newChannel;
        update();
    }
};
