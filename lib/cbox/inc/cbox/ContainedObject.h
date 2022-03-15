/*
 * Copyright 2018 Elco Jacobs / Brewblox
 *
 * This file is part of Brewblox
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

#include "cbox/DataStream.h"
#include "cbox/Object.h"
#include <limits>
#include <memory>

namespace cbox {

/**
 * A wrapper around an object that stores which type it is and in which groups it is active
 */
class ContainedObject {
public:
    explicit ContainedObject(obj_id_t id, std::shared_ptr<Object>&& obj)
        : _id(std::move(id))
        , _obj(std::move(obj))
        , _nextUpdateTime(0)
    {
        if (_obj) {
            _obj->objectId = _id;
        }
    }

    // don't allow construction from derived shared ptr
    // this creates code bloat. It is better to use shared_ptr<Object>(new Derived()) directly than to convert from make_shared<Derived>()
    template <typename T>
    explicit ContainedObject(obj_id_t id, std::shared_ptr<T>&& obj) = delete;

    virtual ~ContainedObject() = default;

    ContainedObject(const ContainedObject&) = default;           // no copy
    ContainedObject& operator=(const ContainedObject&) = delete; // no copy
    ContainedObject(ContainedObject&&) = default;                // move allowed
    ContainedObject& operator=(ContainedObject&&) = default;     // move allowed

private:
    obj_id_t _id;                 // unique id of object
    std::shared_ptr<Object> _obj; // pointer to runtime object
    update_t _nextUpdateTime;     // next time update should be called on _obj

public:
    const obj_id_t& id() const
    {
        return _id;
    }

    const std::shared_ptr<Object>& object() const
    {
        return _obj;
    }

    void update(const update_t& now)
    {
        const update_t overflowGuard = std::numeric_limits<update_t>::max() / 2;
        if (overflowGuard - now + _nextUpdateTime <= overflowGuard) {
            forcedUpdate(now);
        }
    }

    void forcedUpdate(const uint32_t& now)
    {
        if (_obj) {
            _nextUpdateTime = _obj->update(now);
            return;
        }
        _nextUpdateTime += 1000;
    }

    CboxError toResponse(Command& cmd) const
    {
        if (!_obj) {
            return CboxError::INVALID_BLOCK_ID;
        }

        return _obj->toResponse(cmd);
    }

    CboxError toStoredResponse(Command& cmd) const
    {
        if (!_obj) {
            return CboxError::INVALID_BLOCK_ID;
        }

        return _obj->toStoredResponse(cmd);
    }

    CboxError fromRequest(Command& cmd)
    {
        if (!_obj) {
            return CboxError::INVALID_BLOCK_ID;
        }

        return _obj->fromRequest(cmd);
    }
};

} // end namespace cbox
