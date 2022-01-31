/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 BrewBlox / Elco Jacobs
 *
 * This file is part of Controlbox.
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

#include "DataStream.h"
#include "b64_utility.h"
#include "hex_utility.h"
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

/*
 * Converts pairs of hex digit characters into the corresponding binary value.
 */
class HexTextToBinaryIn : public DataIn {
    DataIn& textIn;
    int16_t upper = -1;
    int16_t lower = -1;

public:
    HexTextToBinaryIn(DataIn& _textIn)
        : textIn(_textIn)
    {
    }

    void fetch()
    {
        if (upper < 0) { // 2 bytes to fetch
            if (!isxdigit(textIn.peek())) {
                return; // leave non-hex characters in the stream
            }
            upper = textIn.read();
            if (upper < 0) {
                // no data
                return;
            }
        }

        if (lower < 0) {
            if (!isxdigit(textIn.peek())) {
                return; // leave non-hex characters in the stream
            }
            lower = textIn.read();
        }
    }

    virtual int16_t peek() override
    {
        fetch();
        if (!isxdigit(upper) || !isxdigit(lower)) {
            return -1;
        }
        return h2d(upper) * 16 + h2d(lower);
    }

    virtual int16_t read() override
    {
        auto v = peek();
        if (v >= 0) {
            // valid value received, reset nibbles
            upper = -1;
            lower = -1;
        }
        return v;
    }

    void consumeNonHex()
    {
        // reset nibbles, because we want a fresh hex char after this function
        upper = -1;
        lower = -1;
        while (true) {
            auto v = textIn.peek();
            if (isxdigit(v)) {
                return; // next char is in hex range
            }
            if (v < 0) {
                // stream is empty
                return;
            }
            // consume
            textIn.read();
        }
    }

    virtual StreamType streamType() const override final
    {
        return textIn.streamType();
    }
};

class Base64TextToBinaryIn : public DataIn {
    DataIn& textIn;
    // 4 base64 bytes -> 3 raw bytes
    uint8_t bytesEncoded[4];
    uint8_t bytesDecoded[3];
    uint8_t readInIdx = 0;
    uint8_t readOutIdx = 0;

public:
    Base64TextToBinaryIn(DataIn& _textIn)
        : textIn(_textIn)
    {
    }

    void fetch()
    {
        while (readInIdx < 4) {
            if (!isbase64(textIn.peek())) {
                return;
            }

            auto inchar = textIn.read();
            if (inchar == '=') { // Partial group. Pad out the remaining bytes
                for (; readInIdx < 4; readInIdx++) {
                    bytesEncoded[readInIdx] = 0;
                }
            } else {
                bytesEncoded[readInIdx] = inchar;
                readInIdx++;
            }

            // We read an entire group. Now fill bytesDecoded
            if (readInIdx == 4) {
                for (auto i = 0; i < 4; i++) {
                    bytesEncoded[i] = base64chars.find(bytesEncoded[i]);
                }
                bytesDecoded[0] = (bytesEncoded[0] << 2) + ((bytesEncoded[1] & 0x30) >> 4);
                bytesDecoded[1] = ((bytesEncoded[1] & 0xf) << 4) + ((bytesEncoded[2] & 0x3c) >> 2);
                bytesDecoded[2] = ((bytesEncoded[2] & 0x3) << 6) + bytesEncoded[3];
            }
        }
    }

    virtual int16_t peek() override
    {
        fetch();
        if (readInIdx < 4) {
            return -1;
        }
        return bytesDecoded[readOutIdx];
    }

    virtual int16_t read() override
    {
        auto v = peek();
        if (v >= 0) {
            readOutIdx++;
            if (readOutIdx > 3) {
                // The entire byte group has been read, and must be refilled
                readInIdx = 0;
                readOutIdx = 0;
            }
        }
        return v;
    }

    virtual StreamType streamType() const override final
    {
        return textIn.streamType();
    }
};

} // end namespace cbox
