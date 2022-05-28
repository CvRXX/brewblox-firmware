/*
 * Copyright 2020 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "dynamic_gui/elements/widgets/color_widget.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "dynamic_gui/util/color.hpp"
#include "dynamic_gui/util/lvgl_object_wrapper.hpp"
#include "proto/ScreenConfig.pb.h"

#include "lvgl.h"
#include <iostream>

namespace gui::dynamic_interface {

/**
 * An empty widget.
 * This is usefull for content layout blocks with no widget.
 */
class EmptyWidget final : public ColorWidget {
public:
    /**
     * Constructs a numeric value.
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    EmptyWidget()
        : ColorWidget({blox_ScreenConfig_Color{150, 150, 150}})
    {
    }

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     * Because the widget is empty no widget will be added to the vector.
     */
    void serialize(std::vector<blox_ScreenConfig_ContentNode>& contentnodes, uint8_t layOutNodeId) override final
    {
    }
};
}
