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

enum class EepromBlockType : uint8_t {
    invalid, // ensures cleared eeprom reads as invalid block type
    object,
    disposed_block,
    unknown,
};

class EepromBlock {
private:
    std::reference_wrapper<EepromAccess> _eeprom;
    uint16_t _start;           // start including block header
    uint16_t _pos;             // current read/write location
    uint16_t _size;            // total size including headers
    uint16_t _accessible_size; // total accessible reduced to 'valid region' manually
    EepromBlockType _type = EepromBlockType::unknown;

public:
    EepromBlock(EepromAccess& eepromAccess, uint16_t start)
        : _eeprom(eepromAccess)
        , _start(start)
        , _pos(_start + blockHeaderLength)
    {
        auto typeByte = _eeprom.get().get<uint8_t>(start);
        _size = _eeprom.get().get<uint16_t>(start + 1) + blockHeaderLength;
        _type = typeByte > uint8_t(EepromBlockType::unknown) ? EepromBlockType::unknown : EepromBlockType(typeByte);

        if (_type == EepromBlockType::object) {
            if (length() < objectHeaderLength) {
                // discard object blocks that are too short
                setBlockType(EepromBlockType::disposed_block);
            }
        }
        _accessible_size = _size;
    }

    static constexpr uint16_t blockHeaderLength
        = sizeof(EepromBlockType) + sizeof(uint16_t);                                   // type, block data size
    static constexpr uint16_t objectHeaderLength = sizeof(uint16_t) + sizeof(uint16_t); // id, actualsize

public:
    [[nodiscard]] constexpr uint16_t offset() const { return _pos - _start; }
    [[nodiscard]] constexpr uint16_t remaining() const { return _start + _accessible_size - _pos; }
    [[nodiscard]] constexpr uint16_t header_pos() const { return _start; }
    [[nodiscard]] constexpr uint16_t object_pos() const { return _start + blockHeaderLength; }
    [[nodiscard]] constexpr uint16_t object_data_pos() const { return _start + blockHeaderLength + objectHeaderLength; }
    [[nodiscard]] constexpr uint16_t end() const { return _start + _size; }
    [[nodiscard]] constexpr EepromBlockType type() const { return _type; }
    [[nodiscard]] constexpr uint16_t length() const { return _size - blockHeaderLength; }
    [[nodiscard]] constexpr uint16_t object_data_length() const { return _size - blockHeaderLength - objectHeaderLength; }
    [[nodiscard]] constexpr uint16_t block_size() const { return _size; }
    void seekToObjectData() { _pos = _start + blockHeaderLength + objectHeaderLength; };

public:
    void setBlockType(EepromBlockType type)
    {
        _eeprom.get().writeByte(_start, uint8_t(type));
        _type = type;
    }

    void setBlockLength(uint16_t len)
    {
        _size = len + blockHeaderLength;
        _accessible_size = _size;
        _eeprom.get().put(_start + 1, length());
    }

    void resetToObjectData()
    {
        _pos = _start + blockHeaderLength + objectHeaderLength;
    }

    void put(uint8_t value)
    {
        if (_pos < _start + _accessible_size) {
            _eeprom.get().writeByte(_pos, value);
            ++_pos;
        }
    }

    void put(const std::vector<uint8_t>& bytes)
    {
        if (_pos + bytes.size() <= _start + _accessible_size) {
            _eeprom.get().writeBlock(_pos, bytes.data(), bytes.size());
            _pos += bytes.size();
        }
    }

    template <typename T>
    void put(const std::vector<T>& bytes) = delete;

    template <typename T>
    void put(const T& t)
    {
        if (_pos + sizeof(T) <= _start + _accessible_size) {
            _eeprom.get().put<T>(_pos, t);
            _pos += sizeof(T);
        }
    }

    template <typename T>
    void put(std::optional<T>&) = delete;

    template <typename T>
    void get(T& t)
    {
        if (_pos + sizeof(T) <= _start + _accessible_size) {
            _eeprom.get().get<T>(_pos, t);
            _pos += sizeof(T);
        }
    }

    void get(std::vector<uint8_t>& bytes)
    {
        if (_pos + bytes.size() <= _start + _accessible_size) {
            _eeprom.get().readBlock(bytes.data(), _pos, bytes.size());
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
        return _eeprom.get().readByte(_pos);
    }

    void reduceLength(uint16_t object_data_length)
    {
        auto new_length = object_data_length + blockHeaderLength + objectHeaderLength;
        if (new_length < _accessible_size) {
            _accessible_size = new_length;
        }
    }

    void setObjectSize(uint16_t size)
    {
        // first 2 bytes after the header
        if (_type == EepromBlockType::object) {
            _eeprom.get().put(_start + blockHeaderLength, size);
        }
    }

    uint16_t getObjectSize()
    {
        if (_type == EepromBlockType::object) {
            return _eeprom.get().get<uint16_t>(_start + blockHeaderLength);
        }
        return 0;
    }

    void setObjectId(uint16_t id)
    {
        // second 2 bytes after the header
        if (_type == EepromBlockType::object) {
            _eeprom.get().put(_start + blockHeaderLength + 2, id);
        }
    }

    uint16_t getObjectId()
    {
        if (_type == EepromBlockType::object) {
            return _eeprom.get().get<uint16_t>(_start + blockHeaderLength + 2);
        }
        return 0;
    }

    void split(uint16_t retainedLength)
    {
        // split into shorter block and new disposed block
        // don't create disposed blocks smaller than 8 bytes
        if (retainedLength + 8 + blockHeaderLength > length()) {
            return;
        }

        _eeprom.get().put(object_pos() + retainedLength, EepromBlockType::disposed_block);
        _eeprom.get().put(object_pos() + retainedLength + 1, length() - retainedLength - blockHeaderLength);

        // then we update the current block
        setBlockLength(retainedLength);
    }

    void join(EepromBlock& other)
    {
        setBlockLength(length() + other.block_size());
    }
};

} // end namespace cbox
