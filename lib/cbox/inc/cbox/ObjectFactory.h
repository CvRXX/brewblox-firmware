
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

#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "tl/expected.hpp"
#include <functional>
#include <memory>
#include <tuple>
#include <vector>

namespace cbox {

template <typename T, std::enable_if_t<std::is_constructible<T>::value, std::nullptr_t> = nullptr>
Object* make()
{
    return new T();
}

// An object factory combines the create function with a type ID.
// They can be put in a container that can be walked to find the matching typeId
// The container keeps the objects as shared pointer, so it can create weak pointers to them.
// Factory entries generate a raw pointer to prevent std::shared_ptr template specialization for all entry types.
// The raw pointers are wrapped in a shared pointer by the factory.
struct ObjectFactoryEntry {
    obj_type_t typeId;
    Object* (*createFn)();

    ObjectFactoryEntry(const obj_type_t& id, Object* (*f)())
        : typeId(id)
        , createFn(f)
    {
    }

    template <class T>
    ObjectFactoryEntry(const obj_type_t& id)
        : typeId(id)
        , createFn(make<T>)
    {
    }
};

template <typename T>
ObjectFactoryEntry makeFactoryEntry()
{
    return ObjectFactoryEntry(T::staticTypeId(), make<T>);
}

class ObjectFactory {
private:
    const std::vector<ObjectFactoryEntry> objTypes;

    ObjectFactory(ObjectFactory&) = delete;
    ObjectFactory& operator=(ObjectFactory&) = delete;

public:
    ObjectFactory(std::initializer_list<ObjectFactoryEntry> _objTypes)
        : objTypes(_objTypes)
    {
    }

    CboxExpected<std::shared_ptr<Object>> make(const obj_type_t& t) const;
};

} // end namespace cbox
