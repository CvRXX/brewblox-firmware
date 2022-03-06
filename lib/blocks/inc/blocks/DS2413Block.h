/*
 * Copyright 2018 BrewPi B.V.
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

#include "blocks/Block.h"
#include "blocks/OneWireDeviceBlock.h"
#include "control/DS2413.h"

class OneWire;

class DS2413Block : public Block<brewblox_BlockType_DS2413>, public OneWireDeviceBlock {
private:
    DS2413 device;

public:
    DS2413Block()
        : OneWireDeviceBlock()
        , device(owBus.lockFunctor())
    {
    }

    DS2413Block(cbox::obj_id_t busId)
        : OneWireDeviceBlock(busId)
        , device(owBus.lockFunctor())
    {
    }

    DS2413Block(cbox::obj_id_t busId, const OneWireAddress& addr)
        : OneWireDeviceBlock(busId)
        , device(owBus.lockFunctor(), addr)
    {
    }

    virtual cbox::CboxError read(cbox::Command& cmd) const override final;
    virtual cbox::CboxError readPersisted(cbox::Command& cmd) const override final;
    virtual cbox::CboxError write(cbox::Command& cmd) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(const cbox::obj_type_t& iface) override final;

    DS2413& get()
    {
        return device;
    }
};
