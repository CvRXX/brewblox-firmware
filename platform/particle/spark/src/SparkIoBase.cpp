/*
 * Copyright 2019 BrewPi B.V.
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

#include "spark/SparkIoBase.hpp"
#include "control/ActuatorDigital.hpp"
#include "spark/Board.hpp"

namespace platform::particle {

// // generic ArrayIO interface
// IoValue::variant SparkIoBase::readChannelImpl(uint8_t channel) const
// {
//     auto pin = channelToPin(channel);
//     if (pin == static_cast<decltype(pin)>(-1)) {
//         return IoValue::Error::INVALID_CHANNEL;
//     }
//     return pinReadFast(pin) != 0 ? IoValue::Digital{State::Active} : IoValue::Digital{State::Inactive};
// }

// IoValue::variant SparkIoBase::writeChannelImpl(uint8_t channel, IoValue::variant val)
// {
//     auto pin = channelToPin(channel);
//     if (pin == static_cast<decltype(pin)>(-1)) {
//         return IoValue::Error::INVALID_CHANNEL;
//     }

//     if (auto* v = std::get_if<IoValue::Digital>(&val)) {
//         auto state = v->state();
//         if (state == IoValue::State::Active) {
//             pinSetFast(pin);
//             return IoValue::Digital{state};
//         } else if (state == IoValue::State::Inactive) {
//             pinResetFast(pin);
//             return IoValue::Digital{state};
//         }
//     }

//     return IoValue::Error::UNSUPPORTED_VALUE;
// }

} // end namespace platform::particle
