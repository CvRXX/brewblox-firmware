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
#include "cbox/ObjectIds.h"
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

    virtual CboxError read(Command& cmd) const override final
    {
        auto p = reinterpret_cast<const uint8_t*>(std::addressof(originalId));
        Payload outPayload(objectId, typeId(), 0);
        outPayload.content.assign(p, p + sizeof(obj_type_t));
        return cmd.respond(outPayload);
    }

    virtual CboxError readPersisted(Command& cmd) const override final
    {
        return read(cmd);
    }

    virtual CboxError write(Command&) override final
    {
        return CboxError::OBJECT_NOT_WRITABLE;
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
