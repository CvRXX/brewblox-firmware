/*
 * Copyright 2018 Elco Jacobs / Brewblox
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

#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "cbox/ObjectBase.hpp"
#include "cbox/ObjectContainer.hpp"
#include "control/ControlPtr.hpp"
#include <memory>

namespace cbox {

class CboxPtrBase {
private:
    obj_id_t id;
    mutable std::weak_ptr<Object> ptr;

public:
    [[nodiscard]] obj_id_t getId() const
    {
        return id;
    }

    void setId(obj_id_t newId)
    {
        if (newId != id) {
            id = newId;
            ptr.reset();
        }
    }

    CboxError store()
    {
        return objects.store(id);
    }

protected:
    explicit CboxPtrBase(const obj_id_t& id)
        : id(id)
    {
    }

    CboxPtrBase(CboxPtrBase&&) = default;
    // Don't allow destruction with a base class ptr
    ~CboxPtrBase() = default;

    std::shared_ptr<Object> lockObject() const
    {
        // try to lock the weak pointer we already had. If it cannot be locked, we need to do a lookup again
        auto sptr = ptr.lock();
        if (!sptr) {
            // Try to find the object in the container
            if (auto fetched = objects.fetch(id)) {
                sptr = fetched.value();
                ptr = fetched.value();
            }
        }
        return sptr;
    }

public:
    CboxPtrBase(const CboxPtrBase&) = delete;
    CboxPtrBase& operator=(const CboxPtrBase&) = delete;
    CboxPtrBase& operator=(CboxPtrBase&&) = default;
};

template <typename T>
class CboxPtr final : public CboxPtrBase, public ControlPtr<T> {

public:
    explicit CboxPtr(const obj_id_t& id = 0)
        : CboxPtrBase(id)
    {
    }
    ~CboxPtr() = default;

    CboxPtr(const CboxPtr&) = delete;
    CboxPtr(CboxPtr&&) = default;
    CboxPtr& operator=(const CboxPtr&) = delete;
    CboxPtr& operator=(CboxPtr&&) = default;

    template <class U>
    [[nodiscard]] std::shared_ptr<U> lock_as()
    {
        if (auto sptr = lockObject()) {
            // if the lookup succeeded, check if the CboxPtr implements the requested interface using the interface id
            // If the object returned a non-zero pointer, it supports the interface
            // If multiple-inheritance is involved, it is possible that the shared pointer and interface pointer
            // do not point to the same address. The pointer that is returned is of the address that implements
            // the interface.
            // create a shared_ptr by re-using the ref counting block, but for the offset pointer.
            return std::shared_ptr<U>(std::move(sptr), sptr->asInterface<U>());
        }
        // return empty share pointer
        return {};
    }

    template <class U>
    [[nodiscard]] std::shared_ptr<const U> lock_as() const
    {
        if (auto sptr = lockObject()) {
            return std::shared_ptr<const U>(std::move(sptr), sptr->asInterface<U>());
        }
        return {};
    }

    [[nodiscard]] std::shared_ptr<T> lock() override
    {
        return lock_as<T>();
    }

    [[nodiscard]] std::shared_ptr<const T> lock() const override
    {
        return lock_as<T>();
    }
};

} // end namespace cbox
