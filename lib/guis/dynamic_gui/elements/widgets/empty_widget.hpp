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

#include "dynamic_gui/elements/core/color.hpp"
#include "dynamic_gui/elements/widgets/widget_base.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "dynamic_gui/styles/sizing.hpp"
#include "proto/guiMessage.pb.h"

#include "lvgl.h"
#include <iostream>

namespace gui::dynamic_interface {

/**
 * A widget which can display a numeric value.
 */
class EmptyWidget : public WidgetBase {
public:
    /**
     * Constructs a numeric value.
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    EmptyWidget()
        : WidgetBase({guiMessage_Color{150, 150, 150}})
    {
    }

    EmptyWidget(EmptyWidget&& emptyWidget) = default;

    bool serialise(std::vector<guiMessage_ContentNode>& contentnodes, uint8_t layOutNodeId) override
    {
        return true;
    }
};
}
