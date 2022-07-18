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

#pragma once

#include "control/ActuatorDigitalBase.hpp"
#include "control/ControlPtr.hpp"
#include "control/IoArray.hpp"
#include <cstdint>
#include <functional>
#include <memory>

/*
 * A digital actuator that toggles a channel of an ArrayIo object.
 *
 */
class ActuatorDigital : public ActuatorDigitalBase {
private:
    ControlPtr<IoArray>& m_target;
    bool m_invert = false;
    uint8_t m_channel = 0;
    uint8_t m_desiredChannel = 0;

public:
    explicit ActuatorDigital(ControlPtr<IoArray>& target, uint8_t chan)
        : m_target(target)
    {
        channel(chan);
    }

    ActuatorDigital(const ActuatorDigital&) = delete;
    ActuatorDigital(ActuatorDigital&&) = default;
    ActuatorDigital& operator=(const ActuatorDigital&) = delete;
    ActuatorDigital& operator=(ActuatorDigital&&) = delete;

    virtual ~ActuatorDigital()
    {
        channel(0); // release channel before destruction
    }

    void state(const State& v) final;

    [[nodiscard]] State state() const final;

    [[nodiscard]] bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        auto active = state();
        m_invert = inv;
        state(active);
    }

    [[nodiscard]] uint8_t channel() const
    {
        return m_desiredChannel;
    }

    void claimChannel();

    [[nodiscard]] bool channelReady() const
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
