/*
 * Copyright 2021 Elco Jacobs / Brewblox.
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

#include "cbox/EepromObjectStorage.hpp"
#include "cbox/Crc.hpp"

namespace cbox {

EepromObjectStorage::EepromObjectStorage(EepromAccess& _eeprom)
    : eeprom(_eeprom)
{
    init();
}

CboxError EepromObjectStorage::saveObject(const Payload& payload)
{
    if (payload.blockId == 0) {
        return CboxError::INVALID_BLOCK_ID;
    }

    uint16_t dataSize = payload.content.size()
                        + 1 // flags
                        + 2 // cbox blockType
                        + 1 // CRC byte
        ;

    // ID is included in the CRC calculation
    uint8_t crc = calc_crc_16(0, payload.blockId);
    crc = calc_crc_8(crc, 0); // flags reserved byte
    crc = calc_crc_16(crc, payload.blockType);
    crc = calc_crc_vector(crc, payload.content);

    auto writeWithCrc = [&payload, &crc](EepromBlock& eepromBlock) -> void {
        uint16_t start = eepromBlock.offset();
        uint8_t flags{0}; // unused, used to be groups, kept for backwards compatibility
        eepromBlock.put(flags);
        eepromBlock.put(payload.blockType);
        eepromBlock.put(payload.content);
        eepromBlock.put(crc);
        uint16_t end = eepromBlock.offset();
        eepromBlock.setObjectSize(end - start + 3); // + id + actual size - crc
    };

    bool makeNewBlock = false; // set to true if a new block has to be created

    std::optional<EepromBlock> existingBlock;
    std::optional<EepromBlock> newBlock;

    existingBlock = getExistingObject(payload.blockId, false);
    if (existingBlock) {
        auto& objectBlock = existingBlock.value();
        objectBlock.resetToObjectData();
        if (objectBlock.remaining() < dataSize) {
            // new data does not fit in region already allocated to the block
            makeNewBlock = true;
        }
    } else {
        // no existing block found
        makeNewBlock = true;
    }

    if (makeNewBlock) {
        // block didn't fit or not found, should allocate a new block
        // block id is 0 until sucessfully relocated
        newBlock = getNewObject(dataSize);
        if (!newBlock) {
            return CboxError::INSUFFICIENT_STORAGE;
        }
        newBlock.value().resetToObjectData();
    }
    EepromBlock& blockToWrite = newBlock ? newBlock.value() : existingBlock.value();

    writeWithCrc(blockToWrite);
    // successfully written when we reach here

    if (newBlock && existingBlock) {
        existingBlock.value().setBlockType(EepromBlockType::disposed_block);
    }
    if (newBlock) {
        // overwrite invalid id with actual id to validate the block
        newBlock.value().setObjectId(payload.blockId);
    }

    return CboxError::OK;
}

CboxError EepromObjectStorage::loadObject(obj_id_t id, const PayloadCallback& callback)
{
    if (auto objIn = getExistingObject(id, true)) {
        return eepromToPayload(callback, objIn.value());
    }
    return CboxError::INVALID_STORED_BLOCK_ID;
}

CboxError EepromObjectStorage::loadAllObjects(const PayloadCallback& callback)
{
    uint16_t pos = EepromLocation(objects);

    while (auto objOpt = getExistingBlock(EepromBlockType::object, 0, pos)) {
        auto blockData = objOpt.value();
        auto err = eepromToPayload(callback, blockData);
        if (err == CboxError::STORAGE_READ_ERROR) {
            return err; // only stop on read errors
        }
        if (err != CboxError::OK) {
            return err; // TODO should continue and only log error
        }
        pos += blockData.length();
    };

    return CboxError::OK;
}

bool EepromObjectStorage::disposeObject(obj_id_t id)
{
    // sets reader to data start of block data
    if (auto block = getExistingObject(id, false)) {
        // overwrite block type with disposed block
        block.value().setBlockType(EepromBlockType::disposed_block);
        mergeDisposedBlocks();
        return true;
    }
    return false;
}

void EepromObjectStorage::clear()
{
    eeprom.clear();
    init();
}

EepromFreeSpace EepromObjectStorage::freeSpace()
{
    auto space = EepromFreeSpace{0, 0};
    uint16_t pos = EepromLocation(objects);
    while (auto block = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
        auto blockSize = block.value().length();
        space.total += blockSize;
        if (blockSize > space.continuous) {
            space.continuous = blockSize;
        }
        pos = block.value().end();
    }
    // subtract one header length from total, because that will not be available for the object
    // but if no disposed blocks were found, return 0
    // space.total = space.total > EepromBlock::blockHeaderLength ? space.total - EepromBlock::blockHeaderLength : 0;
    return space;
}

void EepromObjectStorage::defrag()
{
    // ensure no invalid objects with ID zero remain in eeprom
    // these are only temporary while relocating data
    disposeObject(0);
    do {
        mergeDisposedBlocks();
    } while (moveDisposedBackwards());
}

// This function assumes that the start position is at the start of a block.
std::optional<EepromBlock> EepromObjectStorage::getExistingBlock(EepromBlockType requestedType, uint16_t minSize, uint16_t startFrom)
{
    uint16_t pos = startFrom;
    while (pos + EepromBlock::blockHeaderLength < EepromLocationEnd(objects)) {
        auto type = eeprom.get<EepromBlockType>(pos);
        auto blockSize = eeprom.get<uint16_t>(pos + sizeof(EepromBlockType));
        if (type == requestedType && blockSize >= minSize) {
            return EepromBlock(eeprom, pos, blockSize);
        }
        pos += blockSize + sizeof(EepromBlockType) + sizeof(uint16_t);
    }
    return std::nullopt;
}

// Search for the block matching the requested id
// If found, return an EEPROM data stream limited to the block.
// If usedSize is true, only the length that was written previously is made available, not the reserved size
// This function assumes that the reader is at the start of a block.
// To ensure this, after using the RegionDataIn object, skip to the end of the block.
std::optional<EepromBlock> EepromObjectStorage::getExistingObject(obj_id_t id, bool usedSize)
{
    auto pos = EepromLocation(objects);
    while (auto blockOpt = getExistingBlock(EepromBlockType::object, 0, pos)) {
        auto& block = blockOpt.value();
        if (block.length() < EepromBlock::blockHeaderLength + EepromBlock::objectHeaderLength) {
            block.setBlockType(EepromBlockType::disposed_block); // dispose invalid objects
            pos += block.length();
            continue;
        }
        auto blockId = block.getObjectId();
        if (blockId != id) {
            pos += block.length();
            continue;
        }
        auto objectSize = block.getObjectSize();
        if (usedSize) {
            block.reduceAccessLength(objectSize + EepromBlock::blockHeaderLength);
        }

        return block;
    }
    return std::nullopt;
}

// gets a block large enough to write object data and headers. objectSize is length of object data
std::optional<EepromBlock> EepromObjectStorage::getNewObject(uint16_t objectSize)
{
    auto requestedSize = EepromBlock::allocationSize(objectSize);
    auto findBlock = [this, requestedSize]() -> std::optional<EepromBlock> {
        auto pos = EepromLocation(objects);
        if (auto block = getExistingBlock(EepromBlockType::disposed_block, requestedSize, pos)) {
            return block;
        }
        // not enough space
        auto space = freeSpace();
        if (space.total < requestedSize) {
            return std::nullopt;
        }
        if (space.continuous < requestedSize) {
            defrag();
        }
        space = freeSpace();
        if (space.continuous < requestedSize) {
            return std::nullopt; // this should be impossible after defrag
        }

        if (auto block = getExistingBlock(EepromBlockType::disposed_block, requestedSize, pos)) {
            return block;
        }
        // this should be impossible
        return std::nullopt;
    };

    if (auto blockOpt = findBlock()) {
        auto& block = blockOpt.value();
        block.split(requestedSize + EepromBlock::blockHeaderLength);
        block.setBlockType(EepromBlockType::object);
        return blockOpt;
    }
    return std::nullopt;
}

CboxError EepromObjectStorage::eepromToPayload(const PayloadCallback& callback,
                                               EepromBlock& in)
{
    auto id = in.getObjectId();
    in.resetToObjectData();

    auto flags = in.get<uint8_t>();
    auto objType = in.get<obj_type_t>();

    auto payload = Payload(id, objType, 0);
    payload.content.resize(in.remaining() - 1); // exclude CRC byte

    in.get(payload.content);

    auto objCrc = in.get<uint8_t>();

    uint8_t crc = calc_crc_16(0, id);
    crc = calc_crc_8(crc, flags);
    crc = calc_crc_16(crc, objType);
    crc = calc_crc_vector(crc, payload.content);
    crc = calc_crc_8(crc, objCrc);

    if (crc != 0) {
        return CboxError::STORAGE_CRC_ERROR;
    }

    return callback(payload);
}

void EepromObjectStorage::init()
{
    uint16_t currentHeader{0};
    eeprom.get(EepromLocation(header), currentHeader);
    if (currentHeader != referenceHeader) {
        eeprom.clear(); // writes zeros, active groups is now also 0x00
        eeprom.put(EepromLocation(header), referenceHeader);
        // make eeprom one big disposed block
        eeprom.put(EepromLocation(objects), EepromBlockType::disposed_block);
        eeprom.put(EepromLocation(objects) + sizeof(EepromBlockType), uint16_t(EepromLocationSize(objects) - EepromBlock::blockHeaderLength));
    }
}

// move a single disposed block backwards by swapping it with an object
bool EepromObjectStorage::moveDisposedBackwards()
{
    auto pos = EepromLocation(objects);
    if (auto disposedBlockOpt = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
        auto& disposedBlock = disposedBlockOpt.value();
        uint16_t disposedStart = disposedBlock.start() + EepromBlock::blockHeaderLength;
        uint16_t disposedEnd = disposedBlock.end();
        uint16_t disposedLength = disposedEnd - disposedStart;

        if (auto objectBlockOpt = getExistingBlock(EepromBlockType::object, 0, disposedBlock.end())) {
            auto& objectBlock = objectBlockOpt.value();
            uint16_t objectStart = objectBlock.start() + EepromBlock::blockHeaderLength;
            uint16_t objectEnd = objectBlock.end();
            uint16_t objectLength = objectEnd - objectStart;

            // write object at location of disposed block and mark the remainder as disposed.
            // essentially, they swap places

            if (objectStart != disposedEnd) {
                // blocks are not contiguous, should have called mergeDisposedBlocks first
                return false;
            }
            uint16_t writePos = disposedStart;
            uint16_t readPos = objectStart;

            // The order of operations here is to prevent losing EEPROM block offsets/alignment when power is lost during the swap.
            // We first write the disposed length of the combined block, so that if power is lost, the entire block is treated as disposed and only 1 object is lost.

            disposedBlock.setBlockLength(disposedLength + objectLength + EepromBlock::blockHeaderLength);

            // Then we copy the data to the front of the block
            while (readPos < objectEnd) {
                auto v = eeprom.readByte(readPos);
                if (!v) {
                    return false;
                }
                eeprom.writeByte(writePos, v.value());
                ++readPos;
                ++writePos;
            }

            // Then we mark the remainder as disposed
            eeprom.put(writePos++, EepromBlockType::disposed_block); // write header of the now discarded block data
            eeprom.put(writePos, disposedLength);

            // And finally we write the new header for the object that has moved forward
            eeprom.put(disposedBlock.start(), EepromBlockType::object);
            eeprom.put(disposedBlock.start() + 1, objectLength);

            return true;
        }
    }
    return false;
}

void EepromObjectStorage::mergeDisposedBlocks()
{

    auto pos = EepromLocation(objects);
    if (auto disposedBlock1Opt = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
        auto& disposedBlock1 = disposedBlock1Opt.value();
        auto nextStart = disposedBlock1.end();
        if (eeprom.readByte(nextStart) == EepromBlockType::disposed_block) {
            if (auto disposedBlock2Opt = getExistingBlock(EepromBlockType::disposed_block, 0, nextStart)) {
                disposedBlock1.join(disposedBlock2Opt.value());
            }
        }
    }
}

} // end namespace cbox
