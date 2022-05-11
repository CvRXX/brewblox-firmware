/*
 * Copyright 2019 BrewPi B.V.
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
#include "control/DS2408.hpp"
#include "proto/DS2408.pb.h"

class OneWire;

class DS2408Block final : public Block<brewblox_BlockType_DS2408>, public OneWireDeviceBlock {
private:
    DS2408 device;
    blox_DS2408_PinConnectMode connectMode = blox_DS2408_PinConnectMode_CONNECT_VALVE;

public:
    DS2408Block()
        : OneWireDeviceBlock()
        , device(owBus)
    {
    }

    DS2408Block(cbox::obj_id_t busId)
        : OneWireDeviceBlock(busId)
        , device(owBus)
    {
    }

    DS2408Block(cbox::obj_id_t busId, const OneWireAddress& addr)
        : OneWireDeviceBlock(busId)
        , device(owBus, addr)
    {
    }

    ~DS2408Block() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    DS2408& get()
    {
        return device;
    }
};
