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
#include "proto/guiMessage.pb.h"

namespace gui::dynamic_interface {

/**
 * A virtual base class for a generic gui element.
 */
class Element { // Rename this into something that is not confusing with brewblox blocks.
public:
    virtual void update() = 0;
    virtual void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) = 0;
    virtual uint16_t getWeight() const = 0;
<<<<<<< HEAD
    virtual ~Element() = default;
=======
    virtual bool serialise(std::vector<guiMessage_LayoutNode>& layoutNodes, std::vector<guiMessage_ContentNode>& contentnodes, uint8_t parentId) = 0;
>>>>>>> 5879f7de4209caf32f65dd5224421e43b0a13949
};

}
