/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
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
#include "control/TempSensor.hpp"
#include "control/TempSensorCombi.hpp"
#include "proto/TempSensorCombi.pb.h"
#include <vector>

class TempSensorCombiBlock : public Block<brewblox_BlockType_TempSensorCombi> {
private:
    TempSensorCombi sensor;
    std::vector<cbox::CboxPtr<TempSensor>> inputs;

public:
    TempSensorCombiBlock()
    {
    }

    virtual ~TempSensorCombiBlock() = default;

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t updateHandler(const cbox::update_t& now) override final;
    virtual void* implements(cbox::obj_type_t iface) override final;

    TempSensorCombi& get()
    {
        return sensor;
    }

private:
    void writeMessage(blox_TempSensorCombi_Block& message, bool includeReadOnly) const;
};
