/*
 * Copyright 2019 BrewPi B.V.
 *
 * This file is part of BrewBlox
 *
 * BrewBlox is free software: you can redistribute it and/or modify
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
 * along with BrewBlox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "../ExpOwGpio.hpp"
#include "blox/Block.h"
#include "blox/compiled_proto/src/OneWireGpioModule.pb.h"
#include <string>
#include <vector>

class ExpOwGpioBlock : public Block<BrewBloxTypes_BlockType_OneWireGpioModule> {
private:
    ExpOwGpio drivers;

public:
    ExpOwGpioBlock(uint8_t lower_address = 0xFF)
        : drivers(lower_address)
    {
        drivers.init();
    }

    virtual cbox::CboxError streamFrom(cbox::DataIn& in) override final;
    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;
    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(const cbox::obj_type_t& iface) override final;

private:
    void writeMessage(blox_OneWireGpioModule& message, bool includeNotPersisted) const;

    typedef struct {
        uint8_t id;
        std::string name;
    } ChannelNameEntry;
    std::vector<ChannelNameEntry> channelNames;
};
