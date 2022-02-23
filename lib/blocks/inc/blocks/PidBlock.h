/*
 * Copyright 2020 BrewPi B.V.
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

#include "blocks/Block.h"
#include "cbox/CboxPtr.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/IntervalHelper.h"
#include "control/Pid.h"

class PidBlock : public Block<brewblox_BlockType_Pid> {
private:
    cbox::CboxPtr<SetpointSensorPair> input;
    cbox::CboxPtr<ActuatorAnalogConstrained> output;

    Pid pid;
    IntervalHelper<1000> m_intervalHelper;
    bool previousActive = false;

public:
    PidBlock();
    virtual ~PidBlock() = default;

    virtual cbox::CboxError streamFrom(cbox::DataIn& in) override final;
    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError
    streamPersistedTo(cbox::DataOut& out) const override final;

    virtual cbox::update_t
    update(const cbox::update_t& now) override final;
    virtual void*
    implements(const cbox::obj_type_t& iface) override final;

    Pid&
    get()
    {
        return pid;
    }

    const Pid&
    get() const
    {
        return pid;
    }

    const auto&
    getInputLookup() const
    {
        return input;
    }

    const auto&
    getOutputLookup() const
    {
        return output;
    }
};
