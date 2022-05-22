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

class EepromRegion {
    uint16_t blockStart;
    uint16_t objectStart;
    uint16_t objectEnd;
    uint16_t blockEnd;
};

EepromObjectStorage::EepromObjectStorage(EepromAccess& _eeprom)
    : eeprom(_eeprom)
    , reader(_eeprom)
    , writer(_eeprom)
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
                        + 2 // blockType
                        + 1 // CRC byte
        ;

    // ID is included in the CRC calculation
    uint8_t crc = calc_crc_16(0, payload.blockId);
    crc = calc_crc_8(crc, 0); // flags reserved byte
    crc = calc_crc_16(crc, payload.blockType);
    crc = calc_crc_vector(crc, payload.content);

    auto writeWithCrc = [&payload, &crc](RegionDataOut& objectEepromData) -> bool {
        uint8_t flags(0); // unused, used to be groups, kept for backwards compatibility
        if (!objectEepromData.put(flags)) {
            return false;
        }
        if (!objectEepromData.put(payload.blockType)) {
            return false;
        }
        if (!objectEepromData.writeBuffer(payload.content.data(), payload.content.size())) {
            return false;
        }
        if (!objectEepromData.write(crc)) {
            return false;
        }
        return true;
    };

    auto writeObject = [this, &writeWithCrc](RegionDataOut& objectEepromData) -> bool {
        uint16_t dataLocation = writer.offset();

        if (writeWithCrc(objectEepromData)) {
            uint16_t actualSize = writer.offset() - dataLocation;
            // write the actual object size as first 2 bytes in the block
            writer.reset(dataLocation - objectHeaderLength(), sizeof(actualSize));
            return writer.put(actualSize);
        }
        return false;
    };

    bool disposeBlock = false; // set to true if an old block should be removed
    bool newBlock = false;     // set to true if a new block has to be created

    if (auto objectEepromDataOpt = getObjectWriter(payload.blockId)) {
        auto& objectEepromData = objectEepromDataOpt.value();
        if (objectEepromData.availableForWrite() < dataSize) {
            // new data does not fit in region already allocated to the block
            disposeBlock = true;
            newBlock = true;
        } else if (!writeObject(objectEepromData)) {
            return CboxError::STORAGE_WRITE_ERROR;
        }
    } else {
        // no existing block found
        newBlock = true;
    }

    if (newBlock) {
        // block didn't fit or not found, should allocate a new block
        // get new writer, set block id to invalid until sucessfully relocated
        // over-provision 4 bytes or 12.5% to prevent having to relocate the block if it grows
        uint16_t overProvision = std::max(dataSize / 8, 4);
        uint16_t requestedSize = dataSize + overProvision;

        // uint16_t dataLocation = 0;

        if (auto objectEepromData = newObjectWriter(0, requestedSize)) {
            if (!writeObject(objectEepromData.value())) {
                // dataLocation = writer.offset();
                return CboxError::STORAGE_WRITE_ERROR;
            }
        } else {
            // not enough continuous free space
            auto needed = stream_size_t(requestedSize) + objectHeaderLength() + blockHeaderLength();
            if (freeSpace() < needed) {
                return CboxError::INSUFFICIENT_STORAGE; // not even enough total free space
            }
            if (continuousFreeSpace() < needed) {
                defrag();
            }
            if (continuousFreeSpace() < needed) {
                return CboxError::STORAGE_ERROR; // this should be impossible after defrag
            }

            if (auto objectEepromData = newObjectWriter(0, requestedSize)) {
                // dataLocation = writer.offset();
                if (!writeObject(objectEepromData.value())) {
                    return CboxError::STORAGE_WRITE_ERROR;
                }
            } else {
                // this should be impossible
                return CboxError::STORAGE_WRITE_ERROR;
            }
        }
    }

    // successfully written
    uint16_t idLocation = writer.offset();
    if (disposeBlock) {
        disposeObject(payload.blockId);
    }
    writer.reset(idLocation, sizeof(payload.blockId));
    writer.put(payload.blockId); // overwrite invalid id with actual id

    return CboxError::OK;
}

CboxError EepromObjectStorage::loadObject(obj_id_t id, const PayloadCallback& callback)
{
    if (auto objIn = getObjectReader(id, true)) {
        return parseFromStream(id, callback, objIn.value());
    }
    return CboxError::INVALID_STORED_BLOCK_ID;
}

CboxError EepromObjectStorage::loadAllObjects(const PayloadCallback& callback)
{
    reader.reset(EepromLocation(objects), EepromLocationSize(objects));

    while (auto type = reader.read()) {
        // loop over all blocks and write objects to output stream
        uint16_t blockSize = 0;
        if (!reader.get(blockSize)) {
            return CboxError::STORAGE_READ_ERROR;
        }

        switch (BlockType(type.value())) {
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

bool EepromObjectStorage::disposeObject(obj_id_t id)
{
    // sets reader to data start of block data
    if (auto block = getObjectReader(id, false)) {
        // overwrite block type with disposed block
        uint16_t dataStart = reader.offset();
        uint16_t blockTypeOffset = dataStart - objectHeaderLength() - blockHeaderLength();
        eeprom.writeByte(blockTypeOffset, static_cast<uint8_t>(BlockType::disposed_block));
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

stream_size_t EepromObjectStorage::freeSpace()
{
    stream_size_t total = 0;
    resetReader();
    while (auto block = getBlockReader(BlockType::disposed_block)) {
        auto blockSize = block.value().available();
        total += blockSize;
        total += blockHeaderLength();
        reader.skip(blockSize);
    }
    // subtract one header length, because that will not be available for the object
    // but if no disposed blocks were found, return 0
    return total > blockHeaderLength() ? total - blockHeaderLength() : 0;
}

stream_size_t EepromObjectStorage::continuousFreeSpace()
{
    stream_size_t space = 0;
    resetReader();
    while (auto block = getBlockReader(BlockType::disposed_block)) {
        auto blockSize = block.value().available();
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
std::optional<RegionDataIn> EepromObjectStorage::getBlockReader(BlockType requestedType)
{
    while (auto type = reader.read()) {
        uint16_t blockSize{0};
        if (!reader.get(blockSize)) {
            break; // couldn't read blocksize, due to reaching end of reader
        }
        if (!(type.value() == requestedType)) {
            reader.skip(blockSize);
            continue;
        }
        return RegionDataIn(reader, blockSize);
    }
    return std::nullopt;
}

// This function assumes that the reader is at the start of a block.
std::optional<RegionDataOut> EepromObjectStorage::getBlockWriter(BlockType requestedType, uint16_t minSize)
{
    // this sets the eeprom to the object location, with the full block size available
    if (auto blockOpt = getBlockReader(requestedType)) {
        auto& objectData = blockOpt.value();
        if (objectData.available() >= minSize) {
            // block found. now wrap the eeprom location with a writer instead of a reader
            writer.reset(reader.offset(), reader.available());
            return RegionDataOut(writer, objectData.available());
        }
    }
    return std::nullopt;
}

// Search for the block matching the requested id
// If found, return an EEPROM data stream limited to the block.
// If usedSize is true, only the length that was written previously is made available, not the reserved size
// This function assumes that the reader is at the start of a block.
// To ensure this, after using the RegionDataIn object, skip to the end of the block.
std::optional<RegionDataIn> EepromObjectStorage::getObjectReader(obj_id_t id, bool usedSize)
{
    resetReader();
    while (auto blockOpt = getBlockReader(BlockType::object)) {
        auto& block = blockOpt.value();
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
    return std::nullopt;
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

std::optional<RegionDataOut> EepromObjectStorage::getObjectWriter(obj_id_t id)
{
    // this sets the eeprom to the object location and requestes the full available object size for writing
    if (auto object = getObjectReader(id, false)) {
        // block found. now wrap the eeprom location with a writer instead of a reader
        writer.reset(reader.offset(), reader.available());
        return RegionDataOut(writer, object.value().available());
    }
    return std::nullopt;
}

// gets a block large enough to write storage id, actual size and data. objectSize is length of data
std::optional<RegionDataOut> EepromObjectStorage::newObjectWriter(obj_id_t id, uint16_t objectSize)
{
    // find a disposed block with enough size available
    resetReader();
    uint16_t neededSizeInclBlockHeader = objectSize + objectHeaderLength() + blockHeaderLength();
    uint16_t neededSizeExclBlockHeader = objectSize + objectHeaderLength();
    while (auto blockOpt = getBlockReader(BlockType::disposed_block)) {
        auto& blockData = blockOpt.value();
        auto blockSize = uint16_t(blockData.available()); // this excludes the block header
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
            uint16_t availableObjectSize = blockSize - objectHeaderLength();
            writer.put(availableObjectSize);
            writer.put(uint16_t(id));
            return RegionDataOut(writer, availableObjectSize);
        }
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
        uint16_t availableObjectSize = newBlockSize - objectHeaderLength();
        writer.put(newBlockSize);
        // write actualSize to the full block length
        // storeObject can adjust this if it doesn't use the full block
        writer.put(availableObjectSize);
        writer.put(uint16_t(id));
        return RegionDataOut(writer, availableObjectSize);
    }
    return std::nullopt;
}

void EepromObjectStorage::init()
{
    uint16_t header;
    eeprom.get(EepromLocation(header), header);
    if (header != referenceHeader) {
        eeprom.clear(); // writes zeros, active groups is now also 0x00
        eeprom.put(EepromLocation(header), referenceHeader);
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
    if (auto disposedBlock = getBlockReader(BlockType::disposed_block)) {
        uint16_t disposedStart = reader.offset();
        uint16_t disposedLength = disposedBlock.value().available();
        reader.skip(disposedLength);

        if (auto objectBlock = getBlockReader(BlockType::object)) {
            uint16_t objectLength = objectBlock.value().available();

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
    }
    return false;
}

void EepromObjectStorage::mergeDisposedBlocks()
{

    resetReader();
    while (auto disposedBlock1Opt = getBlockReader(BlockType::disposed_block)) {
        auto& disposedBlock1 = disposedBlock1Opt.value();

        uint16_t disposedDataStart1 = reader.offset();
        uint16_t disposedDataLength1 = disposedBlock1.available();

        reader.skip(disposedDataLength1);

        if (reader.peek() == BlockType::disposed_block) {
            if (auto disposedBlock2Opt = getBlockReader(BlockType::disposed_block)) {
                auto& disposedBlock2 = disposedBlock2Opt.value();
                uint16_t disposedLength2 = disposedBlock2.available();
                // now merge the blocks
                uint16_t combinedLength = disposedDataLength1 + disposedLength2 + blockHeaderLength();
                writer.reset(disposedDataStart1 - blockHeaderLength() + sizeof(BlockType), sizeof(uint16_t));
                writer.put(combinedLength);
                reader.skip(disposedLength2);
            }
        }
    }
}

} // end namespace cbox
