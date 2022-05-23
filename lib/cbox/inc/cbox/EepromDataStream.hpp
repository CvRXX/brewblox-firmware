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

#include "cbox/EepromAccess.hpp"
#include <cstdint>
#include <functional>
#include <vector>

namespace cbox {
class EepromStreamRegion {
protected:
    std::reference_wrapper<EepromAccess> _eepromAccess;
    uint16_t _start;
    uint16_t _pos;
    uint16_t _length;
    uint16_t _accessible_length;

public:
    EepromStreamRegion(EepromAccess& eepromAccess, uint16_t start, uint16_t length)
        : _eepromAccess(eepromAccess)
        , _start(start)
        , _pos(start)
        , _length(length)
        , _accessible_length(length)
    {
    }
    ~EepromStreamRegion() = default;

    EepromStreamRegion(EepromStreamRegion&& other) = default;
    EepromStreamRegion& operator=(EepromStreamRegion&& other) = default;
    EepromStreamRegion(const EepromStreamRegion& other) = default;
    EepromStreamRegion& operator=(const EepromStreamRegion& other) = default;

    constexpr uint16_t start() { return _start; }
    constexpr uint16_t offset() { return _pos - _start; }
    constexpr uint16_t remaining() { return _start + _accessible_length - _pos; }
    constexpr uint16_t length() { return _length; }
    constexpr uint16_t end() { return _pos + _length; }

    void reset(uint16_t o)
    {
        _pos = _start + o;
    }

    void put(uint8_t value)
    {
        if (_pos < _start + _accessible_length) {
            _eepromAccess.get().writeByte(_pos, value);
            ++_pos;
        }
    }

    void put(const std::vector<uint8_t>& bytes)
    {
        if (_pos + bytes.size() <= _start + _accessible_length) {
            _eepromAccess.get().writeBlock(_pos, bytes.data(), bytes.size());
            _pos += bytes.size();
        }
    }

    template <typename T>
    void put(const std::vector<T>& bytes) = delete;

    template <typename T>
    void put(const T& t)
    {
        if (_pos + sizeof(T) <= _start + _accessible_length) {
            _eepromAccess.get().put<T>(_pos, t);
            _pos += sizeof(T);
        }
    }

    template <typename T>
    void put(std::optional<T>&) = delete;

    template <typename T>
    void get(T& t)
    {
        if (_pos + sizeof(T) <= _start + _accessible_length) {
            _eepromAccess.get().get<T>(_pos, t);
            _pos += sizeof(T);
        }
    }

    void get(std::vector<uint8_t>& bytes)
    {
        if (_pos + bytes.size() <= _start + _accessible_length) {
            _eepromAccess.get().readBlock(bytes.data(), _pos, bytes.size());
            _pos += bytes.size();
        }
    }

    template <typename T>
    void get(std::vector<T>& bytes) = delete;

    template <typename T>
    [[nodiscard]] T get(T&& t = {})
    {
        T val;
        get(val);
        return val;
    }

    template <typename T>
    const T& get(std::optional<T>&) = delete;

    [[nodiscard]] std::optional<uint8_t> peek()
    {
        return _eepromAccess.get().readByte(_pos);
    }

    void skip(uint16_t skip_length)
    {
        auto skip = std::min(skip_length, _accessible_length);
        _pos += skip;
    }

    void reduceLength(uint16_t new_length)
    {
        if (new_length < _accessible_length) {
            _accessible_length = new_length;
        }
    }
};

enum class EepromBlockType : uint8_t {
    invalid, // ensures cleared eeprom reads as invalid block type
    object,
    disposed_block,
};

class EepromBlock : public EepromStreamRegion {
public:
    EepromBlock(EepromAccess& eepromAccess, uint16_t start, uint16_t length)
        : EepromStreamRegion(eepromAccess, start, length)
    {
    }

    static constexpr uint16_t blockHeaderLength = sizeof(EepromBlockType) + sizeof(uint16_t); // type, block data size
    static constexpr uint16_t objectHeaderLength = sizeof(uint16_t) + sizeof(uint16_t);       // id, actualsize

    void setBlockType(EepromBlockType type)
    {
        _eepromAccess.get().writeByte(_start, uint8_t(type));
    }

    void setBlockLength(uint16_t size)
    {
        _length = size;
        _accessible_length = _length;
        _eepromAccess.get().put(_start + 1, size - blockHeaderLength);
    }

    void resetToObjectData()
    {
        _pos = _start + blockHeaderLength + objectHeaderLength;
    }

    uint16_t objectOffset()
    {
        uint16_t offset = _pos - _start;
        uint16_t header = blockHeaderLength + objectHeaderLength;
        return offset > header ? offset - header : 0;
    }

    void setObjectSize(uint16_t size)
    {
        _eepromAccess.get().put(_start + blockHeaderLength, size);
    }

    uint16_t getObjectSize()
    {
        return _eepromAccess.get().get<uint16_t>(_start + blockHeaderLength);
    }

    void setObjectId(uint16_t id)
    {
        _eepromAccess.get().put(_start + blockHeaderLength + sizeof(uint16_t), id);
    }

    uint16_t getObjectId()
    {
        return _eepromAccess.get().get<uint16_t>(_start + blockHeaderLength + sizeof(uint16_t));
    }

    void reduceAccessLength(uint16_t new_length)
    {
        reduceLength(new_length);
    }

    void split(uint16_t newBlockLength)
    {
        // split into shorter block and new disposed block
        // first write new disposed block (at the end)
        uint16_t newDisposedLength = length() - newBlockLength;
        if (newDisposedLength < 8) {
            // don't create blocks smaller than 8 bytes
            return;
        }
        _eepromAccess.get().put(start() + newBlockLength, EepromBlockType::disposed_block);
        _eepromAccess.get().put(start() + newBlockLength + 1, newDisposedLength - objectHeaderLength);

        // then we update the current block
        setBlockLength(newBlockLength);
    }

    void join(EepromBlock& other)
    {
        setBlockLength(length() + other.length());
    }

    static uint16_t allocationSize(uint16_t objectSize)
    {
        // 1 byte eeprom block type
        // 2 bytes eeprom size
        // 2 bytes object id
        // 2 bytes actual object size
        // 1 byte flags (previously groups)
        // 2 bytes cbox object type
        // x bytes object data
        // 4+ bytes overprovision
        // 1 byte CRC

        // over-provision minimally 4 bytes or 12.5% to prevent having to relocate the block if it grows
        uint16_t provisionedObjectSize = objectSize + std::max(objectSize / 8, 4);

        return provisionedObjectSize + objectHeaderLength;
    }
};

} // end namespace cbox
