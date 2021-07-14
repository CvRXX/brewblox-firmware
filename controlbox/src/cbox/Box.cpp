/*
 * Copyright 2019 BrewPi B.V. / Elco Jacobs
 * based on earlier work of Matthew McGowan.
 *
 * This file is part of BrewBlox.
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
 * along with Controlbox.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Box.h"

#include "CboxError.h"
#include "Connections.h"
#include "ContainedObject.h"
#include "DataStream.h"
#include "DataStreamConverters.h"
#include "DeprecatedObject.h"
#include "GroupsObject.h"
#include "Object.h"
#include "ObjectContainer.h"
#include "ObjectFactory.h"
#include "ObjectStorage.h"
#include "ScanningFactory.h"
#include "Tracing.h"
#include <memory>
#include <tuple>
#include <vector>

extern void
handleReset(bool exit, uint8_t reason);

namespace cbox {

Box::Box(const ObjectFactory& _factory,
         ObjectContainer& _objects,
         ObjectStorage& _storage,
         ConnectionPool& _connections,
         std::vector<std::unique_ptr<ScanningFactory>>&& _scanners)
    : factory(_factory)
    , objects(_objects)
    , storage(_storage)
    , connections(_connections)
    , scanners{std::move(_scanners)}
{
    objects.add(std::make_unique<GroupsObject>(this), 0x80, obj_id_t(1)); // add groups object to give access to the active groups setting on id 1
    objects.setObjectsStartId(userStartId());                             // set startId for user objects to 100
}

/**
 * The no-op command simply echoes the response until the end of stream.
 */
void Box::noop(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    out.writeResponseSeparator();
    out.write(asUint8(CboxError::OK));
}

/**
 * The no-op command simply echoes the response until the end of stream.
 */
void Box::invalidCommand(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    out.writeResponseSeparator();
    out.write(asUint8(CboxError::INVALID_COMMAND));
}

void Box::readObject(DataIn& in, EncodedDataOut& out)
{
    CboxError status = CboxError::OK;
    obj_id_t id = 0;
    ContainedObject* cobj = nullptr;
    if (!in.get(id)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    } else {
        cobj = objects.fetchContained(id);
        if (cobj == nullptr) {
            status = CboxError::INVALID_OBJECT_ID;
        }
    }

    in.spool();
    if (out.crc()) {
        status = CboxError::CRC_ERROR_IN_COMMAND;
    }
    out.writeResponseSeparator();
    out.write(asUint8(status));
    if (status == CboxError::OK) {
        // stream object as id, groups, typeId, data
        status = cobj->streamTo(out); // traced READ_OBJECT here
        if (status != CboxError::OK) {
            out.writeError(status);
            out.invalidateCrc();
        }
    }
}

void Box::writeObject(DataIn& in, EncodedDataOut& out)
{
    CboxError status = CboxError::OK;
    obj_id_t id = 0;
    ContainedObject* cobj = nullptr;
    if (!in.get(id)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    } else {
        cobj = objects.fetchContained(id);
        if (cobj == nullptr) {
            status = CboxError::INVALID_OBJECT_ID;
        }
    }

    // stream new settings to object
    if (cobj) {
        status = cobj->streamFrom(in);
    }

    in.spool();
    if (out.crc()) {
        status = CboxError::CRC_ERROR_IN_COMMAND;
    }

    if (cobj != nullptr && status == CboxError::OK) {
        // check if object was inactive and should become active
        if (cobj->object()->typeId() == InactiveObject::staticTypeId()
            && ((cobj->groups() & activeGroups) != 0)) {
            obj_id_t id = cobj->id();
            std::shared_ptr<Object> obj;

            bool handlerCalled = false;
            auto streamHandler = [this, &obj, &handlerCalled](RegionDataIn& objInStorage) -> CboxError {
                handlerCalled = true;
                RegionDataIn objWithoutCrc(objInStorage, objInStorage.available() - 1);

                uint8_t storedGroups; // discarded
                CboxError status;
                std::tie(status, obj, storedGroups) = createObjectFromStream(objWithoutCrc);

                return status;
            };
            status = storage.retrieveObject(storage_id_t(id), streamHandler);

            if (!handlerCalled) {
                status = CboxError::INVALID_OBJECT_ID; // write status if handler has not written it
            }
            if (status == CboxError::OK) {
                *cobj = ContainedObject(id, cobj->groups(), std::move(obj)); // replace contained object
            }
        }
        if (status == CboxError::OK) {
            // save new settings to storage
            auto storeContained = [&cobj](DataOut& storage) -> CboxError {
                return cobj->streamPersistedTo(storage);
            };
            status = storage.storeObject(id, storeContained);
        }

        // deactivate object if it is not a system object and is not in an active group
        if ((cobj->groups() & activeGroups) == 0) {
            cobj->deactivate();
        }
    }

    out.writeResponseSeparator();
    out.write(asUint8(status));
    if (cobj != nullptr && status == CboxError::OK) {
        cobj->forcedUpdate(lastUpdateTime); // force an update of the object
        status = cobj->streamTo(out);
        if (status != CboxError::OK) {
            out.writeError(status);
            out.invalidateCrc();
        }
    }
}

/**
 * Creates a new object by streaming in everything except the object id
 */
std::tuple<CboxError, std::shared_ptr<Object>, uint8_t>
Box::createObjectFromStream(DataIn& in)
{
    obj_type_t typeId;
    uint8_t groups;

    if (!in.get(groups)) {
        return std::make_tuple(CboxError::INPUT_STREAM_READ_ERROR, std::shared_ptr<Object>(), uint8_t(0)); // LCOV_EXCL_LINE
    }
    if (!in.get(typeId)) {
        return std::make_tuple(CboxError::INPUT_STREAM_READ_ERROR, std::shared_ptr<Object>(), uint8_t(0)); // LCOV_EXCL_LINE
    }

    auto retv = factory.make(typeId);
    auto result = std::get<0>(retv);
    auto obj = std::get<1>(retv);

    if (obj) {
        obj->streamFrom(in);
    }
    return std::make_tuple(std::move(result), std::move(obj), groups);
}

/**
 * Creates a new object and adds it to the container
 */
void Box::createObject(DataIn& in, EncodedDataOut& out)
{
    obj_id_t id;
    obj_type_t typeId;
    uint8_t groups = 0;

    CboxError status = CboxError::OK;

    if (!in.get(id)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    if (id > 0 && id < userStartId()) {
        status = CboxError::INVALID_OBJECT_ID;
    }

    std::shared_ptr<Object> newObj;
    if (status == CboxError::OK) {
        std::tie(status, newObj, groups) = createObjectFromStream(in);
    }

    in.spool();
    if (out.crc()) {
        status = CboxError::CRC_ERROR_IN_COMMAND;
    }
    ContainedObject* ptrCobj = nullptr;
    if (status == CboxError::OK) {
        // add object to container. Id is returned because id from stream can be 0 to let the box assign it
        id = objects.add(std::move(newObj), groups, id, false);
        ptrCobj = objects.fetchContained(id);
        if (ptrCobj) {
            auto storeContained = [&ptrCobj](DataOut& out) -> CboxError {
                return ptrCobj->streamPersistedTo(out);
            };
            status = storage.storeObject(id, storeContained);
            if (status != CboxError::OK) {
                objects.remove(id);
            } else if (id >= userStartId() && !(ptrCobj->groups() & activeGroups)) {
                // object should not be active, replace object with inactive object
                ptrCobj->deactivate();
            }
        } else {
            status = CboxError::INVALID_OBJECT_ID;
        }
    }
    out.writeResponseSeparator();
    out.write(asUint8(status));
    if (ptrCobj != nullptr && status == CboxError::OK) {
        ptrCobj->forcedUpdate(lastUpdateTime); // force an update of the object
        status = ptrCobj->streamTo(out);
        if (status != CboxError::OK) {
            out.writeError(status);
        }
    }
}

/**
 * Handles the delete object command.
 *
 */
void Box::deleteObject(DataIn& in, EncodedDataOut& out)
{
    CboxError status = CboxError::OK;
    obj_id_t id;

    if (!in.get(id)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    in.spool();
    if (out.crc()) {
        status = CboxError::CRC_ERROR_IN_COMMAND;
    }

    auto storageId = id;

    auto deprecated = makeCboxPtr<DeprecatedObject>(id);
    if (auto obj = deprecated.lock()) {
        // object is a deprecated one. We should delete the original object id from storage
        storageId = obj->storageId();
    }

    if (status == CboxError::OK) {
        status = objects.remove(id);
        storage.disposeObject(storageId);
    }

    out.writeResponseSeparator();
    out.write(asUint8(status));
}

/**
 * Walks the object container and lists all objects.
 */
void Box::listActiveObjects(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }

    out.write(asUint8(CboxError::OK));
    for (auto it = objects.cbegin(); it < objects.cend(); it++) {
        out.writeListSeparator();
        it->streamTo(out);
    }
}

/**
 * Walks the object container and lists all objects that implement a certain interface
 */
void Box::listCompatibleObjects(DataIn& in, EncodedDataOut& out)
{
    CboxError status = CboxError::OK;
    obj_type_t interfaceType = 0;
    if (!in.get(interfaceType)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }

    out.write(asUint8(status));
    for (auto it = objects.cbegin(); it < objects.cend(); it++) {
        if (it->object()->implements(interfaceType)) {
            out.writeListSeparator();
            out.put(it->id());
        }
    }
}

void Box::readStoredObject(DataIn& in, EncodedDataOut& out)
{
    CboxError status = CboxError::OK;
    obj_id_t id = 0;

    if (!in.get(id)) {
        status = CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        status = CboxError::CRC_ERROR_IN_COMMAND;
    }

    if (status != CboxError::OK) {
        out.write(asUint8(status));
        return;
    }

    bool handlerCalled = false;
    auto objectStreamer = [&out, &id, &handlerCalled](RegionDataIn& objInStorage) -> CboxError {
        out.write(asUint8(CboxError::OK));
        out.put(id);
        handlerCalled = true;
        RegionDataIn objWithoutCrc(objInStorage, objInStorage.available() - 1);
        if (objWithoutCrc.push(out) != CboxError::OK) {
            return CboxError::OUTPUT_STREAM_WRITE_ERROR; // LCOV_EXCL_LINE;
        }
        return CboxError::OK;
    };
    status = storage.retrieveObject(storage_id_t(id), objectStreamer);
    if (!handlerCalled) {
        out.write(asUint8(CboxError::PERSISTED_OBJECT_NOT_FOUND)); // write status if handler has not written it
    } else if (status != CboxError::OK) {
        out.writeError(status); // write error as event, because objectStreamer has already written a status
    }
}

void Box::listStoredObjects(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }
    out.write(asUint8(CboxError::OK));
    auto listObjectStreamer = [&out](const storage_id_t& id, RegionDataIn& objInStorage) -> CboxError {
        out.writeListSeparator();
        obj_id_t objId(id);
        RegionDataIn objWithoutCrc(objInStorage, objInStorage.available() - 1);
        if (!out.put(id)) {
            return CboxError::OUTPUT_STREAM_WRITE_ERROR; // LCOV_EXCL_LINE
        }
        return objWithoutCrc.push(out);
    };
    storage.retrieveObjects(listObjectStreamer);
}

// load all objects from storage
void Box::loadObjectsFromStorage()
{
    // keep a list of deprecated objects so we can add them after all other objects
    // they get a new ID, if use the next free ID before all other objects are processed
    // then they can take an ID that is in use by an object loader later
    std::vector<obj_id_t> deprecatedList;

    const auto objectLoader = [this, &deprecatedList](storage_id_t id, RegionDataIn& objInStorage) -> CboxError {
        obj_id_t objId = obj_id_t(id);
        CboxError status = CboxError::OK;

        tracing::add(tracing::Action::LOAD_STORED_OBJECT, objId, obj_type_t(0));

        // use a CrcDataOut to a black hole to check the CRC
        BlackholeDataOut hole;
        CrcDataOut crcCalculator(hole);
        TeeDataIn tee(objInStorage, crcCalculator);
        crcCalculator.put(id); // id is part of CRC, but not part of the stream we get from storage

        if (auto ptrCobj = objects.fetchContained(objId)) {
            // existing object
            status = ptrCobj->streamFrom(tee);

            tee.spool();
            if (crcCalculator.crc() != 0) {
                return CboxError::CRC_ERROR_IN_STORED_OBJECT;
            }

        } else {
            // new object
            uint8_t groups;
            std::shared_ptr<Object> newObj;

            std::tie(status, newObj, groups) = createObjectFromStream(tee);

            tee.spool();
            if (crcCalculator.crc() != 0) {
                return CboxError::CRC_ERROR_IN_STORED_OBJECT;
            }

            if (newObj) {
                objects.add(std::move(newObj), groups, id);
            } else if (status == CboxError::OBJECT_NOT_CREATABLE) {
                deprecatedList.emplace_back(id);
                status = CboxError::OK;
            }
        }
        return status;
    };
    // now apply the loader above to all objects in storage
    storage.retrieveObjects(objectLoader);

    // add deprecated object placeholders at the end
    for (auto& id : deprecatedList) {
        objects.add(std::make_shared<DeprecatedObject>(id), 0xFF);
    }

    // finally, deactivate objects that should not be active based on the (possibly just loaded) active groups setting
    setActiveGroupsAndUpdateObjects(activeGroups);
}

void Box::reboot(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }

    out.write(asUint8(CboxError::OK));

    ::handleReset(true, 2);
}

void Box::factoryReset(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }
    out.write(asUint8(CboxError::OK));
    storage.clear();

    ::handleReset(true, 3);
}

/**
 * Handles the delete all objects command.
 *
 */

void Box::clearObjects(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }

    // remove user objects from storage
    auto cit = objects.userbegin();
    while (cit != objects.cend()) {
        auto id = cit->id();
        cit++;
        bool mergeDisposed = cit == objects.cend(); // merge disposed blocks on last delete
        storage.disposeObject(id, mergeDisposed);
    }

    // remove all user objects from vector
    objects.clear();

    out.write(asUint8(CboxError::OK));
}

/**
 * Search scannable buses for new objects and create them
 *
 */

void Box::discoverNewObjects(DataIn& in, EncodedDataOut& out)
{
    in.spool();
    auto crc = out.crc();

    out.writeResponseSeparator();

    if (crc) {
        out.write(asUint8(CboxError::CRC_ERROR_IN_COMMAND));
        return;
    }

    out.write(asUint8(CboxError::OK));

    for (auto& scanner : scanners) {
        scanner->reset();
        auto newId = obj_id_t(0);
        do {
            newId = scanner->scanAndAdd(objects);
            if (newId) {
                auto cobj = objects.fetchContained(newId);

                out.writeListSeparator();
                out.put(newId);
                if (cobj != nullptr) { // always true,  but just in case
                    out.put(cobj->object()->typeId());
                    auto storeContained = [&cobj](DataOut& out) -> CboxError {
                        return cobj->streamPersistedTo(out);
                    };
                    storage.storeObject(newId, storeContained);
                }
            }
        } while (newId);
    }
}

void Box::discoverNewObjects()
{
    for (auto& scanner : scanners) {
        scanner->reset();
        auto newId = obj_id_t(0);
        do {
            newId = scanner->scanAndAdd(objects);
        } while (newId);
    }
}

/*
 * Processes the command request from a data stream.
 * @param dataIn The request data. The first byte is the command id. The stream is assumed to contain at least
 *   this data.
 */
void Box::handleCommand(DataIn& dataIn, DataOut& dataOut)
{
    HexTextToBinaryIn hexIn(dataIn);
    EncodedDataOut out(dataOut); // hex encodes and adds CRC after response, supports protocol special characters
    TeeDataIn in(hexIn, out);    // ensure command input is also echoed to output
    uint16_t msg_id;
    in.get(msg_id); // get and echo message id back

    auto cmd_id = in.read(); // get command type code

    if (cmd_id < 100) {
        tracing::add(tracing::Action(cmd_id)); // non-custom commands trace that they are invoked
        switch (cmd_id) {
        case NONE:
            connectionStarted(dataOut); // insert welcome message annotation
            noop(in, out);
            break;
        case READ_OBJECT:
            readObject(in, out);
            break;
        case WRITE_OBJECT:
            writeObject(in, out);
            break;
        case CREATE_OBJECT:
            createObject(in, out);
            break;
        case DELETE_OBJECT:
            deleteObject(in, out);
            break;
        case LIST_ACTIVE_OBJECTS:
            listActiveObjects(in, out);
            break;
        case READ_STORED_OBJECT:
            readStoredObject(in, out);
            break;
        case LIST_STORED_OBJECTS:
            listStoredObjects(in, out);
            break;
        case CLEAR_OBJECTS:
            clearObjects(in, out);
            break;
        case REBOOT:
            reboot(in, out);
            break;
        case FACTORY_RESET:
            factoryReset(in, out);
            break;
        case LIST_COMPATIBLE_OBJECTS:
            listCompatibleObjects(in, out);
            break;
        case DISCOVER_NEW_OBJECTS:
            discoverNewObjects(in, out);
            break;
        default:
            invalidCommand(in, out);
            break;
        }
    } else {
        bool validCommand = applicationCommand(cmd_id, in, out);
        if (!validCommand) {
            invalidCommand(in, out);
        }
    }

    hexIn.consumeLineEnd(); // consumes any leftover \r or \n

    out.endMessage();
}

void Box::hexCommunicate()
{
    connections.process([this](DataIn& in, DataOut& out) {
        while (in.peek() >= 0) {
            this->handleCommand(in, out);
        }
    });
}

void Box::parseMessage(DataIn& in, DataOut& out)
{
    handleCommand(in, out);
}

void Box::setActiveGroupsAndUpdateObjects(const uint8_t newGroups)
{
    activeGroups = newGroups | 0x80; // system group cannot be disabled
    for (auto cit = objects.userbegin(); cit != objects.cend(); cit++) {
        obj_id_t objId = cit->id();
        uint8_t objGroups = cit->groups();
        obj_type_t objType = cit->object()->typeId();

        bool shouldBeActive = activeGroups & objGroups;

        // replace entire 'contained object', not just the object inside.
        // this ensures that any smart pointers to the contained object are also invalidated

        if (shouldBeActive && objType == InactiveObject::staticTypeId()) {
            // look for object in storage and replace existing object with it
            auto retrieveContained = [this, &objId](RegionDataIn& objInStorage) -> CboxError {
                CboxError status;
                std::shared_ptr<Object> newObj;
                uint8_t groups = 0;

                // use a CrcDataOut to a black hole to check the CRC
                BlackholeDataOut hole;
                CrcDataOut crcCalculator(hole);
                TeeDataIn tee(objInStorage, crcCalculator);

                crcCalculator.put(objId); // id is part of CRC, but not part of the stream we get from storage
                std::tie(status, newObj, groups) = createObjectFromStream(tee);

                tee.spool();
                if (crcCalculator.crc() != 0) {
                    return CboxError::CRC_ERROR_IN_STORED_OBJECT;
                }

                if (newObj) {
                    objects.add(std::move(newObj), groups, objId, true);
                }

                return status;
            };

            CboxError status = storage.retrieveObject(storage_id_t(objId), retrieveContained);
            if (status != CboxError::OK) {
                // TODO emit log event about reloading object from storage failing?
            }
        }

        if (!shouldBeActive && objType != InactiveObject::staticTypeId()) {
            // replace object with inactive object
            objects.deactivate(cit);
        }
    }
}

CboxError
Box::storeUpdatedObject(const obj_id_t& id) const
{
    return objects.store(id);
}

CboxError
Box::reloadStoredObject(const obj_id_t& id)
{
    return objects.reloadStored(id);
}

} // end namespace cbox
