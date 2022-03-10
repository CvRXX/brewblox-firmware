
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

#pragma once

#include "cbox/Application.h"
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
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
    virtual std::shared_ptr<Object> scan() = 0;
};

} // end namespace cbox
