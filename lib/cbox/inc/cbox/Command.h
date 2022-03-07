/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 Brewblox / Elco Jacobs
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
#include "cbox/CboxOpcode.h"
#include "cbox/ObjectIds.h"
#include <optional>
#include <vector>

namespace cbox {

class Payload {
public:
    const obj_id_t blockId;
    const obj_type_t blockType;
    const uint16_t subtype;
    std::vector<uint8_t> content;

    Payload(obj_id_t _blockId,
            obj_type_t _blockType,
            uint16_t _subtype,
            std::vector<uint8_t>&& _content)
        : blockId(_blockId)
        , blockType(_blockType)
        , subtype(_subtype)
        , content(std::move(_content))
    {
    }

    Payload(obj_id_t _blockId,
            obj_type_t _blockType,
            uint16_t _subtype)
        : blockId(_blockId)
        , blockType(_blockType)
        , subtype(_subtype)
    {
    }

    virtual ~Payload() = default;
};

class Command {
public:
    const uint32_t msgId;
    const CboxOpcode opcode;
    std::optional<Payload> requestPayload;

    Command(uint32_t _msgId,
            CboxOpcode _opcode,
            std::optional<Payload>&& _requestPayload = std::nullopt)
        : msgId(_msgId)
        , opcode(_opcode)
        , requestPayload(std::move(_requestPayload))
    {
    }

    Command(const Command&) = delete;
    Command(Command&&) = delete;
    Command& operator=(const Command&) = delete;

    virtual ~Command() = default;

    virtual CboxError respond(const Payload& payload) = 0;
};

class StubCommand : public Command {
public:
    StubCommand()
        : Command(0, CboxOpcode::NONE)
    {
    }

    virtual ~StubCommand() = default;

    virtual CboxError respond(const Payload&) override final
    {
        return CboxError::OK;
    }
};

} // end namespace cbox
