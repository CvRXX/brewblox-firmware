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

#include "cbox/CboxError.hpp"
#include <functional>
#include <memory>
#include <vector>

namespace cbox {

using obj_type_t = uint16_t;
using obj_id_t = uint16_t;
using obj_subtype_t = uint16_t;

class Payload {
public:
    const obj_id_t blockId;
    const obj_type_t blockType;
    const obj_subtype_t subtype;
    std::vector<uint8_t> content;

    Payload(obj_id_t _blockId,
            obj_type_t _blockType,
            obj_subtype_t _subtype,
            std::vector<uint8_t>&& _content)
        : blockId(_blockId)
        , blockType(_blockType)
        , subtype(_subtype)
        , content(std::move(_content))
    {
    }

    Payload(obj_id_t _blockId,
            obj_type_t _blockType,
            obj_subtype_t _subtype)
        : blockId(_blockId)
        , blockType(_blockType)
        , subtype(_subtype)
    {
    }

    virtual ~Payload() = default;
};

using PayloadCallback = std::function<CboxError(const Payload&)>;

} // end namespace cbox
