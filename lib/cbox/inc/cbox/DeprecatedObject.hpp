/*
 * Copyright 2018 Elco Jacobs / Brewblox, based on earlier work of Matthew McGowan
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
#include "cbox/ObjectBase.hpp"
#include "cbox/Serialization.hpp"
#include <limits>

namespace cbox {

/**
 * An object that does nothing. When read, it returns the type it becomes when it is activated.
 */
class DeprecatedObject final : public ObjectBase<std::numeric_limits<uint16_t>::max() - 2> {
private:
    obj_id_t originalId;

public:
    explicit DeprecatedObject(const obj_id_t& oid)
        : originalId(oid)
    {
    }
    ~DeprecatedObject() = default;

    CboxError read(const PayloadCallback& callback) const override
    {
        Payload payload(objectId(), typeId(), 0);
        appendToByteVector(payload.content, originalId);
        return callback(payload);
    }

    CboxError readStored(const PayloadCallback& callback) const override
    {
        return read(callback);
    }

    CboxError write(const Payload&) override
    {
        return CboxError::BLOCK_NOT_WRITABLE;
    }

    obj_id_t storageId()
    {
        return originalId;
    }
};

} // end namespace cbox
