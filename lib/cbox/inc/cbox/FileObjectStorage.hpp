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

#include "cbox/ObjectStorage.hpp"
#include <string>

namespace cbox {
class FileObjectStorage : public ObjectStorage {
public:
    explicit FileObjectStorage(const std::string& root_);

    virtual ~FileObjectStorage() = default;

    CboxError loadObject(obj_id_t id, const PayloadCallback& callback) final;

    CboxError loadAllObjects(const PayloadCallback& callback) final;

    CboxError saveObject(const Payload& payload) final;

    bool disposeObject(obj_id_t id, bool mergeDisposed = true) final;

    void clear() final;

private:
    std::string path;
    size_t rootLen;

    inline uint8_t
    storageVersion() const
    {
        return 0x01;
    }

    void setPath(obj_id_t id)
    {
        path.resize(rootLen);
        path += std::to_string(uint16_t(id));
    }
};

} // end namespace cbox
