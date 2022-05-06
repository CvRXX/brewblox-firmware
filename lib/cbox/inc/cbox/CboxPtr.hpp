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
#include "cbox/ObjectBase.hpp"
#include "cbox/ObjectContainer.hpp"
#include "control/ControlPtr.hpp"
#include <memory>

namespace cbox {

class CboxPtrBase {
private:
    obj_id_t id;
    std::weak_ptr<Object> ptr;

public:
    obj_id_t getId() const;
    void setId(obj_id_t newId);

    CboxError store();

protected:
    explicit CboxPtrBase(const obj_id_t& id)
        : id(id)
    {
    }

    // The destructor does not have to be virtual
    ~CboxPtrBase() = default;

    std::shared_ptr<Object> lockObject();
};

template <typename T>
class CboxPtr final : public CboxPtrBase, public ControlPtr<T> {

public:
    explicit CboxPtr(const obj_id_t& id = 0)
        : CboxPtrBase(id)
    {
    }
    ~CboxPtr() = default;

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

    std::shared_ptr<T> lock() override
    {
        return lock_as<T>();
    }

    std::shared_ptr<const T> lock() const override
    {
        return const_lock_as<T>();
    }
};

} // end namespace cbox
