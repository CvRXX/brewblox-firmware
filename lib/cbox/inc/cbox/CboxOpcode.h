/*
 * Copyright 2018 Elco Jacobs / Brewblox
 *
 * This file is part of Brewblox
 *
 * Brewblox is free software: you can redistribute it and/or modify
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
#include <cstdint>

namespace cbox {

enum class CboxOpcode : uint8_t {
    NONE = 0,
    READ_OBJECT = 1,
    WRITE_OBJECT = 2,
    CREATE_OBJECT = 3,
    DELETE_OBJECT = 4,
    LIST_OBJECTS = 5,
    READ_STORED_OBJECT = 6,
    LIST_STORED_OBJECTS = 7,
    CLEAR_OBJECTS = 8,
    REBOOT = 9,
    FACTORY_RESET = 10,
    LIST_COMPATIBLE_OBJECTS = 11,
    DISCOVER_OBJECTS = 12,
    FIRMWARE_UPDATE = 100,
};

inline uint8_t
asUint8(CboxOpcode e)
{
    return static_cast<uint8_t>(e);
}

} // end namespace cbox
