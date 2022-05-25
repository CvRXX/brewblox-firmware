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

#include <array>
#include <cstdint>
#include <cstring>
#include <memory>
#include <optional>

namespace cbox {

class EepromAccess {
protected:
    EepromAccess() = default;
    ~EepromAccess() = default;

public:
    [[nodiscard]] virtual uint8_t readByte(uint16_t offset) const = 0;
    virtual void writeByte(uint16_t offset, uint8_t value) = 0;
    virtual void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const = 0;
    virtual void writeBlock(uint16_t offset, const uint8_t* source, uint16_t size) = 0;
    virtual void clear() = 0;

    template <typename T>
    void get(uint16_t idx, T& t) const
    {
        readBlock(reinterpret_cast<uint8_t*>(std::addressof(t)), idx, sizeof(T));
    }

    template <typename T>
    [[nodiscard]] T get(uint16_t idx, T&& t = {}) const
    {
        T val;
        get(idx, val);
        return val;
    }

    template <typename T>
    T& get(std::optional<T>&) = delete;

    template <typename T>
    void put(uint16_t idx, const T& t)
    {
        writeBlock(idx, reinterpret_cast<const uint8_t*>(std::addressof(t)), sizeof(T));
    }

    template <typename T>
    void put(std::optional<T>&) = delete;
};

class EepromMemoryAccess : public EepromAccess {
private:
    [[nodiscard]] bool isValidRange(uint16_t offset, uint16_t size) const
    {
        return offset + size <= length();
    }

protected:
    [[nodiscard]] virtual uint16_t length() const = 0;
    virtual uint8_t* data() = 0;

    [[nodiscard]] const uint8_t* data() const
    {
        auto* self = const_cast<EepromMemoryAccess*>(this);
        return self->data();
    }

public:
    [[nodiscard]] uint8_t readByte(uint16_t offset) const final
    {
        if (isValidRange(offset, 1)) {
            return data()[offset];
        }
        return 0;
    }

    void writeByte(uint16_t offset, uint8_t value) final
    {
        if (isValidRange(offset, 1)) {
            data()[offset] = value;
        }
    }

    void readBlock(uint8_t* target, uint16_t offset, uint16_t size) const final
    {
        if (isValidRange(offset, size)) {
            memcpy(target, data() + offset, size);
        }
    }

    void writeBlock(uint16_t offset, const uint8_t* source, uint16_t size) final
    {
        if (isValidRange(offset, size)) {
            memcpy(data() + offset, source, size);
        }
    }

    void clear() final
    {
        memset(data(), 0, length());
    }
};

/**
 * Emulate eeprom in memory. Used for testing.
 */
template <uint16_t eeprom_size>
class ArrayEepromAccess final : public EepromMemoryAccess {
private:
    std::array<uint8_t, eeprom_size> dataArray;

public:
    ArrayEepromAccess()
    {
        dataArray.fill(uint8_t{0xFF});
    }
    ~ArrayEepromAccess() = default;

    [[nodiscard]] uint8_t* data() override
    {
        return dataArray.data();
    }

    [[nodiscard]] uint16_t length() const override
    {
        return dataArray.size();
    }
};

} // end namespace cbox
