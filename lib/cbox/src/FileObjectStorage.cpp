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

#include "cbox/FileObjectStorage.h"
#include "cbox/Crc.h"
#include "cbox/DataStreamIo.h"
#include <cstdio>
extern "C" {
#include <dirent.h>
}
#include <fstream>

namespace cbox {

FileObjectStorage::FileObjectStorage(const std::string& root)
{
    rootLen = root.size();
    path.reserve(rootLen + 10);
    path = root;
    if (root.back() != '/') {
        path += '/';
        ++rootLen;
    }
}

CboxError FileObjectStorage::saveObject(const Payload& payload)
{
    if (!payload.blockId) {
        return CboxError::INVALID_BLOCK_ID;
    }

    // ID is included in the CRC calculation
    uint8_t crc = calc_crc_16(0, payload.blockId);
    crc = calc_crc_16(crc, payload.blockType);
    crc = calc_crc_vector(crc, payload.content);

    setPath(payload.blockId);
    std::fstream fs(path, std::fstream::out | std::fstream::binary);
    if (!fs.is_open()) {
        return CboxError::STORAGE_WRITE_ERROR;
    }
    OStreamDataOut outStream{fs};

    bool writeOk = outStream.put(payload.blockId)
                   && outStream.put(payload.blockType)
                   && outStream.writeBuffer(payload.content.data(), payload.content.size())
                   && outStream.put(crc);

    fs.flush();
    fs.close();

    if (writeOk) {
        return CboxError::OK;
    } else {
        remove(path.c_str());
        return CboxError::STORAGE_WRITE_ERROR;
    }
}

CboxError FileObjectStorage::loadObject(
    const storage_id_t& id,
    const PayloadCallback& callback)
{
    setPath(id);
    std::fstream fs(path, std::fstream::in | std::fstream::binary);
    if (!fs.is_open()) {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    IStreamDataIn inStream{fs};
    RegionDataIn objIn(inStream, UINT16_MAX);
    // check that the first 2 bytes match the ID
    storage_id_t stored_id{0};
    if (objIn.get(stored_id) && stored_id == id) {
        return parseFromStream(id, callback, objIn);
    }
    return CboxError::INVALID_STORED_BLOCK_ID;
}

CboxError FileObjectStorage::loadAllObjects(const PayloadCallback& callback)
{
    path.resize(rootLen);
    if (auto* dir = opendir(path.c_str())) {
        while (auto* entry = readdir(dir)) {
            if ((entry->d_type & DT_REG) == DT_REG) {
                path.resize(rootLen);
                path += entry->d_name;
                std::fstream fs(path, std::fstream::in | std::fstream::binary);
                IStreamDataIn inStream{fs};
                RegionDataIn objIn(inStream, UINT16_MAX);
                // check that the first 2 bytes match the ID
                storage_id_t stored_id{0};
                if (objIn.get(stored_id) && stored_id == atoi(entry->d_name)) {
                    parseFromStream(stored_id, callback, objIn);
                }
            }
        }
        closedir(dir);
    }
    return CboxError::OK;
}

bool FileObjectStorage::disposeObject(const storage_id_t& id, bool /*mergeDisposed*/)
{
    setPath(id);
    return remove(path.c_str()) == 0;
}

void FileObjectStorage::clear()
{
    path.resize(rootLen);
    if (auto* dir = opendir(path.c_str())) {
        while (auto* entry = readdir(dir)) {
            if ((entry->d_type & DT_REG) == DT_REG) {
                path.resize(rootLen);
                path += entry->d_name;
                remove(path.c_str());
            }
        }
        closedir(dir);
    }
}

CboxError FileObjectStorage::parseFromStream(const storage_id_t& id, const PayloadCallback& callback, RegionDataIn& in)
{
    auto available = in.available();
    if (available == 0) {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    uint16_t blockType(0);
    if (!in.get(blockType)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    auto payload = Payload(id, blockType, 0);
    payload.content.resize(available - 1); // exclude CRC byte

    if (!in.readBytes(payload.content.data(), payload.content.size())) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint8_t objCrc(0);
    if (!in.get(objCrc)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint8_t crc = calc_crc_16(0, id);
    crc = calc_crc_16(crc, blockType);
    crc = calc_crc_vector(crc, payload.content);
    crc = calc_crc_8(crc, objCrc);

    if (crc != 0) {
        return CboxError::STORAGE_CRC_ERROR;
    }

    return callback(payload);
}

} // end namespace cbox
