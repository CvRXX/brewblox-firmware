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
#include "cbox/Payload.hpp"
#include <limits>

namespace cbox {

using update_t = uint32_t;

class Object {
private:
    update_t _nextUpdateTime{0}; // ignore update() calls before this time
    obj_id_t _objectId{0};       // unique object ID

protected:
    /**
     * Call this function in the body of the update function for Objects that don't need updating
     * @param now: current time in milliseconds
     * @return next update time, 24.8 days in the future
     */
    static inline update_t next_update_never(const update_t& now)
    {
        return now + std::numeric_limits<update_t>::max() / 2;
    }

    /**
     * Call this function in the body of the update function for Objects that don't need updating
     * @param now: current time in milliseconds
     * @return next update time, 24.8 days in the future
     */
    inline update_t next_update_1s(const update_t& now)
    {
        return now + 1000;
    }

public:
    Object() = default;
    virtual ~Object() = default;

    obj_id_t objectId() const
    {
        return _objectId;
    }

    void setObjectId(obj_id_t id)
    {
        _objectId = id;
    }

    /**
     * get the unique typeID of the Object
     * @return object type
     *
     */
    virtual obj_type_t typeId() const = 0;

    /**
     * Each object can yield its data.
     * A callback is provided so the return value can be processed immediately.
     * The yielded data should be compatible with write().
     */
    virtual CboxError read(const PayloadCallback& callback) const = 0;

    /**
     * Objects can yield data they want persisted.
     * A callback is provided so the return value can be processed immediately.
     * The yielded data should be compatible with write().
     */
    virtual CboxError readStored(const PayloadCallback& callback) const = 0;

    /**
     * Objects can receive incoming data.
     * This function should be compatible with data yielded from either read() or readStored().
     */
    virtual CboxError write(const Payload& payload) = 0;

    /**
     * Prompt object to load cached data if required.
     */
    virtual CboxError loadFromCache()
    {
        return CboxError::OK;
    }

    /**
     * checks whether the class implements a certain interface. If it does, it returns the this pointer implementing it
     * @param iface: typeId of the interface requested
     */
    virtual void* implements(obj_type_t iface) = 0;

    /**
     * update the object, returns timestamp at which the object wants to be updated again (in ms).
     * The default implementation permanently skips updates.
     */
    virtual update_t updateHandler(const update_t& now)
    {
        return next_update_never(now);
    }

    void update(update_t now)
    {
        const update_t overflowGuard = std::numeric_limits<update_t>::max() / 2;
        if (overflowGuard - now + _nextUpdateTime <= overflowGuard) {
            forcedUpdate(now);
        }
    }

    void forcedUpdate(update_t now)
    {
        _nextUpdateTime = updateHandler(now);
    }
};

} // end namespace cbox
