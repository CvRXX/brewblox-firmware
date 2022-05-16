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
#include "lvgl.h"
#include "proto/ScreenConfig.pb.h"

namespace gui::dynamic_interface {

/**
 * A virtual base class for a generic gui element.
 */
class Element { // Rename this into something that is not confusing with brewblox blocks.
public:
    virtual void update() = 0;
    virtual void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) = 0;
    virtual uint16_t getWeight() const = 0;
    virtual void serialize(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentnodes, uint8_t parentId) = 0;

    virtual ~Element() = default;

protected:
    Element(const Element&) = delete;
    Element(Element&&) = delete;
    Element& operator=(const Element&) = delete;
    Element& operator=(Element&&) = delete;
    Element() = default;
};

}
