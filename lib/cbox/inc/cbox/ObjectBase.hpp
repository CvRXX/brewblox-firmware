/*
 * Copyright 2018 Elco Jacobs / Brewblox, based on earlier work of Matthew McGowan
 *
 * This file is part of Brewblox.
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
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/Object.hpp"
#include <memory>
#include <type_traits>

namespace cbox {

template <uint16_t id>
class ObjectBase : public Object {
public:
    [[nodiscard]] static obj_type_t staticTypeId()
    {
#if !defined(PLATFORM_ID) || PLATFORM_ID == 3 // check that ID is unique if building for cross platform (tests)
        static auto uniqueId = throwIdNotUnique(id);
        return uniqueId;
#else
        return id;
#endif
    }

    /**
     * The application defined typeID for this object instance. Defined by derived class
     */
    [[nodiscard]] obj_type_t typeId() const override
    {
        return id;
    }

    [[nodiscard]] void* implements(obj_type_t iface) override
    {
        if (id == iface) {
            return this;
        }
        return nullptr;
    }
};

} // end namespace cbox
