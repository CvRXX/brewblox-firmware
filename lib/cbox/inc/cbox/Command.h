/*
 * Copyright 2014-2015 Matthew McGowan.
 * Copyright 2018 Brewblox / Elco Jacobs
 * This file is part of Controlbox.
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

#pragma once

#include "proto/brewblox.pb.h"
#include "proto/controlbox.pb.h"
#include <optional>
#include <vector>

namespace cbox {

class CboxPayload {
public:
    const uint32_t blockId;
    const brewblox_BlockType blockType;
    const uint32_t subtype;
    const std::vector<uint8_t> content;

    CboxPayload(uint32_t _blockId,
                brewblox_BlockType _blockType,
                uint32_t _subtype,
                std::vector<uint8_t>&& _content)
        : blockId(_blockId)
        , blockType(_blockType)
        , subtype(_subtype)
        , content(std::move(_content))
    {
    }

    ~CboxPayload() = default;
};

class CboxCommand {
public:
    const uint32_t msgId;
    const controlbox_Opcode opcode;
    const std::optional<CboxPayload> requestPayload;

    CboxCommand(uint32_t _msgId,
                controlbox_Opcode _opcode,
                std::optional<CboxPayload>&& _requestPayload = std::nullopt)
        : msgId(_msgId)
        , opcode(_opcode)
        , requestPayload(std::move(_requestPayload))
    {
    }

    CboxCommand(const CboxCommand&) = delete;
    CboxCommand(CboxCommand&&) = delete;
    CboxCommand& operator=(const CboxCommand&) = delete;

    ~CboxCommand() = default;

    virtual CboxError respond(const CboxPayload& payload) = 0;
};

} // end namespace cbox
