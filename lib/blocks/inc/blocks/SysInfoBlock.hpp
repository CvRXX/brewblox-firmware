/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox
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

#include "blocks/Block.hpp"
#include "proto/SysInfo.pb.h"

// provides a protobuf interface to the read only system info
class SysInfoBlock final : public cbox::ObjectBase<brewblox_BlockType_SysInfo> {
public:
    explicit SysInfoBlock(size_t (&device_id_func_)(uint8_t*, size_t len))
        : device_id_func(device_id_func_)
    {
    }
    ~SysInfoBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;

    enum class Command : uint8_t {
        NONE = 0,
        SYS_CMD_TRACE_READ = 1,
        SYS_CMD_TRACE_RESUME = 2,
        READ_AND_SYS_CMD_TRACE_RESUME = 3,
    };

    mutable Command command = Command::NONE;

    size_t (&device_id_func)(uint8_t*, size_t len);
};
