/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewBlox.
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

#include "control/MotorValve.hpp"

void MotorValve::state(State v)
{
    auto oldState = m_desiredValveState;
    if (v == State::Active) {
        m_desiredValveState = ValveState::Opening;
    } else {
        m_desiredValveState = ValveState::Closing;
    }
    if (oldState != m_desiredValveState) {
        update();
    }
}

MotorValve::State
MotorValve::state() const
{
    if (m_actualValveState == ValveState::Opening || m_actualValveState == ValveState::Open) {
        return State::Active;
    }
    if (m_actualValveState == ValveState::Closing || m_actualValveState == ValveState::Closed) {
        return State::Inactive;
    }

    return State::Unknown;
}

void MotorValve::applyValveState(ValveState v, std::shared_ptr<IoArray>& devPtr)
{
    if (m_startChannel == 0) {
        return;
    }
    // ACTIVE HIGH means latch pull down enabled, so the input to the H-bridge is inverted.
    // We keep the motor enabled just in case. The valve itself has an internal shutoff.
    if (v == ValveState::Opening || v == ValveState::Open) {
        devPtr->writeChannel(m_startChannel + chanOpeningHigh, IoValue::Digital{State::Inactive});
        devPtr->writeChannel(m_startChannel + chanClosingHigh, IoValue::Digital{State::Active});
    } else if (v == ValveState::Closing || v == ValveState::Closed) {
        devPtr->writeChannel(m_startChannel + chanOpeningHigh, IoValue::Digital{State::Active});
        devPtr->writeChannel(m_startChannel + chanClosingHigh, IoValue::Digital{State::Inactive});
    } else {
        devPtr->writeChannel(m_startChannel + chanOpeningHigh, IoValue::Digital{State::Active});
        devPtr->writeChannel(m_startChannel + chanClosingHigh, IoValue::Digital{State::Active});
    }
}

MotorValve::ValveState
MotorValve::getValveState(const std::shared_ptr<IoArray>& devPtr) const
{
    if (m_startChannel == 0) {
        return ValveState::Unknown;
    }

    auto isClosedPin = devPtr->readChannel(m_startChannel + chanIsClosed);
    auto isOpenPin = devPtr->readChannel(m_startChannel + chanIsOpen);

    auto openChan = devPtr->readChannel(m_startChannel + chanOpeningHigh);
    auto closeChan = devPtr->readChannel(m_startChannel + chanClosingHigh);

    ValveState vs = ValveState::Unknown;

    // Note: signal to H-bridge is inverted because active high enables a pull down latch
    if (openChan == IoValue::Digital{State::Inactive} && closeChan == IoValue::Digital{State::Active}) {
        vs = ValveState::Opening;
    } else if (openChan == IoValue::Digital{State::Active} && closeChan == IoValue::Digital{State::Inactive}) {
        vs = ValveState::Closing;
    } else if (openChan == IoValue::Digital{State::Active} && closeChan == IoValue::Digital{State::Active}) {
        vs = ValveState::HalfOpenIdle;
    } else {
        return ValveState::InitIdle; // return immediately to get out of init state
    }

    if (isOpenPin == IoValue::Digital{State::Active}) {
        if (vs != ValveState::Closing) {
            vs = ValveState::Open;
        }
    }

    if (isClosedPin == IoValue::Digital{State::Active}) {
        if (vs != ValveState::Opening) {
            vs = ValveState::Closed;
        }
    }

    return vs;
}

void MotorValve::update()
{
    if (!channelReady()) {
        // Periodic retry to claim channel in case target didn't exist
        // at earlier tries
        claimChannel();
        return;
    }
    if (auto devPtr = m_target.lock()) {
        m_actualValveState = getValveState(devPtr);

        if (m_desiredValveState == ValveState::Closing && m_actualValveState == ValveState::Closed) {
            return; // leave motor driven
        }
        if (m_desiredValveState == ValveState::Opening && m_actualValveState == ValveState::Open) {
            return; // leave motor driven
        }

        if (m_actualValveState != m_desiredValveState) {
            applyValveState(m_desiredValveState, devPtr);
            m_actualValveState = getValveState(devPtr);
        }
    }
}

void MotorValve::claimChannel()
{
    if (auto devPtr = m_target.lock()) {
        if (m_startChannel != 0) {
            for (uint8_t i = 0; i < 4; ++i) {
                // release previous channels
                devPtr->setupChannel(m_startChannel + i, IoValue::Setup::Unused{});
            }
            m_startChannel = 0;
        }
        if (m_desiredChannel == 1 || m_desiredChannel == 5) { // only 2 valid options
            bool success = std::holds_alternative<IoValue::Setup::InputDigital>(devPtr->setupChannel(m_desiredChannel + chanIsClosed, IoValue::Setup::InputDigital{}));
            success = std::holds_alternative<IoValue::Setup::InputDigital>(devPtr->setupChannel(m_desiredChannel + chanIsOpen, IoValue::Setup::InputDigital{})) && success;
            success = std::holds_alternative<IoValue::Setup::OutputDigital>(devPtr->setupChannel(m_desiredChannel + chanOpeningHigh, IoValue::Setup::OutputDigital{})) && success;
            success = std::holds_alternative<IoValue::Setup::OutputDigital>(devPtr->setupChannel(m_desiredChannel + chanClosingHigh, IoValue::Setup::OutputDigital{})) && success;
            if (success) {
                m_startChannel = m_desiredChannel;
            } else {
                for (uint8_t i = 0; i < 4; ++i) {
                    devPtr->setupChannel(m_desiredChannel + i, IoValue::Setup::Unused{}); // cancel all channels again
                }
            }
        } else {
            m_desiredChannel = 0;
        }
    }
}
