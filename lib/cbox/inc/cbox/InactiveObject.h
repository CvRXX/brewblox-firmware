/*
 * Copyright 2018 Elco Jacobs / Brewblox, based on earlier work of Matthew McGowan
 *
 * This file is part of ControlBox.
 *
 * Controlbox is free software: you can redistribute it and/or modify
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
 * along with Controlbox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/CboxError.h"
#include "cbox/ObjectBase.h"
#include "cbox/ObjectIds.h"
#include <limits>

namespace cbox {

/**
 * An object that does nothing. When read, it returns the type it becomes when it is activated.
 */
class InactiveObject : public ObjectBase<std::numeric_limits<uint16_t>::max()> {
private:
    obj_type_t actualType;

public:
    InactiveObject(obj_type_t type)
        : actualType(type)
    {
    }
    virtual ~InactiveObject() = default;

    virtual CboxError streamTo(DataOut& out) const override final
    {
        out.put(actualType);
        return CboxError::OK;
    }

    virtual CboxError streamFrom(DataIn&) override final
    {
        return CboxError::OK;
    }

    virtual CboxError streamPersistedTo(DataOut&) const override final
    {
        return CboxError::PERSISTING_TO_INACTIVE_OBJECT; // inactive objects are never persisted
    }

    virtual update_t update(const update_t& now) override final
    {
        return update_never(now);
    }

    obj_type_t actualTypeId()
    {
        return actualType;
    }
};

} // end namespace cbox
