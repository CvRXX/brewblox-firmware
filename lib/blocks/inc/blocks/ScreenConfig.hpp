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
#include "dynamic_gui/dynamicGui.hpp"
#include "proto/Screen.pb.h"

// provides a protobuf interface to the read only system info
class ScreenConfig final : public cbox::ObjectBase<brewblox_BlockType_ScreenConfig> {
public:
    ScreenConfig() = default;
    ~ScreenConfig() = default;

    struct DecodedScreenConfig {
        screen_Block settings;
        std::vector<screen_LayoutNode> layoutNodes;
        std::vector<screen_ContentNode> contentNodes;
    };

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;

    static DecodedScreenConfig& settings()
    {
        m_newSettingsReceived = false;
        return decodedScreenConfig;
    }

    static bool newSettingsReceived()
    {
        return m_newSettingsReceived;
    }

private:
    static DecodedScreenConfig decodedScreenConfig;
    static bool m_newSettingsReceived;
};
