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
static constexpr update_t MAX_UPDATE_INTERVAL = std::numeric_limits<update_t>::max() / 2;

class Object;

// any type can be assigned a typeid by explicit template instantiation
// this allows objects to implement returning a pointer for that type, without needing to inherit from it
template <typename T>
obj_type_t interfaceIdImpl();

// for objects, the object id is the interface id
template <typename T>
constexpr obj_type_t interfaceId(typename std::enable_if_t<std::is_base_of<Object, T>::value>* = 0)
{
    return T::staticTypeId();
}

#if !defined(PLATFORM_ID) || PLATFORM_ID == 3 // check that ID is unique if building for cross platform (tests)
uint16_t throwIdNotUnique(uint16_t id);
#endif

// for interface, we check uniqueness on first use, if compiling with gcc (test code)
template <typename T>
obj_type_t interfaceId(typename std::enable_if_t<!std::is_base_of<Object, T>::value>* = 0)
{
#if !defined(PLATFORM_ID) || PLATFORM_ID == 3
    static auto uniqueId = throwIdNotUnique(interfaceIdImpl<T>());
    return uniqueId;

#else

    return interfaceIdImpl<T>();
#endif
}

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
        return now + MAX_UPDATE_INTERVAL;
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

    void resetNextUpdateTime()
    {
        _nextUpdateTime = 0;
    }

private:
    /**
     * checks whether the class implements a certain interface. If it does, it returns the this pointer implementing it
     * @param iface: typeId of the interface requested
     */
    virtual void* implements(obj_type_t iface) = 0;

    const void* implements(obj_type_t iface) const
    {
        return const_cast<Object*>(this)->implements(iface);
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

    template <typename T>
    T* asInterface()
    {
        return reinterpret_cast<T*>(implements(interfaceId<T>()));
    }

    template <typename T>
    const T* asInterface() const
    {
        return reinterpret_cast<const T*>(implements(interfaceId<T>()));
    }

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
        if (_nextUpdateTime == 0 || MAX_UPDATE_INTERVAL - now + _nextUpdateTime <= MAX_UPDATE_INTERVAL) {
            _nextUpdateTime = updateHandler(now);
        }
    }

    void forcedUpdate(update_t now)
    {
        _nextUpdateTime = 0;
        update(now);
    }
};

} // end namespace cbox
