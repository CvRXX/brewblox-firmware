/*
 * Copyright 2014-2021 BrewPi B.V. / Elco Jacobs
 * based on earlier work of Matthew McGowan.
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

#include "cbox/EepromDataStream.hpp"
#include "cbox/Crc.hpp"
#include <algorithm>

namespace cbox {

bool DataOut::writeBuffer(const uint8_t* data, stream_size_t len)
{
    const uint8_t* d = data;
    while (len-- > 0) {
        if (!write(*d++))
            return false;
    }
    return true;
}

bool DataIn::readBytes(uint8_t* t, stream_size_t length)
{
    uint8_t* target = t;
    while (length-- > 0) {
        auto v = read();
        if (v < 0) {
            return false;
        }
        *target++ = v;
    }
    return true;
}

CboxError DataIn::push(DataOut& out, stream_size_t length)
{
    while (length-- > 0) {
        auto v = read();
        if (v < 0) {
            return CboxError::NETWORK_READ_ERROR;
        }
        if (!out.write(v)) {
            return CboxError::NETWORK_WRITE_ERROR;
        }
    }
    return CboxError::OK;
}

CboxError DataIn::push(DataOut& out)
{
    while (true) {
        auto v = read();
        if (v < 0) {
            // stream is empty or error
            // we don't know the expected length, so we assume this was expected
            return CboxError::OK;
        }
        if (!out.write(v)) {
            return CboxError::NETWORK_WRITE_ERROR;
        }
    }
}

} // end namespace cbox
