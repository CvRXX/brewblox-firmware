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
#include "cbox/CboxClaimingPtr.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/SetpointProfile.hpp"
#include "control/SetpointSensorPair.hpp"

class SetpointProfileBlock final : public Block<brewblox_BlockType_SetpointProfile> {
private:
    cbox::CboxClaimingPtr<SetpointSensorPair> target;
    SetpointProfile profile;

public:
    SetpointProfileBlock()
        : profile(target)
    {
    }
    ~SetpointProfileBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

    SetpointProfile& get()
    {
        return profile;
    }

    const SetpointProfile& get() const
    {
        return profile;
    }
};
