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

#include "cbox/Box.hpp"
#include "cbox/CboxError.hpp"
#include "cbox/CboxPtr.hpp"
#include "cbox/DeprecatedObject.hpp"
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectFactory.hpp"
#include "cbox/ObjectStorage.hpp"
#include "cbox/ScanningFactory.hpp"

#include <memory>
#include <tuple>
#include <vector>

namespace cbox {

ObjectContainer objects;

update_t lastUpdateTime = 0;

CboxError createBlock(const Payload& request, const PayloadCallback& callback)
{
    CboxError status = CboxError::OK;

    // Check if any factory can make this type
    auto makeResult = make(request.blockType);
    if (!makeResult) {
        return makeResult.error();
    }

    // Write desired settings to the newly created block
    status = makeResult.value()->write(request);
    if (status != CboxError::OK) {
        return status;
    }

    // Add created block to the container
    auto addResult = objects.add(std::move(makeResult.value()), request.blockId);
    if (!addResult) {
        return addResult.error();
    }

    auto block = addResult.value();

    // Save block settings to storage
    status = block->readStored([](const Payload& stored) {
        return getStorage().saveObject(stored);
    });

    if (status != CboxError::OK) {
        objects.remove(block->objectId());
        return status;
    }

    // Update and read block
    block->forcedUpdate(lastUpdateTime);
    status = block->read(callback);

    return status;
}

CboxError writeBlock(const Payload& request, const PayloadCallback& callback)
{
    CboxError status = CboxError::OK;

    auto fetched = objects.fetch(request.blockId);
    if (!fetched) {
        return fetched.error();
    }
    auto obj = fetched.value();

    if (request.blockType != obj->typeId()) {
        return CboxError::INVALID_BLOCK_TYPE;
    }

    // Write new settings to block
    status = obj->write(request);
    if (status != CboxError::OK) {
        return status;
    }

    // Save updated settings to storage
    status = obj->readStored([](const Payload& stored) {
        return getStorage().saveObject(stored);
    });

    if (status != CboxError::OK) {
        return status;
    }

    // Update and read block
    obj->forcedUpdate(lastUpdateTime);
    status = obj->read(callback);

    return status;
}

CboxError readBlock(const Payload& request, const PayloadCallback& callback)
{
    auto fetched = objects.fetch(request.blockId);
    if (!fetched) {
        return fetched.error();
    }
    auto obj = fetched.value();

    if (request.blockType != 0 && request.blockType != obj->typeId()) {
        return CboxError::INVALID_BLOCK_TYPE;
    }

    auto status = obj->read(callback);
    return status;
}

CboxError readAllBlocks(const PayloadCallback& callback)
{
    CboxError status = CboxError::OK;
    for (auto it = objects.cbegin(); (it < objects.cend() && status == CboxError::OK); it++) {
        status = (*it)->read(callback);
    }
    return status;
}

CboxError deleteBlock(const Payload& request)
{
    CboxError status = CboxError::OK;

    obj_id_t id(request.blockId);
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

CboxError readStoredBlock(const Payload& request, const PayloadCallback& callback)
{
    return getStorage().loadObject(request.blockId, callback);
}

CboxError readAllStoredBlocks(const PayloadCallback& callback)
{
    return getStorage().loadAllObjects(callback);
}

CboxError clearBlocks()
{
    // remove user objects from storage
    auto cit = objects.userbegin();
    while (cit != objects.cend()) {
        auto id = (*cit)->objectId();
        cit++;
        bool mergeDisposed = cit == objects.cend(); // merge disposed blocks on last delete
        getStorage().disposeObject(id, mergeDisposed);
    }

    // remove all user objects from vector
    objects.clear();

    return CboxError::OK;
}

CboxError discoverBlocks(const PayloadCallback& callback)
{
    CboxError status = CboxError::OK;
    while (auto newObj = scan()) {
        if (objects.add(std::move(newObj))) {
            status = newObj->readStored([](const Payload& stored) {
                return getStorage().saveObject(stored);
            });
            if (status != CboxError::OK) {
                return status;
            }
            status = newObj->read(callback);
            if (status != CboxError::OK) {
                return status;
            }
        }
    }
    return status;
}

CboxError discoverBlocks()
{
    return discoverBlocks([](const Payload&) {
        return CboxError::OK;
    });
}

void loadBlocksFromStorage()
{
    // keep a list of deprecated objects so we can add them after all other objects
    // they get a new ID, if use the next free ID before all other objects are processed
    // then they can take an ID that is in use by an object loader later
    std::vector<obj_id_t> deprecatedList;

    // now apply the loader above to all objects in storage
    getStorage().loadAllObjects([&deprecatedList](const Payload& payload) -> CboxError {
        CboxError status = CboxError::OK;

        if (auto fetched = objects.fetch(payload.blockId)) {
            // existing object
            status = fetched.value()->write(payload);
        } else {
            // new object

            // Check if any factory can make this type
            auto makeResult = make(payload.blockType);
            if (!makeResult) {
                if (makeResult.error() == CboxError::BLOCK_NOT_CREATABLE) {
                    deprecatedList.push_back(payload.blockId);
                    return CboxError::OK;
                } else {
                    return makeResult.error();
                }
            }

            // Write desired settings to the newly created block
            status = makeResult.value()->write(payload);
            if (status != CboxError::OK) {
                return status;
            }

            objects.add(std::move(makeResult.value()), payload.blockId);
        }
        return status;
    });

    // add deprecated object placeholders at the end
    for (auto& id : deprecatedList) {
        objects.add(std::shared_ptr<Object>(new DeprecatedObject(id)));
    }
}

void unloadBlocks()
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
