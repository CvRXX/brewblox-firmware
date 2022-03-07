/*
 * Copyright 2018 Elco Jacobs / Brewblox.
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
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/Command.h"
#include "cbox/DataStream.h"
#include "cbox/Object.h"
#include <memory>

namespace cbox {

class DataInCommand : public Command {
public:
    DataInCommand(DataIn& in, size_t available, std::shared_ptr<Object> obj)
        : Command(0, CboxOpcode::NONE) // not relevant
    {
        std::vector<uint8_t> objData(available);
        in.readBytes(objData.data(), available);
        requestPayload.emplace(obj->objectId, obj->typeId(), 0, std::move(objData));
    }

    virtual ~DataInCommand() = default;

    virtual CboxError respond(const Payload&) override final
    {
        return CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }
};

class DataOutCommand : public Command {
private:
    DataOut& out;

public:
    DataOutCommand(DataOut& _out)
        : Command(0, CboxOpcode::NONE) // not relevant
        , out(_out)
    {
    }

    virtual ~DataOutCommand() = default;

    virtual CboxError respond(const Payload& payload) override final
    {
        auto success = out.writeBuffer(payload.content.data(), payload.content.size());
        return (success) ? CboxError::OK : CboxError::PERSISTED_STORAGE_WRITE_ERROR;
    }
};

std::pair<CboxError, std::shared_ptr<Object>>
createFromStream(RegionDataIn& in, obj_id_t objId);

CboxError loadFromStream(RegionDataIn& in, obj_id_t objId, std::shared_ptr<Object> obj);

CboxError readPersistedFromStream(RegionDataIn& in, obj_id_t objId, Command& cmd);

CboxError saveToStream(DataOut& out, obj_id_t objId, std::shared_ptr<Object> obj);

} // end namespace cbox
