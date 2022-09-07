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

class ActuatorDigitalSoft;

/*
 * A digital actuator that toggles a channel of an ArrayIo object.
 *
 */
class ActuatorDigital : public ActuatorDigitalBase {
private:
    ControlPtr<IoArray>& m_target;
    uint8_t m_channel = 0;
    bool m_invert = false;

    bool ensureChannelSetup(std::shared_ptr<IoArray>& devPtr);

public:
    explicit ActuatorDigital(ControlPtr<IoArray>& target, uint8_t chan)
        : m_target(target)
        , m_channel(chan)
    {
        // TODO(Bob) refactor ActuatorDigitalChangeLogged / ActuatorDigitalConstrained to not rely on this behavior
        update();
    }

    ActuatorDigital(const ActuatorDigital&) = delete;
    ActuatorDigital(ActuatorDigital&&) = default;
    ActuatorDigital& operator=(const ActuatorDigital&) = delete;
    ActuatorDigital& operator=(ActuatorDigital&&) = delete;
    virtual ~ActuatorDigital() = default;

    [[nodiscard]] State state() const final;

    void state(State v) final;

    [[nodiscard]] uint8_t channel() const
    {
        return m_channel;
    }

    void channel(uint8_t chan)
    {
        m_channel = chan;
    }

    [[nodiscard]] bool invert() const
    {
        return m_invert;
    }

    void invert(bool inv)
    {
        m_invert = inv;
    }

    void update()
    {
        // Check whether we can claim and setup target channel
        if (auto devPtr = m_target.lock()) {
            ensureChannelSetup(devPtr);
        }
    }
};
