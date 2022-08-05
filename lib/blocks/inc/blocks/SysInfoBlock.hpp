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
#include "control/Temperature.hpp"
#include "control/TicksTypes.hpp"
#include "proto/SysInfo.pb.h"

struct SystemSettings {
    std::string timeZone;
    TempUnit tempUnit{TempUnit::Celsius};
    uint8_t displayBrightness{255};
};

// provides a protobuf interface to the read only system info
class SysInfoBlock final : public cbox::ObjectBase<brewblox_BlockType_SysInfo> {
private:
    static SystemSettings _settings;
    static bool _newSettingsReceived;

    ticks_millis_t _updateCounterStart{0};
    uint32_t _updateCounter{0};

public:
    explicit SysInfoBlock(size_t (&device_id_func_)(uint8_t*, size_t len))
        : device_id_func(device_id_func_)
    {
    }
    ~SysInfoBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;

    size_t (&device_id_func)(uint8_t*, size_t len);

    static SystemSettings& settings()
    {
        _newSettingsReceived = false;
        return _settings;
    }

    static bool newSettingsReceived()
    {
        return _newSettingsReceived;
    }
};
