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
        auto written = end - start;
        eepromBlock.setObjectSize(written);
    };

    bool makeNewBlock = false; // set to true if a new block has to be created

    std::optional<EepromBlock> existingBlock;
    std::optional<EepromBlock> newBlock;

    uint16_t expectedSize = payload.content.size()
                            + 1 // flags
                            + 2 // cbox blockType
                            + 1 // CRC byte
        ;
    existingBlock = getExistingObject(payload.blockId, false);
    if (existingBlock) {
        auto& objectBlock = (*existingBlock);
        if (objectBlock.object_data_length() < expectedSize) {
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
        newBlock = getNewObject(expectedSize);
        if (!newBlock) {
            return CboxError::INSUFFICIENT_STORAGE;
        }
    }
    EepromBlock& blockToWrite = newBlock ? (*newBlock) : (*existingBlock);

    writeWithCrc(blockToWrite);
    // successfully written when we reach here

    if (newBlock && existingBlock) {
        (*existingBlock).setBlockType(EepromBlockType::disposed_block);
    }
    if (newBlock) {
        // overwrite invalid id with actual id to validate the block
        (*newBlock).setObjectId(payload.blockId);
    }

    return CboxError::OK;
}

CboxError EepromObjectStorage::loadObject(obj_id_t id, const PayloadCallback& callback)
{
    if (auto objIn = getExistingObject(id, true)) {
        return eepromToPayload(callback, (*objIn));
    }
    return CboxError::INVALID_STORED_BLOCK_ID;
}

CboxError EepromObjectStorage::loadAllObjects(const PayloadCallback& callback)
{
    uint16_t pos = EepromLocation(objects);

    while (auto objOpt = getNextObject(pos, true)) {
        auto blockData = (*objOpt);
        auto err = eepromToPayload(callback, blockData);
        if (err == CboxError::STORAGE_READ_ERROR) {
            return err; // only stop on read errors
        }
        if (err != CboxError::OK) {
            return err; // TODO should continue and only log error
        }
        pos = blockData.end();
    };

    return CboxError::OK;
}

bool EepromObjectStorage::disposeObject(obj_id_t id)
{
    // sets reader to data start of block data
    if (auto block = getExistingObject(id, false)) {
        // overwrite block type with disposed block
        (*block).setBlockType(EepromBlockType::disposed_block);
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
    uint16_t continuous = 0;
    uint16_t total = 0;
    uint16_t pos = EepromLocation(objects);
    while (auto block = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
        auto blockSize = (*block).block_size();
        total += blockSize;
        if (blockSize > continuous) {
            continuous = blockSize;
        }
        pos = (*block).end();
    }
    // subtract one header length from total, because that will not be available for the object
    // but if no disposed blocks were found, return 0
    return (total > EepromBlock::blockHeaderLength)
               ? EepromFreeSpace{uint16_t(total - EepromBlock::blockHeaderLength),
                                 uint16_t(continuous - EepromBlock::blockHeaderLength)}
               : EepromFreeSpace{0, 0};
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
std::optional<EepromBlock> EepromObjectStorage::getExistingBlock(EepromBlockType requestedType, uint16_t minLength, uint16_t startFrom)
{
    uint16_t pos = startFrom;
    while (pos + EepromBlock::blockHeaderLength < EepromLocationEnd(objects)) {
        EepromBlock block(eeprom, pos);
        if (block.type() == requestedType && block.length() >= minLength) {
            return block;
        }
        if (block.type() == EepromBlockType::unknown) {
            return std::nullopt; // abort search, eeprom is invalid
        }
        pos = block.end();
    }
    return std::nullopt;
}

// If limitToWrittenSize is true, only the length that was written previously is made available, not the reserved size
std::optional<EepromBlock> EepromObjectStorage::getNextObject(uint16_t start, bool limitToWrittenSize)
{

    if (auto blockOpt = getExistingBlock(EepromBlockType::object, 0, start)) {
        auto& block = *blockOpt;
        if (limitToWrittenSize) {
            block.reduceLength(block.getObjectSize());
        }
        block.seekToObjectData();
        return block;
    }
    return std::nullopt;
}

// Search for the object matching the requested id
// If limitToWrittenSize is true, only the length that was written previously is made available, not the reserved size
std::optional<EepromBlock> EepromObjectStorage::getExistingObject(obj_id_t id, bool limitToWrittenSize)
{
    auto pos = EepromLocation(objects);
    while (auto blockOpt = getNextObject(pos, limitToWrittenSize)) {
        auto& block = (*blockOpt);
        auto blockId = block.getObjectId();
        if (blockId != id) {
            pos = block.end();
            continue;
        }
        block.seekToObjectData();
        return block;
    }
    return std::nullopt;
}

// gets a block large enough to write object data and headers. objectLength does not include object header
std::optional<EepromBlock> EepromObjectStorage::getNewObject(uint16_t objectLength)
{
    auto provisionedLength = objectLength + std::max(objectLength / 8, 4) + EepromBlock::objectHeaderLength; // overprovision by 12.5%, minimal 4 bytes
    auto findBlock = [this, &provisionedLength]() -> std::optional<EepromBlock> {
        auto pos = EepromLocation(objects);
        if (auto block = getExistingBlock(EepromBlockType::disposed_block, provisionedLength, pos)) {
            return block;
        }
        // not enough space
        auto space = freeSpace();
        if (space.total < provisionedLength) {
            return std::nullopt;
        }
        if (space.continuous < provisionedLength) {
            defrag();
        }
        space = freeSpace();
        if (space.continuous < provisionedLength) {
            return std::nullopt; // this should be impossible after defrag
        }

        if (auto block = getExistingBlock(EepromBlockType::disposed_block, provisionedLength, pos)) {
            return block;
        }
        // this should be impossible
        return std::nullopt;
    };

    if (auto blockOpt = findBlock()) {
        auto& block = (*blockOpt);
        // split the block into the required length for the object and a new disposed block
        block.split(provisionedLength);
        // change the block from disposed to object.
        // Don't write the id yet, this will be done after valid data has been written
        block.setBlockType(EepromBlockType::object);
        block.resetToObjectData();
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
        auto& disposedBlock = (*disposedBlockOpt);
        if (auto objectBlockOpt = getExistingBlock(EepromBlockType::object, 0, disposedBlock.end())) {
            auto& objectBlock = (*objectBlockOpt);
            if (objectBlock.header_pos() != disposedBlock.end()) {
                // blocks are not contiguous, should have called mergeDisposedBlocks first
                return false;
            }

            // write object at location of disposed block and mark the remainder as disposed.
            // essentially, they swap places

            // The order of operations here is to prevent losing EEPROM block offsets/alignment when power is lost during the swap.
            // We first write the disposed length of the combined block, so that if power is lost, the entire block is treated as disposed and only 1 object is lost.
            disposedBlock.setBlockLength(disposedBlock.length() + objectBlock.block_size());

            uint16_t writePos = disposedBlock.object_pos();
            uint16_t readPos = objectBlock.object_pos();
            uint16_t readEnd = readPos + objectBlock.getObjectSize() + EepromBlock::objectHeaderLength;
            uint16_t provisionedSize = objectBlock.length();

            // Then we copy the data to the front of the block
            while (readPos < readEnd) {
                auto v = eeprom.readByte(readPos);
                if (!v) {
                    return false;
                }
                eeprom.writeByte(writePos, (*v));
                ++readPos;
                ++writePos;
            }

            // Then we split the block again
            disposedBlock.split(provisionedSize);

            // And finally we make the disposed block an object block again
            disposedBlock.setBlockType(EepromBlockType::object);
            return true;
        }
    }
    return false;
}

void EepromObjectStorage::mergeDisposedBlocks()
{

    auto pos = EepromLocation(objects);
    while (pos + EepromBlock::blockHeaderLength < EepromLocationEnd(objects)) {
        if (auto disposedBlock1Opt = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
            auto& disposedBlock1 = (*disposedBlock1Opt);
            pos = disposedBlock1.end();
            if (auto disposedBlock2Opt = getExistingBlock(EepromBlockType::disposed_block, 0, pos)) {
                if (disposedBlock1.end() == (*disposedBlock2Opt).header_pos()) {
                    // blocks are consecutive
                    disposedBlock1.join((*disposedBlock2Opt));
                } else {
                    pos = (*disposedBlock2Opt).end();
                }
            }
        } else {
            return;
        }
    }
}

} // end namespace cbox
