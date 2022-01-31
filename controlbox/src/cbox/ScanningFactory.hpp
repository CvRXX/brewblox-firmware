
/*
 * Copyright 2018 Elco Jacobs / Brewblox, based on earlier work of Matthew McGowan
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

/**
 * A scanning factory has some kind of scan mechanism for new objects.
 * It has a reference to the object container to check if the new object already exists
 */
class ScanningFactory {
public:
    ScanningFactory() = default;
    virtual ~ScanningFactory() = default;

    // scan takes the existing object container to be able to check if the object already exists
    virtual std::shared_ptr<Object> scan(ObjectContainer& objects) = 0;

    obj_id_t scanAndAdd(ObjectContainer& objects)
    {
        if (auto newObj = scan(objects)) {
            return objects.add(std::move(newObj), uint8_t(0x01)); // default to first profile
        }
        return 0;
    }
};

} // end namespace cbox
