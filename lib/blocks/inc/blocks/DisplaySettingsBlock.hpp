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
#include "proto/DisplaySettings.pb.h"

// provides a protobuf interface to the read only system info
class DisplaySettingsBlock final : public cbox::ObjectBase<brewblox_BlockType_DisplaySettings> {
public:
    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;

    static blox_DisplaySettings_Block& settings()
    {
        m_newSettingsReceived = false;
        return m_settings;
    }

    static bool newSettingsReceived()
    {
        return m_newSettingsReceived;
    }

private:
    static blox_DisplaySettings_Block m_settings;
    static bool m_newSettingsReceived;
};
