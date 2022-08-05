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
#include "cbox/Application.hpp"
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

    auto block = makeResult.value();

    // Add created block to the container
    status = getObjects().add(block, request.blockId);
    if (status != CboxError::OK) {
        return status;
    }

    // Save block settings to storage
    status = block->readStored(getStorage().saveObjectCallback);

    if (status != CboxError::OK) {
        getObjects().remove(block->objectId());
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

    auto fetched = getObjects().fetch(request.blockId);
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
    status = obj->readStored(getStorage().saveObjectCallback);

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
    auto fetched = getObjects().fetch(request.blockId);
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
    for (auto it = getObjects().cbegin(); (it < getObjects().cend() && status == CboxError::OK); it++) {
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

    status = getObjects().remove(id);
    getStorage().disposeObject(storageId);
    getCacheStorage().disposeObject(storageId);

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

CboxError clearBlocks(const PayloadCallback& callback)
{
    // remove user objects from storage
    for (auto cit = getObjects().usercbegin(); cit < getObjects().cend(); cit++) {
        auto& obj = *cit;
        auto id = obj->objectId();
        obj->read(callback); // do not early terminate on read error
        getStorage().disposeObject(id);
        getCacheStorage().disposeObject(id);
    }

    // remove all user objects from vector
    getObjects().clear();

    return CboxError::OK;
}

CboxError discoverBlocks(const PayloadCallback& callback)
{
    while (auto newObj = scan()) {
        auto status = getObjects().add(newObj);
        if (status != CboxError::OK) {
            return status;
        }

        status = newObj->readStored(getStorage().saveObjectCallback);
        if (status != CboxError::OK) {
            return status;
        }

        status = newObj->read(callback);
        if (status != CboxError::OK) {
            return status;
        }
    }
    return CboxError::OK;
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

        if (auto fetched = getObjects().fetch(payload.blockId)) {
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
                }
                return makeResult.error();
            }

            // Write desired settings to the newly created block
            status = makeResult.value()->write(payload);
            if (status != CboxError::OK) {
                return status;
            }

            getObjects().add(std::move(makeResult.value()), payload.blockId);
        }
        return status;
    });

    // add deprecated object placeholders at the end
    for (auto& id : deprecatedList) {
        getObjects().add(std::shared_ptr<Object>(new DeprecatedObject(id)));
    }

    getObjects().loadFromCache();
}

void unloadBlocks()
{
    getObjects().clearAll();
}

void update(update_t now)
{
    lastUpdateTime = now;
    getObjects().update(now);
}

void forcedUpdate(update_t now)
{
    lastUpdateTime = now;
    getObjects().forcedUpdate(now);
}

} // end namespace cbox
