/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 Brewblox / Elco Jacobs
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

#include "cbox/DataStream.h"
#include "cbox/hex_utility.h"
#include <string>

namespace cbox {

/*
 * A DataIn filter - wraps a DataIn instance and provides also a DataIn interface.
 * Filters out non-significant text - comment markers, whitespace, unrecognized characters.
 * The stream automatically closes on newline and hasNext() returns false.
 * Once a character has been received, the underlying stream is continually polled for characters until
 * the stream is closed by the newline.
 *
 * The result of this is that lines are polled non-blocking while no data is available, and when data is available
 * the stream blocks for each character until the entire line is read.
 */

#if 0 // unused currently. Comments in input not supported.
class TextIn : public DataIn {
    DataIn* _in;
    uint8_t data;
    bool hasData;
    bool inLine;
    int8_t commentLevel; // -1 indicates end of stream

    void fetchNextData(bool optional);

public:
    TextIn(DataIn& in)
        : _in(&in)
        , data(0)
        , hasData(0)
        , inLine(false)
        , commentLevel(0)
    {
    }

    bool hasNext() override
    {
        fetchNextData(true);
        return hasData;
    }

    uint8_t next() override
    {
        fetchNextData(false);
        hasData = false;
        return data;
    }

    uint8_t peek() override
    {
        fetchNextData(true);
        return data;
    }

    stream_size_t available() override
    {
        return hasNext();
    }

    bool isClosed()
    {
        return commentLevel < 0;
    }
};
#endif

} // end namespace cbox
