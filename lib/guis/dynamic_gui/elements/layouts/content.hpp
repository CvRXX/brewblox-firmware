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
#include "dynamic_gui/elements/core/element.hpp"
#include "dynamic_gui/elements/widgets/widget.hpp"
#include "dynamic_gui/styles/styles.hpp"
#include "proto/ScreenConfig.pb.h"

namespace gui::dynamic_interface {

/**
 * A base class for widgets.
 */
class Content : public Element {
public:
    /**
     * Constructs a content element.
     */
    Content(uint16_t weight, uint8_t layOutNodeId, std::unique_ptr<Widget> widget)
        : weight(weight)
        , layOutNodeId(layOutNodeId)
        , widget(std::move(widget))
    {
    }

    Content(Content&& widget) = default;

    void update() override
    {
        widget->update();
    }

    uint16_t getWeight() const override
    {
        return weight;
    }

    bool serialise(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t parentId) override
    {
        layoutNodes.push_back({parentId, layOutNodeId, blox_ScreenConfig_Type_Content, weight});
        return widget->serialise(contentNodes, layOutNodeId);
    }

    /**
     * Draws the widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t with, uint16_t height) override
    {
        widget->draw(placeholder, with, height);
    }

protected:
    uint16_t weight;
    uint8_t layOutNodeId;
    std::unique_ptr<Widget> widget;
};

}
