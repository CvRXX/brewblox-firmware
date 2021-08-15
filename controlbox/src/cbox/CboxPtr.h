/*
 * Copyright 2018 Elco Jacobs / BrewBlox
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
#include <memory>

namespace cbox {

class CboxPtrBase {
private:
    obj_id_t id;
    ObjectContainer& objects;
    std::weak_ptr<Object> ptr;

public:
    void setId(obj_id_t newId)
    {
        if (newId != id) {
            id = std::move(newId);
            ptr.reset();
        }
    }

    obj_id_t getId() const
    {
        return id;
    }

    CboxError store()
    {
        return objects.store(id);
    }

    ObjectContainer& container()
    {
        return objects;
    }

protected:
    explicit CboxPtrBase(ObjectContainer& objects, const obj_id_t& id)
        : id(id)
        , objects(objects)
    {
    }
    ~CboxPtrBase() = default;

    std::shared_ptr<Object> lockObject()
    {
        // try to lock the weak pointer we already had. If it cannot be locked, we need to do a lookup again
        auto sptr = ptr.lock();
        if (!sptr) {
            // Try to find the object in the container
            ptr = objects.fetch(id);
            sptr = ptr.lock();
        }
        return sptr;
    }
};

template <typename T>
class CboxPtr : public CboxPtrBase {

public:
    explicit CboxPtr(ObjectContainer& objects, const obj_id_t& id = 0)
        : CboxPtrBase(objects, id)
    {
    }
    ~CboxPtr() = default;

    std::shared_ptr<T> lock()
    {
        return lock_as<T>();
    }

    template <class U>
    std::shared_ptr<U> lock_as()
    {
        if (auto sptr = lockObject()) {
            // if the lookup succeeded, check if the Object implements the requested interface using the interface id
            // If the object returned a non-zero pointer, it supports the interface
            // If multiple-inheritance is involved, it is possible that the shared pointer and interface pointer
            // do not point to the same address. The pointer that is returned is of the address that implements
            // the interface.
            // create a shared_ptr by re-using the ref counting block, but for the offset pointer.
            return std::shared_ptr<U>(std::move(sptr), reinterpret_cast<U*>(sptr->implements(interfaceId<U>())));
        }
        // return empty share pointer
        return std::shared_ptr<U>();
    }

    template <class U>
    std::shared_ptr<const U> const_lock_as() const
    {
        auto this_non_const = const_cast<CboxPtr<T>*>(this);
        auto sptr = this_non_const->template lock_as<U>();
        return std::const_pointer_cast<const U>(std::move(sptr));
    }

    std::shared_ptr<const T> const_lock() const
    {
        return const_lock_as<T>();
    }

    std::function<std::shared_ptr<T>()> lockFunctor()
    {
        return [this]() { return this->lock(); };
    }

    std::function<std::shared_ptr<const T>()> lockFunctor() const
    {
        return [this]() { return this->const_lock(); };
    }
};

} // end namespace cbox
