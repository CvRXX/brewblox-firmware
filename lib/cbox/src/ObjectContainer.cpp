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

#include "cbox/ObjectContainer.hpp"
#include "cbox/Application.hpp"
#include <algorithm>
#include <iterator>

namespace cbox {

std::pair<ObjectContainer::Iterator, ObjectContainer::Iterator> ObjectContainer::findPosition(obj_id_t id)
{
    // equal_range is used instead of find, because it is faster for a sorted container
    // the returned pair can be used as follows:
    // first == second means not found, first points to the insert position for the new object id
    // first != second means the object is found and first points to it

    struct IdLess {
        bool operator()(const std::shared_ptr<Object>& c, const obj_id_t& i) const { return c->objectId() < i; }
        bool operator()(const obj_id_t& i, const std::shared_ptr<Object>& c) const { return i < c->objectId(); }
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
    return std::max(startId, contained.empty() ? startId : obj_id_t(contained.back()->objectId() + 1));
}

CboxExpected<std::shared_ptr<Object>> ObjectContainer::fetch(obj_id_t id)
{
    auto p = findPosition(id);
    if (p.first == p.second) {
        return tl::make_unexpected(CboxError::INVALID_BLOCK_ID);
    } else {
        return *p.first;
    }
}

CboxError ObjectContainer::add(const std::shared_ptr<Object>& obj, obj_id_t id)
{
    if (!obj) {
        return CboxError::INVALID_BLOCK;
    }

    if (id != invalidId && id < startId) {
        return CboxError::INVALID_BLOCK_ID;
    }

    obj_id_t newId;
    Iterator position;

    if (id == invalidId) { // use 0 to let the container assign a free slot
        newId = nextId();
        position = contained.end();
    } else {
        // find insert position
        auto p = findPosition(id);
        if (p.first != p.second) { // refuse to overwrite existing objects
            return CboxError::INVALID_BLOCK_ID;
        }
        newId = id;
        position = p.first;
    }

    // Make obj aware of its ID
    obj->setObjectId(newId);

    // insert new entry in container in sorted position
    contained.insert(position, obj);
    return CboxError::OK;
}

CboxError ObjectContainer::remove(obj_id_t id)
{
    if (id < startId) {
        return CboxError::BLOCK_NOT_DELETABLE; // refuse to remove system objects
    }
    // find existing object
    auto p = findPosition(id);
    contained.erase(p.first, p.second); // doesn't remove anything if no objects found (first == second)
    return p.first == p.second ? CboxError::INVALID_BLOCK_ID : CboxError::OK;
}

// remove all non-system objects from the container
void ObjectContainer::clear()
{
    // Objects can perform lookups during their destructor.
    // Copy removed objects to `temp` to ensure that `contained` is empty
    // before any objects are destructed.
    decltype(contained) temp(
        std::make_move_iterator(findPosition(startId).first),
        std::make_move_iterator(contained.end()));
    contained.erase(userbegin(), cend());
    contained.shrink_to_fit();
}

// remove all objects from the container
void ObjectContainer::clearAll()
{
    // Objects can perform lookups during their destructor.
    // Swap objects to `temp` to ensure that `contained` is empty
    // before any objects are destructed.
    decltype(contained) temp;
    contained.swap(temp);
}

void ObjectContainer::update(update_t now)
{
    for (auto& obj : contained) {
        obj->update(now);
    }
}

void ObjectContainer::forcedUpdate(update_t now)
{
    for (auto& obj : contained) {
        obj->forcedUpdate(now);
    }
}

CboxError ObjectContainer::store(obj_id_t id)
{
    auto fetched = fetch(id);
    if (!fetched) {
        return fetched.error();
    }

    return fetched.value()->readStored([](const Payload& stored) {
        return getStorage().saveObject(stored);
    });
}

CboxError ObjectContainer::reloadStored(obj_id_t id)
{
    auto fetched = fetch(id);
    if (!fetched) {
        return fetched.error();
    }

    return getStorage().loadObject(id, [&fetched](const Payload& stored) {
        return fetched.value()->write(stored);
    });
}

} // end namespace cbox
