/*
 * Copyright 2018 Elco Jacobs / Brewblox.
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
#include "cbox/EepromDataStream.hpp"
#include "cbox/EepromLayout.hpp"
#include "cbox/ObjectStorage.hpp"

namespace cbox {

enum class BlockType : uint8_t {
    invalid, // ensures cleared eeprom reads as invalid block type
    object,
    disposed_block,
};

inline bool
operator==(const uint8_t& a, const BlockType& b)
{
    return a == static_cast<uint8_t>(b);
}

class EepromObjectStorage : public ObjectStorage {
public:
    explicit EepromObjectStorage(EepromAccess& _eeprom);
    virtual ~EepromObjectStorage() = default;

    CboxError loadObject(obj_id_t id, const PayloadCallback& callback) final;

    CboxError saveObject(const Payload& payload) final;

    CboxError loadAllObjects(const PayloadCallback& callback) final;

    bool disposeObject(obj_id_t id, bool mergeDisposed = true) final;

    void clear() final;

    stream_size_t freeSpace();

    stream_size_t continuousFreeSpace();

    void defrag();

private:
    /**
     * The application supplied EEPROM storage class
     */
    EepromAccess& eeprom;

    /**
     * Stream wrappers for reading, writing and limiting region
     */
    EepromDataIn reader;
    EepromDataOut writer;

    static constexpr uint8_t magicByte = 0x69;
    static constexpr uint8_t storageVersion = 0x01;
    static constexpr uint16_t referenceHeader = uint16_t(uint16_t(magicByte) << 8U) + storageVersion;

    void resetReader()
    {
        reader.reset(EepromLocation(objects), EepromLocationSize(objects));
    }
    void resetWriter()
    {
        writer.reset(EepromLocation(objects), EepromLocationSize(objects));
    }

    static uint16_t
    blockHeaderLength()
    {
        return sizeof(BlockType) + sizeof(uint16_t);
    }

    static uint16_t
    objectHeaderLength()
    {
        // actual size + id
        return blockHeaderLength() + sizeof(uint16_t) + sizeof(obj_id_t);
    }

    RegionDataIn getBlockReader(BlockType requestedType);
    RegionDataOut getBlockWriter(BlockType requestedType, uint16_t minSize);
    RegionDataIn getObjectReader(obj_id_t id, bool usedSize);
    RegionDataOut getObjectWriter(obj_id_t id);
    RegionDataOut newObjectWriter(obj_id_t id, uint16_t objectSize);

    void init();
    bool moveDisposedBackwards();
    bool mergeDisposedBlocks();

    static CboxError parseFromStream(obj_id_t id,
                                     const PayloadCallback& callback,
                                     RegionDataIn& in);
};

} // end namespace cbox
