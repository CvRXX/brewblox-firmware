/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of BrewBlox
 *
 * BrewBlox is free software: you can redistribute it and/or modify
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
 * along with BrewBlox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "blox/Block.h"
#include "cbox/DataStream.h"
#include "proto/cpp/DisplaySettings.pb.h"

// provides a protobuf interface to the read only system info
class DisplaySettingsBlock : public cbox::ObjectBase<BrewBloxTypes_BlockType_DisplaySettings> {
public:
    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;

    virtual cbox::CboxError streamFrom(cbox::DataIn& in) override final;

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        return update_never(now);
    }

    static blox_DisplaySettings& settings()
    {
        m_newSettingsReceived = false;
        return m_settings;
    }

    static bool newSettingsReceived()
    {
        return m_newSettingsReceived;
    }

private:
    static blox_DisplaySettings m_settings;
    static bool m_newSettingsReceived;
};
