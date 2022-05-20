/*
 * Copyright 2018 Elco Jacobs / Brewblox.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
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
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/CboxError.hpp"
#include "cbox/Payload.hpp"
#include <cstdint>

namespace cbox {

class ObjectStorage {
public:
    ObjectStorage() = default;
    virtual ~ObjectStorage() = default;

    virtual CboxError loadObject(obj_id_t id, const PayloadCallback& callback)
        = 0;

    virtual CboxError loadAllObjects(const PayloadCallback& callback)
        = 0;

    virtual CboxError saveObject(const Payload& payload)
        = 0;

    virtual bool disposeObject(obj_id_t id, bool mergeDisposed = true)
        = 0;

    virtual void clear() = 0;
};

class ObjectStorageStub : public ObjectStorage {
public:
    ObjectStorageStub() = default;
    virtual ~ObjectStorageStub() = default;

    CboxError loadObject(obj_id_t, const PayloadCallback&) final
    {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    CboxError loadAllObjects(const PayloadCallback&) final
    {
        return CboxError::INVALID_STORED_BLOCK_ID;
    }

    CboxError saveObject(const Payload&) final
    {
        return CboxError::OK;
    }

    bool disposeObject(obj_id_t /*id*/, bool /*mergeDisposed = true*/) final
    {
        return false;
    }

    void clear() final
    {
    }
};

} // end namespace cbox
