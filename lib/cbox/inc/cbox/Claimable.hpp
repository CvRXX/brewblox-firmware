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

#include "cbox/Object.hpp"
#include <atomic>

namespace cbox {

class Claimable {
public:
    bool claim(obj_id_t requesterId)
    {
        if (requesterId == 0) {
            return false;
        }
        if (_claimedById == requesterId) {
            return true;
        }
        // allow claim if current claimer id is 0
        auto nullId = obj_id_t{0};
        return std::atomic_compare_exchange_weak(&_claimedById, &nullId, requesterId);
    }

    bool unclaim(obj_id_t requesterId)
    {
        // release if my id is the claimer
        return std::atomic_compare_exchange_weak(&_claimedById, &requesterId, obj_id_t{0});
    }

    obj_id_t claimedBy() const
    {
        return _claimedById;
    }

private:
    std::atomic<obj_id_t> _claimedById = 0;
};

} // end namespace cbox
