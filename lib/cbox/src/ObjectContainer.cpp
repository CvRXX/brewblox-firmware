/*
 * Copyright 2018 Elco Jacobs / Brewblox
 *
 * This file is part of Brewblox
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

#include "cbox/ObjectContainer.h"
#include "cbox/Application.h"
#include "cbox/ObjectStream.h"
#include <algorithm>

namespace cbox {

std::pair<ObjectContainer::Iterator, ObjectContainer::Iterator> ObjectContainer::findPosition(obj_id_t id)
{
    // equal_range is used instead of find, because it is faster for a sorted container
    // the returned pair can be used as follows:
    // first == second means not found, first points to the insert position for the new object id
    // first != second means the object is found and first points to it

    struct IdLess {
        bool operator()(const ContainedObject& c, const obj_id_t& i) const { return c.id() < i; }
        bool operator()(const obj_id_t& i, const ContainedObject& c) const { return i < c.id(); }
    };

    auto pair = std::equal_range(
        contained.begin(),
        contained.end(),
        id,
        IdLess{});
    return pair;
}

obj_id_t ObjectContainer::nextId() const
{
    return std::max(startId, contained.empty() ? startId : ++obj_id_t(contained.back().id()));
}

ContainedObject* ObjectContainer::fetchContained(obj_id_t id)
{
    auto p = findPosition(id);
    if (p.first == p.second) {
        return nullptr;
    } else {
        return &(*p.first);
    }
}

const std::weak_ptr<Object> ObjectContainer::fetch(obj_id_t id)
{
    auto p = findPosition(id);
    if (p.first == p.second) {
        return std::weak_ptr<Object>(); // empty weak ptr if not found
    }
    return p.first->object(); // weak_ptr to found object
}

// create a new object with specific id, optionally replacing an existing object
obj_id_t ObjectContainer::add(std::shared_ptr<Object>&& obj, obj_id_t id, bool replace)
{
    obj_id_t newId;
    Iterator position;

    if (id == obj_id_t::invalid()) { // use 0 to let the container assign a free slot
        newId = nextId();
        position = contained.end();
    } else {
        if (id < startId) {
            return obj_id_t::invalid(); // refuse to add system objects
        }
        // find insert position
        auto p = findPosition(id);
        if (p.first != p.second) {
            // existing object found
            if (!replace) {
                return obj_id_t::invalid(); // refuse to overwrite existing objects
            }
        }
        newId = id;
        position = p.first;
    }

    if (replace) {
        *position = ContainedObject(newId, std::move(obj));
    } else {
        // insert new entry in container in sorted position
        contained.emplace(position, newId, std::move(obj));
    }
    return newId;
}

CboxError ObjectContainer::remove(obj_id_t id)
{
    if (id < startId) {
        return CboxError::OBJECT_NOT_DELETABLE; // refuse to remove system objects
    }
    // find existing object
    auto p = findPosition(id);
    contained.erase(p.first, p.second); // doesn't remove anything if no objects found (first == second)
    return p.first == p.second ? CboxError::INVALID_OBJECT_ID : CboxError::OK;
}

// remove all non-system objects from the container
void ObjectContainer::clear()
{
    contained.erase(userbegin(), cend());
}

// remove all objects from the container
void ObjectContainer::clearAll()
{
    contained.clear();
    contained.shrink_to_fit();
}

void ObjectContainer::update(update_t now)
{
    for (auto& cobj : contained) {
        cobj.update(now);
    }
}

void ObjectContainer::forcedUpdate(update_t now)
{
    for (auto& cobj : contained) {
        cobj.forcedUpdate(now);
    }
}

CboxError ObjectContainer::store(const obj_id_t& id)
{
    auto cobj = fetchContained(id);
    if (cobj == nullptr) {
        return CboxError::INVALID_OBJECT_ID;
    }

    auto storeContained = [&cobj, &id](DataOut& out) -> CboxError {
        return saveToStream(out, id, cobj->object());
    };
    return getStorage().storeObject(id, storeContained);
}

CboxError ObjectContainer::reloadStored(const obj_id_t& id)
{
    ContainedObject* cobj = fetchContained(id);
    if (cobj == nullptr) {
        return CboxError::INVALID_OBJECT_ID;
    }

    bool handlerCalled = false;
    auto streamHandler = [&cobj, &id, &handlerCalled](RegionDataIn& in) -> CboxError {
        handlerCalled = true;
        return loadFromStream(in, id, cobj->object());
    };
    CboxError status = getStorage().retrieveObject(storage_id_t(id), streamHandler);
    if (!handlerCalled) {
        return CboxError::INVALID_OBJECT_ID; // write status if handler has not written it
    }

    return status;
}

} // end namespace cbox
