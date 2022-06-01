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

#include "dynamic_gui/elements/layout/layout_node.hpp"
#include "lvgl.h"
#include "proto/Screen.pb.h"
#include <type_traits>

namespace gui::dynamic_interface {

// Top level node for the layouttree.
class Screen final : public LayoutNode {
public:
    Screen(std::unique_ptr<LayoutNode>&& child)
        : child(std::move(child))
    {
    }

    Screen() = default;

    // Calls update on it's child.
    void update() override final
    {
        if (!empty()) {
            child->update();
        }
    }

    /**
     * Calls draw on it's child forwarding the parameters.
     * @param placeholder The lvgl placeholder in which the child will be drawn.
     * @param width the width of the available space in the placeholder.
     * @param height the height of the available space in the placeholder.
     */
    void draw(lv_obj_t* screen, uint16_t width, uint16_t height) override final
    {
        if (!empty()) {
            child->draw(screen, width, height);
        }
    }

    // Returns if the Screen is empty.
    bool empty()
    {
        return !child;
    }

    /**
     * Returns the weight of the screen.
     * Because the screen is the top level node this is always zero.
     */
    uint16_t getWeight() const override final
    {
        return 1;
    }

    /**
     * Serializes the screen node and it's child.
     * @param layoutNodes This class will be serialized into this vector.
     * @param contentNodes The child of this class will be serialized into this vector.
     */
    void serialize(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t parentId = 0) override final
    {
        return child->serialize(layoutNodes, contentNodes, 0);
    }

private:
    std::unique_ptr<LayoutNode> child;
};
}
