/*
 * Copyright 2014-2020 BrewPi B.V. / Elco Jacobs
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

#pragma once

#include "cbox/CboxError.hpp"
#include <cstdint>
#include <string>

namespace cbox {

using stream_size_t = size_t;

/**
 * An output stream that supports writing data.
 * This is the base class for raw streams that do not encode their bytes as 2 hex characters
 */
class DataOut {
public:
    DataOut() = default;
    virtual ~DataOut() = default;

    /**
     * Writes a byte to the stream.
     * @return {@code true} if the byte was successfully written, false otherwise.
     */
    virtual bool write(uint8_t data) = 0;

    template <typename T>
    bool put(const T& t)
    {
        auto p = reinterpret_cast<const uint8_t*>(std::addressof(t));
        return writeBuffer(p, sizeof(T));
    }

    /**
     * Writes a number of bytes to the stream.
     * @param data	The address of the data to write.
     * @param len	The number of bytes to write.
     * @return {@code true} if the byte was successfully written, false otherwise.
     */
    virtual bool writeBuffer(const uint8_t* data, stream_size_t len);

    inline bool writeBuffer(const char* data, stream_size_t len)
    {
        return writeBuffer(reinterpret_cast<const uint8_t*>(data), len);
    }
};

enum class StreamType : uint8_t {
    Mock = 0,
    Usb = 1,
    Tcp = 2,
    Eeprom = 3,
    File = 4,
};

/**
 * A data input stream. Byte based, but returns int16_t to be able to return negative values for error conditions
 */
class DataIn {
public:
    virtual ~DataIn() = default;
    /**
     * Retrieves the next byte of data. The return value is -1 if no data is available.
     */
    virtual int16_t read() = 0;

    /**
     * Retrieves the next byte of data without removing it from the stream. -1 when no data is availabe.
     */
    virtual int16_t peek() = 0;

    /**
     * Discards all data until no new data is available
     */
    void spool()
    {
        while (read() >= 0) {
            ;
        }
    }

    /**
     * Read of {@code length} bytes.
     */
    bool readBytes(uint8_t* t, stream_size_t length);

    template <typename T>
    bool get(T& t)
    {
        return readBytes(reinterpret_cast<uint8_t*>(&t), sizeof(T));
    }

    /**
     * Writes the contents of this stream to an output stream.
     * @param out
     * @param length
     * @return CboxError
     */
    CboxError push(DataOut& out, stream_size_t length);

    /**
     * Writes the contents of this stream to an output stream, until input stream is empty
     * @param out
     * @return CboxError
     */
    CboxError push(DataOut& out);

    virtual StreamType streamType() const = 0;
};

/**
 * Limits reading from the stream to the given number of bytes.
 */
class RegionDataIn : public DataIn {
    DataIn& in;
    stream_size_t len;

public:
    RegionDataIn(DataIn& _in, stream_size_t _len)
        : in(_in)
        , len(_len)
    {
    }
    virtual ~RegionDataIn() = default;

    int16_t read() override final
    {
        int16_t v = -1;
        if (len) {
            v = in.read();
            --len;
        }
        return v;
    }

    int16_t peek() override final
    {
        return in.peek();
    }

    stream_size_t available()
    {
        return len;
    }

    void reduceLength(stream_size_t newLen)
    {
        if (newLen < len) {
            len = newLen; // only allow making region smaller
        }
    }

    virtual StreamType streamType() const override final
    {
        return in.streamType();
    }
};

/**
 * Limits writing to the stream to the given number of bytes.
 */
class RegionDataOut final : public DataOut {
    DataOut* out; // use pointer to have assignment operator
    stream_size_t len;

public:
    RegionDataOut(DataOut& _out, stream_size_t _len)
        : out(&_out)
        , len(_len)
    {
    }
    virtual ~RegionDataOut() = default;

    virtual bool write(uint8_t data) override
    {
        if (len > 0) {
            --len;
            return out->write(data);
        }
        return false;
    }

    void setLength(stream_size_t len_)
    {
        len = len_;
    }
    stream_size_t availableForWrite()
    {
        return len;
    }
};

} // end namespace cbox
