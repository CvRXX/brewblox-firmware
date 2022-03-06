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

#include "cbox/ContainedObject.h"
#include "cbox/ObjectStorage.h"
#include <vector>

namespace cbox {

class ObjectContainer {
private:
    std::vector<ContainedObject> contained;
    obj_id_t startId = obj_id_t::start();

public:
    using Iterator = decltype(contained)::iterator;
    using CIterator = decltype(contained)::const_iterator;

    ObjectContainer()
        : contained{}
    {
    }

    ObjectContainer(std::initializer_list<ContainedObject> objects_)
        : contained{objects_}
    {
    }

    virtual ~ObjectContainer() = default;

private:
    std::pair<Iterator, Iterator> findPosition(obj_id_t id);

    obj_id_t nextId() const;

public:
    ContainedObject* fetchContained(obj_id_t id);
    const std::weak_ptr<Object> fetch(obj_id_t id);

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

    void init(std::initializer_list<ContainedObject> objects_)
    {
        contained = std::move(decltype(contained)(objects_));
    }

    // create a new object and let box assign id
    obj_id_t add(std::shared_ptr<Object>&& obj)
    {
        return add(std::move(obj), obj_id_t::invalid());
    }

    // create a new object with specific id, optionally replacing an existing object
    obj_id_t add(std::shared_ptr<Object>&& obj, obj_id_t id, bool replace = false);

    // force to pass an object pointer, not a derived shared::ptr
    // this creates code bloat. It is better to use shared_ptr<Object>(new Derived()) directly than to convert from make_shared<Derived>()
    template <class T>
    obj_id_t add(std::shared_ptr<Object>&& obj, obj_id_t id = 0, bool replace = false) = delete;

    // also catch passing unique_ptr, as this also results in unnecessary conversions
    template <class T>
    obj_id_t add(std::unique_ptr<T>&& obj, obj_id_t id = 0, bool replace = false) = delete;

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

    void forcedUpdate(update_t now);

    CboxError store(const obj_id_t& id);

    CboxError reloadStored(const obj_id_t& id);
};

} // end namespace cbox
