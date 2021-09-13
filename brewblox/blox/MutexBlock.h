/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of BrewBlox.
 *
 * BrewBlox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewBlox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewBlox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "ActuatorDigitalConstrained.h"
#include "Block.h"

class MutexBlock : public Block<BrewBloxTypes_BlockType_Mutex> {
private:
    MutexTarget m_mutex;

public:
    MutexBlock() = default;
    virtual ~MutexBlock() = default;

    virtual cbox::CboxError streamFrom(cbox::DataIn& dataIn) override final;
    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final
    {
        return streamTo(out);
    }

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return update_never(now);
    }

    virtual void* implements(const cbox::obj_type_t& iface) override final;

    MutexTarget&
    getMutex()
    {
        return m_mutex;
    }
};
