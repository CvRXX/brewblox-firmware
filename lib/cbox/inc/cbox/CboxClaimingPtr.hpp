/*
 * Copyright 2022 BrewPi B.V.
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

#include "CboxPtr.hpp"
#include "Claimable.hpp"
#include "Object.hpp"
#include "control/ControlPtr.hpp"
#include <atomic>
#include <memory>

namespace cbox {

template <typename T>
class CboxClaimingPtr final : public ControlPtr<T> {
public:
    explicit CboxClaimingPtr()
        : _ptr(0)
        , _claimerId(0)
    {
    }
    explicit CboxClaimingPtr(obj_id_t targetId, obj_id_t claimerId)
        : _ptr(targetId)
        , _claimerId(claimerId)
    {
    }
    ~CboxClaimingPtr()
    {
        release();
    }

    CboxClaimingPtr(const CboxClaimingPtr&) = delete;
    CboxClaimingPtr(CboxClaimingPtr&&) noexcept = default;
    CboxClaimingPtr& operator=(const CboxClaimingPtr&) = delete;
    CboxClaimingPtr& operator=(CboxClaimingPtr&&) noexcept = default;

    [[nodiscard]] obj_id_t getId() const
    {
        return _ptr.getId();
    }

    void setId(obj_id_t targetId, obj_id_t claimerId)
    {
        if (claimerId != _claimerId || targetId != _ptr.getId()) {
            release();
        }
        _claimerId = claimerId;
        _ptr.setId(targetId);
    }

    // locking as non-const requires a unique claim
    [[nodiscard]] std::shared_ptr<T> lock() override
    {
        if (auto ptr = _ptr.template lock_as<Claimable>()) {
            if (ptr->claim(_claimerId)) {
                return _ptr.lock();
            }
        }
        return nullptr;
    };

    // locking as const is always allowed
    [[nodiscard]] std::shared_ptr<const T> lock() const override
    {
        return _ptr.lock();
    };

    void release() override
    {
        if (auto claimTarget = _ptr.template lock_as<Claimable>()) {
            claimTarget->unclaim(_claimerId);
        }
    };

    CboxError store() const
    {
        return _ptr.store();
    }

    template <class U>
    [[nodiscard]] std::shared_ptr<U> lock_as()
    {
        return _ptr.template lock_as<U>();
    }

    template <class U>
    [[nodiscard]] std::shared_ptr<const U> lock_as() const
    {
        return _ptr.template lock_as<U>();
    }

private:
    CboxPtr<T> _ptr;
    obj_id_t _claimerId;
};

} // end namespace cbox
