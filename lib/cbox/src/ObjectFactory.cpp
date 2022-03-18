
/*
 * Copyright 2018 Elco Jacobs / Brewblox, based on earlier work of Matthew McGowan
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

#include "cbox/ObjectFactory.hpp"
#include <algorithm>

namespace cbox {

CboxExpected<std::shared_ptr<Object>> ObjectFactory::make(obj_type_t t) const
{
    auto factoryEntry = std::find_if(objTypes.begin(), objTypes.end(), [&t](const ObjectFactoryEntry& entry) { return entry.typeId == t; });
    if (factoryEntry == objTypes.end()) {
        return tl::make_unexpected(CboxError::BLOCK_NOT_CREATABLE);
    }
    auto obj = factoryEntry->createFn();
    if (!obj) {
        return tl::make_unexpected(CboxError::INSUFFICIENT_HEAP);
    }

    return std::shared_ptr<Object>(obj);
}

} // end namespace cbox
