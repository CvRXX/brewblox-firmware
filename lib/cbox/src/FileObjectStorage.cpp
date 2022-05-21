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

#include "cbox/FileObjectStorage.hpp"
#include "cbox/Crc.hpp"
#include <cstdio>
extern "C" {
#include <dirent.h>
}
#include <fstream>

namespace cbox {

template <typename T>
bool streamRead(std::fstream& fs, T& t)
{
    fs.read(reinterpret_cast<char*>(&t), sizeof(T));
    return !fs.bad();
}

bool streamReadBuffer(std::fstream& fs, std::vector<uint8_t>& buf)
{
    fs.read(reinterpret_cast<char*>(buf.data()), buf.size());
    return !fs.bad();
}

template <typename T>
bool streamWrite(std::fstream& fs, const T& t)
{
    fs.write(reinterpret_cast<const char*>(&t), sizeof(T));
    return !fs.bad();
}

bool streamWriteBuffer(std::fstream& fs, const std::vector<uint8_t>& buf)
{
    fs.write(reinterpret_cast<const char*>(buf.data()), buf.size());
    return !fs.bad();
}

CboxError parseFromStream(obj_id_t id, const PayloadCallback& callback, std::fstream& fs)
{
    static constexpr size_t metadataLength = 0
                                             + 2 // id
                                             + 1 // flags
                                             + 2 // blockType
                                             + 1 // CRC
        ;

    // get length of file:
    fs.seekg(0, std::fstream::end);
    size_t length = fs.tellg();
    fs.seekg(0, std::fstream::beg);

    if (length < metadataLength) {
        return CboxError::STORAGE_READ_ERROR;
    }

    // check that the first 2 bytes match the ID
    obj_id_t storedId{0};
    if (!streamRead(fs, storedId) && storedId == id) {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    uint8_t flags{0}; // used to be groups, now a reserved byte to remain backwards compatible
    if (!streamRead(fs, flags)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    obj_type_t blockType{0};
    if (!streamRead(fs, blockType)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    auto payload = Payload(id, blockType, 0);
    payload.content.resize(length - metadataLength);

    if (!streamReadBuffer(fs, payload.content)) {
        return CboxError::STORAGE_READ_ERROR;
    }

    uint8_t objCrc{0};
    if (!streamRead(fs, objCrc)) {
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

    // Used to be groups, now a reserved byte to remain backwards compatible
    uint8_t flags{0};

    // ID is included in the CRC calculation
    uint8_t crc = calc_crc_16(0, payload.blockId);
    crc = calc_crc_8(crc, flags);
    crc = calc_crc_16(crc, payload.blockType);
    crc = calc_crc_vector(crc, payload.content);

    setPath(payload.blockId);
    std::fstream fs(path, std::fstream::out | std::fstream::binary);
    if (!fs.is_open()) {
        return CboxError::STORAGE_WRITE_ERROR;
    }

    bool writeOk = streamWrite(fs, payload.blockId)
                   && streamWrite(fs, flags)
                   && streamWrite(fs, payload.blockType)
                   && streamWriteBuffer(fs, payload.content)
                   && streamWrite(fs, crc);

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
    obj_id_t id,
    const PayloadCallback& callback)
{
    setPath(id);
    std::fstream fs(path, std::fstream::in | std::fstream::binary);
    if (!fs.is_open()) {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    return parseFromStream(id, callback, fs);
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
                parseFromStream(atoi(entry->d_name), callback, fs);
            }
        }
        closedir(dir);
    }
    return CboxError::OK;
}

bool FileObjectStorage::disposeObject(obj_id_t id, bool /*mergeDisposed*/)
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

} // end namespace cbox
