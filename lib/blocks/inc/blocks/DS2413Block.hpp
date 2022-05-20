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

#include "blocks/Block.hpp"
#include "blocks/OneWireDeviceBlock.hpp"
#include "control/DS2413.hpp"

class OneWire;

class DS2413Block final : public Block<brewblox_BlockType_DS2413>, public OneWireDeviceBlock {
private:
    DS2413 device;

public:
    DS2413Block()
        : OneWireDeviceBlock(0)
        , device(busPtr())
    {
    }

    DS2413Block(cbox::obj_id_t busId)
        : OneWireDeviceBlock(busId)
        , device(busPtr())
    {
    }

    DS2413Block(cbox::obj_id_t busId, OneWireAddress addr)
        : OneWireDeviceBlock(busId)
        , device(busPtr(), std::move(addr))
    {
    }

    ~DS2413Block() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    DS2413& get()
    {
        return device;
    }
};
