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
#include "control/IntervalHelper.hpp"
#include "control/SetpointSensorPair.hpp"

class SetpointSensorPairBlock : public Block<brewblox_BlockType_SetpointSensorPair> {
private:
    cbox::CboxPtr<TempSensor> sensor;
    SetpointSensorPair pair;
    IntervalHelper<1000> m_intervalHelper;

public:
    SetpointSensorPairBlock()
        : pair(sensor.lockFunctor())
    {
    }

    virtual ~SetpointSensorPairBlock() = default;

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(cbox::obj_type_t iface) override final;

    SetpointSensorPair& get()
    {
        return pair;
    }

    const SetpointSensorPair& get() const
    {
        return pair;
    }
};
