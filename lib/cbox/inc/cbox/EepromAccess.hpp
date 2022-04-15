/*
 * Copyright 2013 Matthew McGowan.
 *
 * This file is part of Brewblox.
 *
 * Controlbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Controlbox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>
#include <cstring>

namespace cbox {

class EepromAccess {
public:
    EepromAccess() = default;
    virtual ~EepromAccess() = default;

    virtual int16_t readByte(uint16_t offset) const = 0;
    virtual void writeByte(uint16_t offset, uint8_t value) = 0;
    virtual void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const = 0;
    virtual void writeBlock(uint16_t target, const uint8_t* source, uint16_t size) = 0;
    virtual void clear() = 0;

    template <typename T>
    T& get(const uint16_t& idx, T& t)
    {
        readBlock(reinterpret_cast<uint8_t*>(&t), idx, sizeof(T));
        return t;
    }

    template <typename T>
    const T& put(const uint16_t& idx, const T& t)
    {
        writeBlock(idx, reinterpret_cast<const uint8_t*>(&t), sizeof(T));
        return t;
    }
};

class EepromMemoryAccess : public EepromAccess {
private:
    bool isValidRange(uint16_t offset, uint16_t size) const
    {
        return offset + size <= length();
    }

protected:
    virtual uint16_t length() const = 0;
    virtual uint8_t* data() = 0;

    const uint8_t* data() const
    {
        return const_cast<EepromMemoryAccess*>(this)->data();
    }

public:
    EepromMemoryAccess() = default;
    virtual ~EepromMemoryAccess() = default;

    int16_t readByte(uint16_t offset) const override final
    {
        if (isValidRange(offset, 1)) {
            return data()[offset];
        }
        return -1;
    }

    void writeByte(uint16_t offset, uint8_t value) override final
    {
        if (isValidRange(offset, 1)) {
            data()[offset] = value;
        }
    }

    void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const override final
    {
        if (isValidRange(offset, size)) {
            memcpy(target, &data()[offset], size);
        }
    }

    void writeBlock(uint16_t offset, const uint8_t* source, uint16_t size) override final
    {
        if (isValidRange(offset, size)) {
            memcpy(&data()[offset], source, size);
        }
    }

    void clear() override final
    {
        memset(data(), 0, length());
    }
};

/**
 * Emulate eeprom in memory. Used for testing.
 */
template <size_t eeprom_size>
class ArrayEepromAccess final : public EepromMemoryAccess {
private:
    uint8_t dataArray[eeprom_size];

public:
    ArrayEepromAccess()
    {
        memset(dataArray, -1, length());
    }
    ~ArrayEepromAccess() = default;

    uint8_t* data() override
    {
        return dataArray;
    }

    uint16_t length() const override
    {
        return eeprom_size;
    }
};

} // end namespace cbox
