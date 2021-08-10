
/*
 * Copyright 2018 Elco Jacobs / BrewBlox, based on earlier work of Matthew McGowan
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

#include "Object.h"
#include "ObjectContainer.h"
#include <functional>
#include <memory>
#include <tuple>
#include <vector>

namespace cbox {

// An object factory combines the create function with a type ID.
// They can be put in a container that can be walked to find the matching typeId
// The container keeps the objects as shared pointer, so it can create weak pointers to them.
// Therefore the factory creates a shared pointer right away to only have one allocation.
struct ObjectFactoryEntry {
    obj_type_t typeId;
    std::function<std::shared_ptr<Object>(ObjectContainer&)> createFn;

    ObjectFactoryEntry(const obj_type_t& id, std::function<std::shared_ptr<Object>(ObjectContainer&)>&& fn)
        : typeId(id)
        , createFn(std::move(fn))
    {
    }

    ObjectFactoryEntry(const obj_type_t& id, std::function<std::shared_ptr<Object>()>&& fn)
        : typeId(id)
        , createFn([f = std::move(fn)](ObjectContainer&) { return f(); })
    {
    }
};

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

    std::tuple<CboxError, std::shared_ptr<Object>> make(ObjectContainer& objects, const obj_type_t& t) const;
};

} // end namespace cbox
