/*
 * Copyright 2018 Elco Jacobs / Brewblox
 *
 * This file is part of Brewblox
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
#include <cstdint>

namespace cbox {

enum class CboxError : uint8_t {
    OK = 0,
    UNKNOWN_ERROR = 1,
    INVALID_OPCODE = 2,

    // Memory errors
    INSUFFICIENT_HEAP = 4,
    INSUFFICIENT_STORAGE = 5,

    // Network I/O errors
    NETWORK_ERROR = 10,
    NETWORK_READ_ERROR = 11,
    NETWORK_DECODING_ERROR = 12,
    NETWORK_WRITE_ERROR = 13,
    NETWORK_ENCODING_ERROR = 14,

    // Storage I/O errors
    STORAGE_ERROR = 20,
    STORAGE_READ_ERROR = 21,
    STORAGE_DECODING_ERROR = 22,
    STORAGE_CRC_ERROR = 23,
    STORAGE_WRITE_ERROR = 24,
    STORAGE_ENCODING_ERROR = 25,

    // Invalid actions
    BLOCK_NOT_WRITABLE = 30,
    BLOCK_NOT_READABLE = 31,
    BLOCK_NOT_CREATABLE = 32,
    BLOCK_NOT_DELETABLE = 33,

    // Invalid block data
    INVALID_BLOCK = 40,
    INVALID_BLOCK_ID = 41,
    INVALID_BLOCK_TYPE = 42,
    INVALID_BLOCK_SUBTYPE = 43,
    INVALID_BLOCK_CONTENT = 44,

    // Invalid stored block data
    INVALID_STORED_BLOCK = 50,
    INVALID_STORED_BLOCK_ID = 51,
    INVALID_STORED_BLOCK_TYPE = 52,
    INVALID_STORED_BLOCK_SUBTYPE = 53,
    INVALID_STORED_BLOCK_CONTENT = 54,

    // Internal
    BLOCK_NOT_STORED = 200,
};

inline uint8_t
asUint8(CboxError e)
{
    return static_cast<uint8_t>(e);
}

} // end namespace cbox
