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

#include "cbox/EepromObjectStorage.h"
#include "cbox/Crc.h"

namespace cbox {

EepromObjectStorage::EepromObjectStorage(EepromAccess& _eeprom)
    : eeprom(_eeprom)
    , reader(_eeprom)
    , writer(_eeprom)
{
    init();
}

CboxError EepromObjectStorage::saveObject(const Payload& payload)
{
    if (!payload.blockId) {
        return CboxError::INVALID_BLOCK_ID;
    }

    auto res = CboxError::OK;
    uint16_t dataSize = payload.content.size()
                        + 1 // flags
                        + 2 // blockType
                        + 1 // CRC byte
        ;

    // ID is included in the CRC calculation
    uint8_t crc = calc_crc_16(0, payload.blockId);
    crc = calc_crc_8(crc, 0); // flags reserved byte
    crc = calc_crc_16(crc, payload.blockType);
    crc = calc_crc_vector(crc, payload.content);

    // get actual writable region in eeprom
    RegionDataOut objectEepromData = getObjectWriter(payload.blockId);
    uint16_t dataLocation = writer.offset();
    uint16_t blockSize = objectEepromData.availableForWrite();

    auto writeWithCrc = [&objectEepromData, &payload, &crc]() -> CboxError {
        uint8_t flags(0); // unused, used to be groups, kept for backwards compatibility
        if (!objectEepromData.put(flags)) {
            return CboxError::STORAGE_WRITE_ERROR;
        }
        if (!objectEepromData.put(payload.blockType)) {
            return CboxError::STORAGE_WRITE_ERROR;
        }
        if (!objectEepromData.writeBuffer(payload.content.data(), payload.content.size())) {
            return CboxError::STORAGE_WRITE_ERROR;
        }
        if (!objectEepromData.write(crc)) {
            return CboxError::STORAGE_WRITE_ERROR;
        }
        return CboxError::OK;
    };

    if (dataSize <= blockSize) { // data + crc
        // should fit in existing location, write to EEPROM overwriting old data
        res = writeWithCrc();
    } else {
        // block didn't fit or not found, should allocate a new block
        bool isRelocate = (blockSize > 0);

        // over-provision 4 bytes or 12.5% to prevent having to relocate the block if it grows

        uint16_t overProvision = std::max(dataSize / 8, 4);
        uint16_t requestedSize = dataSize + overProvision;
        objectEepromData = newObjectWriter(0, requestedSize); // get new writer, set block id to invalid until sucessfully relocated
        dataLocation = writer.offset();
        uint16_t eepromBlockSize = objectEepromData.availableForWrite();
        if (eepromBlockSize < requestedSize) {
            // not enough continuous free space
            if (freeSpace() < stream_size_t(requestedSize) + (objectHeaderLength() - blockHeaderLength())) {
                return CboxError::INSUFFICIENT_STORAGE; // not even enough total free space
            }

            // if there is enough free space, but it is not continuous, do a defrag to and try again
            defrag();
            objectEepromData = newObjectWriter(payload.blockId, requestedSize);
            dataLocation = writer.offset();
            if (objectEepromData.availableForWrite() < requestedSize) {
                // LCOV_EXCL_LINE still not enough free space, exclude from coverage, because this should not be possible with the check above
                return CboxError::INSUFFICIENT_STORAGE; // LCOV_EXCL_LINE
            }
        }
        // looks like we can relocate the object, remove the old and write the new block
        if (isRelocate) {
            disposeObject(payload.blockId);
            writer.reset(dataLocation, eepromBlockSize);
        }
        res = writeWithCrc(); // now write the object
    }
    // check how many bytes were written
    uint16_t actualSize = writer.offset() - dataLocation;
    // write the actual object size as first 2 bytes in the block
    writer.reset(dataLocation - (objectHeaderLength() - blockHeaderLength()), 2 * sizeof(uint16_t));
    writer.put(actualSize);
    writer.put(payload.blockId); // overwrite invalid id with actual id
    return res;
}

CboxError EepromObjectStorage::loadObject(obj_id_t id, const PayloadCallback& callback)
{
    auto objIn = getObjectReader(id, true);
    return parseFromStream(id, callback, objIn);
}

CboxError EepromObjectStorage::loadAllObjects(const PayloadCallback& callback)
{
    reader.reset(EepromLocation(objects), EepromLocationSize(objects));

    while (reader.peek() >= 0) {
        uint8_t type = reader.read();
        // loop over all blocks and write objects to output stream
        uint16_t blockSize = 0;
        if (!reader.get(blockSize)) {
            return CboxError::STORAGE_READ_ERROR;
        }

        switch (BlockType(type)) {
        case BlockType::object: {
            auto blockData = RegionDataIn(reader, blockSize);
            auto handleBlock = [&blockData, &callback]() -> CboxError {
                // first 2 bytes of block are actual data size. Limit reading to this region
                uint16_t actualSize;
                if (!blockData.get(actualSize)) {
                    return CboxError::STORAGE_READ_ERROR;
                }
                obj_id_t id;
                if (!blockData.get(id)) {
                    return CboxError::STORAGE_READ_ERROR;
                }

                auto objIn = RegionDataIn(blockData, actualSize);
                return parseFromStream(id, callback, objIn);
            };
            auto result = handleBlock();
            if (result != CboxError::OK) {
                if (result == CboxError::STORAGE_READ_ERROR) {
                    return result; // stop on read errors
                }
                // log event. Do not return, because we do want to handle the next block
            }
            reader.skip(blockData.available());
        } break;
        case BlockType::disposed_block:
            if (!reader.skip(blockSize)) {
                return CboxError::STORAGE_ERROR;
            }
            break;
        case BlockType::invalid:
            return CboxError::INVALID_STORED_BLOCK_TYPE; // unknown block type encountered!
        default:
            return CboxError::INVALID_STORED_BLOCK_TYPE; // unknown block type encountered!
            break;
        }
    }
    return CboxError::OK;
}

bool EepromObjectStorage::disposeObject(obj_id_t id, bool mergeDisposed)
{
    RegionDataIn block = getObjectReader(id, true); // sets reader to data start of block data
    bool found = false;
    if (block.available() > 0) {
        // overwrite block type with disposed block
        uint16_t dataStart = reader.offset();
        uint16_t blockTypeOffset = dataStart - objectHeaderLength();
        eeprom.writeByte(blockTypeOffset, static_cast<uint8_t>(BlockType::disposed_block));
        found = true;
    }
    if (mergeDisposed) {
        mergeDisposedBlocks();
    }
    return found;
}

void EepromObjectStorage::clear()
{
    eeprom.clear();
    init();
}

stream_size_t EepromObjectStorage::freeSpace()
{
    stream_size_t total = 0;
    resetReader();
    while (reader.available()) {
        RegionDataIn blockData = getBlockReader(BlockType::disposed_block);
        auto blockSize = blockData.available();
        total += blockSize;
        total += blockHeaderLength();
        reader.skip(blockSize);
    }
    // subtract one header length, because that will not be available for the object
    return total - blockHeaderLength();
}

stream_size_t EepromObjectStorage::continuousFreeSpace()
{
    stream_size_t space = 0;
    resetReader();
    while (reader.available()) {
        RegionDataIn blockData = getBlockReader(BlockType::disposed_block);
        auto blockSize = blockData.available();
        space = std::max(space, blockSize);
        reader.skip(blockSize);
    }
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

// This function assumes that the reader is at the start of a block.
// To ensure this, after using the RegionDataIn object, skip to the end of the block.
RegionDataIn EepromObjectStorage::getBlockReader(BlockType requestedType)
{
    while (reader.peek() >= 0) {
        uint8_t type = reader.read();
        uint16_t blockSize = 0;
        if (!reader.get(blockSize)) {
            break; // couldn't read blocksize, due to reaching end of reader
        }
        if (!(type == requestedType)) {
            reader.skip(blockSize);
            continue;
        }
        return RegionDataIn(reader, blockSize);
    }
    return RegionDataIn(reader, 0);
}

// This function assumes that the reader is at the start of a block.
RegionDataOut EepromObjectStorage::getBlockWriter(BlockType requestedType, uint16_t minSize)
{
    // this sets the eeprom to the object location, with the full block size available
    RegionDataIn objectData = getBlockReader(requestedType);
    if (objectData.available() >= minSize) {
        // block found. now wrap the eeprom location with a writer instead of a reader
        writer.reset(reader.offset(), reader.available());
        return RegionDataOut(writer, objectData.available());
    }
    return RegionDataOut(writer, 0); // length 0 writer
}

// Search for the block matching the requested id
// If found, return an EEPROM data stream limited to the block.
// If usedSize is true, only the length that was written previously is made available, not the reserved size
// This function assumes that the reader is at the start of a block.
// To ensure this, after using the RegionDataIn object, skip to the end of the block.
RegionDataIn EepromObjectStorage::getObjectReader(obj_id_t id, bool usedSize)
{
    resetReader();
    while (reader.peek() >= 0) {
        RegionDataIn block = getBlockReader(BlockType::object);
        if (block.available() < sizeof(uint16_t) + sizeof(obj_id_t)) {
            reader.skip(block.available());
            continue;
        }
        uint16_t objectSize = 0;
        obj_id_t blockId = 0;
        block.get(objectSize);
        block.get(blockId);
        if (blockId != id) {
            reader.skip(block.available());
            continue;
        }
        if (usedSize) {
            block.reduceLength(objectSize);
        }

        return block;
    }
    return RegionDataIn(reader, 0);
}

CboxError EepromObjectStorage::parseFromStream(obj_id_t id,
                                               const PayloadCallback& callback,
                                               RegionDataIn& in)
{
    if (in.available() == 0) {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    uint8_t flags(0); // reserved, used to be groups
    if (!in.get(flags)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint16_t blockType(0);
    if (!in.get(blockType)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    auto payload = Payload(id, blockType, 0);
    payload.content.resize(in.available() - 1); // exclude CRC byte

    if (!in.readBytes(payload.content.data(), payload.content.size())) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint8_t objCrc(0);
    if (!in.get(objCrc)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint8_t crc = calc_crc_16(0, id);
    crc = calc_crc_8(crc, flags);
    crc = calc_crc_16(crc, blockType);
    crc = calc_crc_vector(crc, payload.content);
    crc = calc_crc_8(crc, objCrc);

    if (crc != 0) {
        return CboxError::STORAGE_CRC_ERROR;
    }

    return callback(payload);
}

RegionDataOut EepromObjectStorage::getObjectWriter(obj_id_t id)
{
    // this sets the eeprom to the object location and requestes the full available object size for writing
    RegionDataIn objectData = getObjectReader(id, false);
    if (objectData.available() > 0) {
        // block found. now wrap the eeprom location with a writer instead of a reader
        writer.reset(reader.offset(), reader.available());
        return RegionDataOut(writer, objectData.available());
    }
    return RegionDataOut(writer, 0); // length 0 writer
}

// gets a block large enough to write storage id, actual size and data. objectSize is length of data
RegionDataOut EepromObjectStorage::newObjectWriter(obj_id_t id, uint16_t objectSize)
{
    // find a disposed block with enough size available
    resetReader();
    uint16_t neededSizeInclBlockHeader = objectSize + objectHeaderLength();
    uint16_t neededSizeExclBlockHeader = neededSizeInclBlockHeader - blockHeaderLength();
    while (reader.available() >= neededSizeInclBlockHeader) {
        RegionDataIn blockData = getBlockReader(BlockType::disposed_block);
        uint16_t blockSize = uint16_t(blockData.available()); // this excludes the block header
        if (blockSize < neededSizeExclBlockHeader) {
            reader.skip(blockSize);
            continue;
        }
        // Large enough block found. now wrap the eeprom location with a writer instead of a reader
        if (blockSize < neededSizeExclBlockHeader + 8) {
            // don't create new disposed blocks smaller than 8 bytes, add space to this object instead
            writer.reset(reader.offset() - blockHeaderLength(), blockSize + blockHeaderLength());
            writer.put(BlockType::object);
            writer.put(blockSize);
            uint16_t availableObjectSize = blockSize - (objectHeaderLength() - blockHeaderLength());
            writer.put(availableObjectSize);
            writer.put(uint16_t(id));
            return RegionDataOut(writer, availableObjectSize);
        } else {
            // split into object block and new disposed block
            uint16_t blockToSplitHeaderStart = reader.offset() - blockHeaderLength();
            uint16_t newDisposedBlockSize = blockSize - neededSizeInclBlockHeader;
            uint16_t newDisposedBlockStart = blockToSplitHeaderStart + neededSizeInclBlockHeader;

            // first disposed block (at the end)
            writer.reset(newDisposedBlockStart, blockHeaderLength());
            writer.put(BlockType::disposed_block);
            writer.put(newDisposedBlockSize);
            // then object block
            writer.reset(blockToSplitHeaderStart, neededSizeInclBlockHeader);
            writer.put(BlockType::object);
            uint16_t newBlockSize = neededSizeExclBlockHeader;
            uint16_t availableObjectSize = newBlockSize - (objectHeaderLength() - blockHeaderLength());
            writer.put(newBlockSize);
            // write actualSize to the full block length
            // storeObject can adjust rewrite this if it doesn't use the full block
            writer.put(availableObjectSize);
            writer.put(uint16_t(id));
            return RegionDataOut(writer, availableObjectSize);
        }
    }
    return RegionDataOut(writer, 0); // length 0 writer
}

void EepromObjectStorage::init()
{
    uint16_t header;
    eeprom.get(EepromLocation(header), header);
    if (header != referenceHeader()) {
        eeprom.clear(); // writes zeros, active groups is now also 0x00
        auto referenceHeaderValue = referenceHeader();
        eeprom.put(EepromLocation(header), referenceHeaderValue);
        resetWriter();
        // make eeprom one big disposed block
        writer.put(BlockType::disposed_block);
        writer.put(uint16_t(EepromLocationSize(objects) - blockHeaderLength()));
    }
}

// move a single disposed block backwards by swapping it with an object
bool EepromObjectStorage::moveDisposedBackwards()
{
    resetReader();
    RegionDataIn disposedBlock = getBlockReader(BlockType::disposed_block);

    uint16_t disposedStart = reader.offset();
    uint16_t disposedLength = disposedBlock.available();
    if (disposedLength == 0) {
        return false;
    }
    reader.skip(disposedLength);

    RegionDataIn objectBlock = getBlockReader(BlockType::object);
    uint16_t objectLength = objectBlock.available();

    if (objectLength == 0) {
        return false;
    }

    // write object at location of disposed block and mark the remainder as disposed.
    // essentially, they swap places

    // The order of operations here is to prevent losing EEPROM block offsets/alignment when power is lost during the swap.
    // We first write the disposed length of the combined block, so that if power is lost, the entire block is treated as disposed and only 1 object is lost.
    writer.reset(disposedStart - sizeof(uint16_t), sizeof(uint16_t) + objectLength + blockHeaderLength());
    writer.put(uint16_t(disposedLength + objectLength + blockHeaderLength()));

    // Then we copy the data to the front of the block
    if (reader.push(writer, objectLength) != CboxError::OK) {
        return false;
    };

    // Then we mark the remainder as disposed
    writer.put(BlockType::disposed_block); // write header of the now discarded block data
    writer.put(disposedLength);

    // And finally we write the new header for the object that has moved forward
    writer.reset(disposedStart - blockHeaderLength(), blockHeaderLength());
    writer.put(BlockType::object);
    writer.put(objectLength);

    return true;
}

bool EepromObjectStorage::mergeDisposedBlocks()
{
    resetReader();
    bool didMerge = false;
    while (reader.peek() >= 0) {
        RegionDataIn disposedBlock1 = getBlockReader(BlockType::disposed_block);

        uint16_t disposedDataStart1 = reader.offset();
        uint16_t disposedDataLength1 = disposedBlock1.available();

        reader.skip(disposedDataLength1);
        if (reader.peek() < 0) {
            return false; // end of EEPROM, no next block
        }

        uint8_t nextBlockType = reader.peek();
        if (nextBlockType == BlockType::disposed_block) {
            RegionDataIn disposedBlock2 = getBlockReader(BlockType::disposed_block);
            uint16_t disposedLength2 = disposedBlock2.available();
            // now merge the blocks
            uint16_t combinedLength = disposedDataLength1 + disposedLength2 + blockHeaderLength();
            writer.reset(disposedDataStart1 - blockHeaderLength() + sizeof(BlockType), sizeof(uint16_t));
            writer.put(combinedLength);
            didMerge = true;
            reader.skip(disposedLength2);
        }
    }
    return didMerge;
}

} // end namespace cbox
