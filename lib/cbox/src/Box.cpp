/*
 * Copyright 2019 BrewPi B.V. / Elco Jacobs
 * based on earlier work of Matthew McGowan.
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

#include "cbox/Box.h"
#include "cbox/CboxError.h"
#include "cbox/CboxPtr.h"
#include "cbox/Connections.h"
#include "cbox/ContainedObject.h"
#include "cbox/DataStream.h"
#include "cbox/DataStreamConverters.h"
#include "cbox/DeprecatedObject.h"
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/ObjectStorage.h"
#include "cbox/ObjectStream.h"
#include "cbox/ScanningFactory.hpp"

#include <memory>
#include <tuple>
#include <vector>

namespace cbox {

ObjectContainer objects;

update_t lastUpdateTime = 0;

CboxError readObject(Command& cmd)
{
    if (!cmd.request()) {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    ContainedObject* cobj = objects.fetchContained(cmd.request()->blockId);
    if (cobj == nullptr) {
        return CboxError::INVALID_OBJECT_ID;
    }

    auto status = cobj->read(cmd);
    return status;
}

CboxError writeObject(Command& cmd)
{
    CboxError status = CboxError::OK;

    if (!cmd.request()) {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    ContainedObject* cobj = objects.fetchContained(cmd.request()->blockId);
    if (cobj == nullptr) {
        return CboxError::INVALID_OBJECT_ID;
    }

    if (cmd.request()->blockType != cobj->object()->typeId()) {
        return CboxError::INVALID_OBJECT_TYPE;
    }

    status = cobj->write(cmd);
    if (status != CboxError::OK) {
        return status;
    }

    // save new settings to storage
    auto storeContained = [&cobj](DataOut& out) -> CboxError {
        return saveToStream(out, cobj->id(), cobj->object());
    };
    status = getStorage().storeObject(cobj->id(), storeContained);
    if (status != CboxError::OK) {
        return status;
    }

    cobj->forcedUpdate(lastUpdateTime);
    return cobj->read(cmd);
}

CboxError createObject(Command& cmd)
{
    CboxError status = CboxError::OK;

    if (!cmd.request()) {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    obj_id_t id(cmd.request()->blockId);
    obj_type_t typeId(cmd.request()->blockType);

    if (id > 0 && id < objects.getObjectsStartId()) {
        return CboxError::INVALID_OBJECT_ID;
    }

    auto makeResult = make(typeId);
    status = std::get<0>(makeResult);
    auto newObj = std::get<1>(makeResult);

    if (newObj) {
        status = newObj->write(cmd);
    }

    if (status != CboxError::OK) {
        return status;
    }

    // add object to container. Id is returned because id from command can be 0 to let the box assign it
    id = objects.add(std::move(newObj), id, false);
    ContainedObject* cobj = objects.fetchContained(id);

    if (cobj == nullptr) {
        return CboxError::INVALID_OBJECT_ID;
    }

    // persist newly created object to storage
    auto storeContained = [&cobj, &id](DataOut& out) -> CboxError {
        return saveToStream(out, id, cobj->object());
    };
    status = getStorage().storeObject(id, storeContained);
    if (status != CboxError::OK) {
        objects.remove(id);
        return status;
    }

    // immediately trigger an update
    cobj->forcedUpdate(lastUpdateTime);
    status = cobj->read(cmd);

    return status;
}

CboxError deleteObject(Command& cmd)
{
    CboxError status = CboxError::OK;

    if (!cmd.request()) {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    obj_id_t id(cmd.request()->blockId);
    obj_id_t storageId = id;

    auto deprecated = CboxPtr<DeprecatedObject>(id);
    if (auto obj = deprecated.lock()) {
        // object is a deprecated one. We should delete the original object id from storage
        storageId = obj->storageId();
    }

    status = objects.remove(id);
    getStorage().disposeObject(storageId);

    return status;
}

CboxError listActiveObjects(Command& cmd)
{
    CboxError status = CboxError::OK;
    for (auto it = objects.cbegin(); (it < objects.cend() && status == CboxError::OK); it++) {
        status = it->read(cmd);
    }
    return status;
}

CboxError readStoredObject(Command& cmd)
{
    if (!cmd.request()) {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    auto objId = cmd.request()->blockId;

    const auto loader = [&cmd, &objId](RegionDataIn& in) -> CboxError {
        return readPersistedFromStream(in, objId, cmd);
    };
    return getStorage().retrieveObject(objId, loader);
}

CboxError listStoredObjects(Command& cmd)
{
    const auto objectLoader = [&cmd](storage_id_t id, RegionDataIn& in) -> CboxError {
        return readPersistedFromStream(in, id, cmd);
    };
    return getStorage().retrieveObjects(objectLoader);
}

CboxError clearObjects(Command&)
{
    // remove user objects from storage
    auto cit = objects.userbegin();
    while (cit != objects.cend()) {
        auto id = cit->id();
        cit++;
        bool mergeDisposed = cit == objects.cend(); // merge disposed blocks on last delete
        getStorage().disposeObject(id, mergeDisposed);
    }

    // remove all user objects from vector
    objects.clear();

    return CboxError::OK;
}

CboxError discoverNewObjects(Command& cmd)
{
    CboxError status = CboxError::OK;
    while (auto newObj = scan()) {
        auto newId = objects.add(std::move(newObj));
        auto cobj = objects.fetchContained(newId);

        if (cobj != nullptr) { // always true, but just in case
            status = cobj->read(cmd);
            if (status != CboxError::OK) {
                return status;
            }

            auto storeContained = [&cobj, &newId](DataOut& out) -> CboxError {
                return saveToStream(out, newId, cobj->object());
            };
            status = getStorage().storeObject(newId, storeContained);
            if (status != CboxError::OK) {
                return status;
            }
        }
    }
    return status;
}

CboxError discoverNewObjects()
{
    StubCommand cmd;
    return discoverNewObjects(cmd);
}

void loadObjectsFromStorage()
{
    // keep a list of deprecated objects so we can add them after all other objects
    // they get a new ID, if use the next free ID before all other objects are processed
    // then they can take an ID that is in use by an object loader later
    std::vector<obj_id_t> deprecatedList;

    const auto objectLoader = [&deprecatedList](storage_id_t id, RegionDataIn& in) -> CboxError {
        obj_id_t objId = obj_id_t(id);
        CboxError status = CboxError::OK;

        if (auto cobj = objects.fetchContained(objId)) {
            // existing object
            status = loadFromStream(in, objId, cobj->object());
        } else {
            // new object
            auto created = createFromStream(in, objId);
            auto newObj = created.second;
            status = created.first;

            if (status == CboxError::OBJECT_NOT_CREATABLE) {
                deprecatedList.emplace_back(id);
                status = CboxError::OK;
            }

            if (status != CboxError::OK) {
                return status;
            }

            if (newObj) {
                objects.add(std::move(newObj), id);
            }
        }
        return status;
    };
    // now apply the loader above to all objects in storage
    getStorage().retrieveObjects(objectLoader);

    // add deprecated object placeholders at the end
    for (auto& id : deprecatedList) {
        objects.add(std::shared_ptr<Object>(new DeprecatedObject(id)), 0xFF);
    }
}

void unloadAllObjects()
{
    objects.clearAll();
}

void update(const update_t& now)
{
    lastUpdateTime = now;
    objects.update(now);
}

void forcedUpdate(const update_t& now)
{
    lastUpdateTime = now;
    objects.forcedUpdate(now);
}

} // end namespace cbox
