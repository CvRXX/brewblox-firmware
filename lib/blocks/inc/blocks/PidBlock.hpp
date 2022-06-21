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

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/ActuatorAnalog.hpp"
#include "control/IntervalHelper.hpp"
#include "control/Pid.hpp"

class PidBlock final : public Block<brewblox_BlockType_Pid> {
private:
    cbox::CboxPtr<SetpointSensorPair> input;
    cbox::CboxPtr<ProcessValue<Pid::out_t>> output;

    Pid pid;
    IntervalHelper<1000> m_intervalHelper;
    bool previousActive = false;
    cbox::update_t lastCacheTime{0};

public:
    PidBlock()
        : pid(input, output)
    {
    }

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::CboxError loadFromCache() override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    Pid& get()
    {
        return pid;
    }

    const Pid& get() const
    {
        return pid;
    }

    const auto& getInputLookup() const
    {
        return input;
    }

    const auto& getOutputLookup() const
    {
        return output;
    }
};
