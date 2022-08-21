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

#pragma once

#include "blocks/Block.hpp"
#include "control/IoArray.hpp"
#include "control/TimerInterrupts.hpp"

namespace platform::particle {

class Spark2PinsBlock final : public IoArray, public Block<brewblox_BlockType_Spark2Pins> {
public:
    Spark2PinsBlock()
        : IoArray(4)
    {
#if PLATFORM_ID != 3
        if (!myInterrupt) {
            myInterrupt = TimerInterrupts::add(timerTask);
        }
#endif
    }
    ~Spark2PinsBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    void* implements(cbox::obj_type_t iface) override;

    static void timerTask();

    // generic ArrayIO interface
    IoValue::variant readChannelImpl(uint8_t channel) const override;
    IoValue::variant writeChannelImpl(uint8_t channel, IoValue::variant val) override;
    IoValue::Setup::variant setupChannelImpl(uint8_t channel, IoValue::Setup::variant setup) override;

    IoArray::ChannelCapabilities getChannelCapabilities(uint8_t /*channel*/) const override
    {
        return ChannelCapabilities{.flags{
            .digitalOutput = 1,
            .pwm100Hz = 1,
        }};
    }
    static int16_t myInterrupt;
};

} // end namespace platform::particle
