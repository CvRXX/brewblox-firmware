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

#include "CboxPtr.h"

namespace cbox {

void CboxPtrBase::setId(obj_id_t newId)
{
    if (newId != id) {
        id = std::move(newId);
        ptr.reset();
    }
}

std::shared_ptr<Object> CboxPtrBase::lockObject()
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

} // end namespace cbox
