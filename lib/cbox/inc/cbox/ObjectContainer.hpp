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

#pragma once

#include "cbox/Object.hpp"
#include "cbox/ObjectStorage.hpp"
#include <vector>

namespace cbox {

constexpr obj_id_t systemStartId{1};
constexpr obj_id_t userStartId{100};
constexpr obj_id_t invalidId{0};

class ObjectContainer {
private:
    std::vector<std::shared_ptr<Object>> contained;
    obj_id_t startId = 1;

public:
    using Iterator = decltype(contained)::iterator;
    using CIterator = decltype(contained)::const_iterator;

    ObjectContainer() = default;
    virtual ~ObjectContainer() = default;

private:
    std::pair<Iterator, Iterator> findPosition(obj_id_t id);

    obj_id_t nextId() const;

public:
    CboxExpected<std::shared_ptr<Object>> fetch(obj_id_t id);

    /**
     * get start ID for user objects.
     * ID's smaller than the start ID are assumed to be system objects and considered undeletable.
     **/
    obj_id_t getObjectsStartId()
    {
        return startId;
    }

    /**
     * set start ID for user objects.
     * ID's smaller than the start ID are assumed to be system objects and considered undeletable.
     **/
    void setObjectsStartId(obj_id_t id)
    {
        startId = id;
    }

    // create a new object with specific id
    CboxError add(std::shared_ptr<Object> obj, obj_id_t id = invalidId);

    // force to pass an object pointer, not a derived shared::ptr
    // this creates code bloat. It is better to use shared_ptr<Object>(new Derived()) directly than to convert from shared_ptr<Derived>()
    template <class T>
    CboxError add(std::shared_ptr<T> obj, obj_id_t id = invalidId) = delete;

    // also catch passing unique_ptr, as this also results in unnecessary conversions
    CboxError add(std::unique_ptr<Object> obj, obj_id_t id = invalidId) = delete;

    CboxError remove(obj_id_t id);

    // only const iterators are exposed. We don't want the caller to be able to modify the container
    CIterator cbegin() const
    {
        return contained.cbegin();
    }

    CIterator cend() const
    {
        return contained.cend();
    }

    CIterator userbegin()
    {
        return findPosition(startId).first;
    }

    // remove all non-system objects from the container
    void clear();

    // remove all objects from the container
    void clearAll();

    void update(update_t now);

    void loadFromCache();

    void forcedUpdate(update_t now);

    CboxError store(obj_id_t id);

    CboxError reloadStored(obj_id_t id);
};

} // end namespace cbox
