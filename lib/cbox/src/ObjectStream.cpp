/*
 * Copyright 2022 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
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

#include "cbox/ObjectStream.h"
#include "cbox/CboxApplication.h"
#include "cbox/Tracing.h"

namespace cbox {

std::pair<CboxError, std::shared_ptr<Object>>
createFromStream(RegionDataIn& in, obj_id_t objId)
{
    CboxError status = CboxError::OK;
    obj_type_t typeId;
    uint8_t flags; // previously the groups byte, now unused and reserved

    tracing::add(tracing::Action::LOAD_STORED_OBJECT, objId, typeId);

    // use a CrcDataOut to a black hole to check the CRC
    BlackholeDataOut hole;
    CrcDataOut crcCalculator(hole);
    TeeDataIn tee(in, crcCalculator);

    // id is part of CRC, but not part of the stream we get from storage
    crcCalculator.put(objId);

    if (!tee.get(flags)) {
        return std::make_pair(CboxError::INPUT_STREAM_READ_ERROR, std::shared_ptr<Object>()); // LCOV_EXCL_LINE
    }

    if (!tee.get(typeId)) {
        return std::make_pair(CboxError::INPUT_STREAM_READ_ERROR, std::shared_ptr<Object>()); // LCOV_EXCL_LINE
    }

    auto makeResult = make(typeId);
    auto obj = std::get<1>(makeResult);
    status = std::get<0>(makeResult);

    if (status != CboxError::OK) {
        return std::make_pair(std::move(status), std::shared_ptr<Object>());
    }

    if (!obj) {
        // If make result is OK, we really expect an object, but check anyway
        return std::make_pair(CboxError::UNKNOWN_ERROR, std::shared_ptr<Object>()); // LCOV_EXCL_LINE
    }

    // The command will immediately collect data bytes
    // The last byte is the CRC, and should not be included
    DataInCommand inCmd(tee, in.available() - 1, obj);

    // Read the CRC byte, and check the total
    tee.spool();
    if (crcCalculator.crc() != 0) {
        return std::make_pair(CboxError::CRC_ERROR_IN_STORED_OBJECT, std::shared_ptr<Object>());
    }

    // CRC is OK, write data to object
    obj->objectId = objId;
    status = obj->write(inCmd);

    return std::make_pair(std::move(status), std::move(obj));
}

CboxError loadFromStream(RegionDataIn& in, obj_id_t objId, std::shared_ptr<Object> obj)
{
    if (!obj) {
        return CboxError::INVALID_OBJECT_PTR;
    }

    tracing::add(tracing::Action::STREAM_FROM_OBJECT, objId, obj->typeId());

    // use a CrcDataOut to a black hole to check the CRC
    BlackholeDataOut hole;
    CrcDataOut crcCalculator(hole);
    TeeDataIn tee(in, crcCalculator);

    // id is part of CRC, but not part of the stream we get from storage
    crcCalculator.put(objId);

    uint8_t flags; // previously the groups byte, now unused and reserved
    obj_type_t inType;

    if (!tee.get(flags)) {
        return CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    if (!tee.get(inType)) {
        return CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    if (inType != obj->typeId()) {
        return CboxError::INVALID_OBJECT_TYPE;
    }

    // The command will immediately collect data bytes
    // The last byte is the CRC, and should not be included
    DataInCommand inCmd(tee, in.available() - 1, obj);

    // Read the CRC byte, and check the total
    tee.spool();
    if (crcCalculator.crc() != 0) {
        return CboxError::CRC_ERROR_IN_STORED_OBJECT;
    }

    obj->objectId = objId;
    return obj->write(inCmd);
}

CboxError readPersistedFromStream(RegionDataIn& in, obj_id_t objId, Command& cmd)
{
    // use a CrcDataOut to a black hole to check the CRC
    BlackholeDataOut hole;
    CrcDataOut crcCalculator(hole);
    TeeDataIn tee(in, crcCalculator);

    // id is part of CRC, but not part of the stream we get from storage
    crcCalculator.put(objId);

    uint8_t flags; // previously the groups byte, now unused and reserved
    obj_type_t inType;

    if (!tee.get(flags)) {
        return CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    if (!tee.get(inType)) {
        return CboxError::INPUT_STREAM_READ_ERROR; // LCOV_EXCL_LINE
    }

    // Grab all data except the last byte
    // The last byte is the CRC, and should not be included
    auto len = in.available() - 1;
    Payload resp(objId, inType, 0);
    resp.content.resize(len);
    tee.readBytes(resp.content.data(), len);

    // Read the CRC byte, and check the total
    tee.spool();
    if (crcCalculator.crc() != 0) {
        return CboxError::CRC_ERROR_IN_STORED_OBJECT;
    }

    return cmd.respond(resp);
}

CboxError saveToStream(DataOut& out, obj_id_t objId, std::shared_ptr<Object> obj)
{
    if (!obj) {
        return CboxError::INVALID_OBJECT_PTR;
    }

    tracing::add(tracing::Action::PERSIST_OBJECT, objId, obj->typeId());

    // id is not streamed out. It is passed to storage separately

    uint8_t flags(0); // previously the groups byte, now unused and reserved
    if (!out.put(flags)) {
        return CboxError::PERSISTED_STORAGE_WRITE_ERROR; // LCOV_EXCL_LINE
    }

    if (!out.put(obj->typeId())) {
        return CboxError::PERSISTED_STORAGE_WRITE_ERROR; // LCOV_EXCL_LINE
    }

    // TODO(Bob): CRC handling is asymmetric
    // When loading, it is checked here, but when saving, it is added in storage
    DataOutCommand outCmd(out);
    return obj->readPersisted(outCmd);
}

} // end namespace cbox
