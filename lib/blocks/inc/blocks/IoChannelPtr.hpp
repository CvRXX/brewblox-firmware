/*
 * Copyright 2022 Elco Jacobs / Brewblox
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

#include "cbox/CboxClaimingPtr.hpp"
#include "control/IoArray.hpp"

// override CboxClaimingPtr for IoArray, where claims are not on the entire block, but per channel
// claiming is handled by IoArray itself, so no need here to manage the claim

namespace cbox {
template <>
class CboxClaimingPtr<IoArray> final : public ControlPtr<IoArray> {
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
        _claimerId = claimerId;
        _ptr.setId(targetId);
    }

    void setChannel(uint8_t channel)
    {
        if (channel == 0) {
            if (auto ptr = _ptr.lock()) {
                ptr->unclaimChannel(_claimerId, _channel);
            }
        }
        _channel = channel;
    }

    // locking as non-const requires a unique claim
    [[nodiscard]] std::shared_ptr<IoArray> lock() override
    {
        if (auto ptr = _ptr.lock()) {
            if (ptr->claimChannel(_claimerId, _channel)) {
                return ptr;
            }
        }
        return nullptr;
    };

    // locking as const is always allowed
    [[nodiscard]] std::shared_ptr<const IoArray> lock() const override
    {
        return _ptr.lock();
    };

    void release() override
    {
        if (auto ptr = _ptr.lock()) {
            ptr->unclaimChannel(_claimerId, _channel);
        }
    }

private:
    CboxPtr<IoArray> _ptr;
    obj_id_t _claimerId;
    uint8_t _channel = 0;
};
}

using IoChannelPtr = cbox::CboxClaimingPtr<IoArray>;
