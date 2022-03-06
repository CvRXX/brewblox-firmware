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

#include "AppTicks.h"
#include "blocks/Block.h"
#include "blocks/TicksBlock.h"
#include "cbox/CboxPtr.h"
#include "control/SetpointProfile.h"
#include "control/SetpointSensorPair.h"

class SetpointProfileBlock : public Block<brewblox_BlockType_SetpointProfile> {
private:
    cbox::CboxPtr<TicksBlock<TicksClass>> ticksPtr;
    cbox::CboxPtr<SetpointSensorPair> target;
    SetpointProfile profile;

public:
    SetpointProfileBlock()
        : ticksPtr(3)
        , profile(target.lockFunctor())
    {
    }

    using Point = SetpointProfile::Point;

    virtual ~SetpointProfileBlock() = default;

    virtual cbox::CboxError read(cbox::Command& cmd) const override final;
    virtual cbox::CboxError readPersisted(cbox::Command& cmd) const override final;
    virtual cbox::CboxError write(cbox::Command& cmd) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(const cbox::obj_type_t& iface) override final;

    SetpointProfile& get()
    {
        return profile;
    }
};
