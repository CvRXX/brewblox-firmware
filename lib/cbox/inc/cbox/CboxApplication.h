/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 Brewblox / Elco Jacobs
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

#include "cbox/ObjectContainer.h"
#include <memory>

namespace cbox {

const obj_id_t userStartId(100);

extern ObjectContainer objects;

// must be implemented in application code
std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t);

// must be implemented in application code
std::shared_ptr<Object> scan();

// must be implemented in application code
ObjectStorage& getStorage();

} // end namespace cbox
