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
#include "cbox/EepromAccess.hpp"
#include <cstdint>

namespace cbox {

using stream_size_t = size_t;

/**
 * An output stream that supports writing data.
 */
class DataOut {
public:
protected:
    DataOut() = default;
    ~DataOut() = default;

public:
    /**
     * Writes a byte to the stream.
     * @return {@code true} if the byte was successfully written, false otherwise.
     */
    virtual bool write(uint8_t data) = 0;

    template <typename T>
    bool put(const T& t)
    {
        const auto* p = reinterpret_cast<const uint8_t*>(std::addressof(t));
        return writeBuffer(p, sizeof(T));
    }

    template <typename T>
    bool put(std::optional<T>&) = delete;

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

/**
 * A data input stream. Byte based, but returns int16_t to be able to return negative values for error conditions
 */
class DataIn {
public:
    virtual ~DataIn() = default;
    /**
     * Retrieves the next byte of data.
     */
    virtual std::optional<uint8_t> read() = 0;

    /**
     * Retrieves the next byte of data without removing it from the stream.
     */
    virtual std::optional<uint8_t> peek() = 0;

    /**
     * Discards all data until no new data is available
     */
    void spool()
    {
        while (read()) {
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
        auto* ptr = reinterpret_cast<uint8_t*>(std::addressof(t));
        return readBytes(ptr, sizeof(T));
    }

    template <typename T>
    bool get(std::optional<T>&) = delete;

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

    std::optional<uint8_t> read() final
    {
        if (len == 0) {
            return std::nullopt;
        }
        auto v = in.read();
        if (v) {
            --len;
        }
        return v;
    }

    std::optional<uint8_t> peek() final
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
    ~RegionDataOut() = default;

    RegionDataOut(const RegionDataOut&) = delete;
    RegionDataOut(RegionDataOut&&) = default;
    RegionDataOut& operator=(const RegionDataOut&) = delete;
    RegionDataOut& operator=(RegionDataOut&&) = default;

    bool write(uint8_t data) override
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

class EepromStreamRegion {
protected:
    uint16_t _offset = 0;
    stream_size_t _length = 0;

public:
    uint16_t offset() { return _offset; }
    stream_size_t length() { return _length; }

    void reset(uint16_t o, stream_size_t l)
    {
        _offset = o;
        _length = l;
    }
};

/**
 * A datastream implementation that writes to a region of eeprom.
 * Eeprom is written via the EepromAccess helper.
 * The stream is only written up to the length specified - once that length has been filled
 * writes are silently failed.
 * @see EepromAccess
 */
class EepromDataOut final : public DataOut, public EepromStreamRegion {
private:
    EepromAccess& eepromAccess;

public:
    explicit EepromDataOut(EepromAccess& ea)
        : eepromAccess(ea)
    {
    }

    bool write(uint8_t value) final
    {
        if (_length > 0) {
            eepromAccess.writeByte(_offset++, value);
            _length--;
            return true;
        }
        return false; // LCOV_EXCL_LINE: doesn't happen if length is managed properly
    }
};

/**
 * A data input stream that reads from a region of eeprom.
 * @see EepromAccess
 */
class EepromDataIn : public DataIn, public EepromStreamRegion {
private:
    EepromAccess& eepromAccess;

public:
    explicit EepromDataIn(EepromAccess& ea)
        : eepromAccess(ea)
    {
    }

    [[nodiscard]] std::optional<uint8_t> peek() final
    {
        return eepromAccess.readByte(_offset);
    }

    [[nodiscard]] std::optional<uint8_t> read() final
    {
        if (_length <= 0) {
            return std::nullopt;
        }
        auto result = eepromAccess.readByte(_offset);
        if (result) {
            _length--;
            _offset++;
        }

        return result;
    }

    bool skip(stream_size_t skip_length)
    {
        auto skip = std::min(skip_length, _length);
        _offset += skip;
        _length -= skip;
        return skip == skip_length;
    }

    stream_size_t available()
    {
        return _length;
    }
};
} // end namespace cbox
