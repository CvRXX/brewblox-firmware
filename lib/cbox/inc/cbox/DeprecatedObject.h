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

#include "cbox/CboxError.h"
#include "cbox/ObjectBase.h"
#include <limits>

namespace cbox {

/**
 * An object that does nothing. When read, it returns the type it becomes when it is activated.
 */
class DeprecatedObject : public ObjectBase<std::numeric_limits<uint16_t>::max() - 2> {
private:
    obj_id_t originalId;

public:
    DeprecatedObject(const obj_id_t& oid)
        : originalId(oid)
    {
    }
    virtual ~DeprecatedObject() = default;

    virtual CboxError read(const PayloadCallback& callback) const override final
    {
        Payload payload(objectId, typeId(), 0);
        payload.content.resize(sizeof(originalId));
        cbox::BufferDataOut out(payload.content.data(), payload.content.size());
        out.put(originalId);
        return callback(payload);
    }

    virtual CboxError readStored(const PayloadCallback& callback) const override final
    {
        return read(callback);
    }

    virtual CboxError write(const Payload&) override final
    {
        return CboxError::BLOCK_NOT_WRITABLE;
    }

    virtual update_t update(const update_t& now) override final
    {
        return update_never(now);
    }

    obj_id_t storageId()
    {
        return originalId;
    }
};

} // end namespace cbox
