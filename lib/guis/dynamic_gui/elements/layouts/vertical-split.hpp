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

#include "dynamic_gui/elements/core/element.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"
#include <numeric>

namespace gui::dynamic_interface {

/**
 * A GUI block which takes a set of blocks which are displayed on a vertical splitted parent.
 */
class VerticalSplit : public Element {
public:
    /**
     * Constructs a vertical split.
     * @param ratioBlocks a list of ratioblocks to be displayed.
     */
    VerticalSplit(std::vector<std::unique_ptr<Element>>&& elements, uint16_t weight)
        : elements(std::move(elements))
        , weight(weight)
    {
    }

    VerticalSplit(VerticalSplit&& verticalSplit)
        : elements(std::move(verticalSplit.elements))
        , placeholders(std::move(verticalSplit.placeholders))
        , weight(verticalSplit.weight)
    {
    }

    /**
     * Calls update on all the child blocks.
     */
    void update() override
    {
        for (auto& element : elements) {
            element->update();
        }
    }

    uint16_t getWeight() const override
    {
        return weight;
    }

    /**
     * Draws the placeholders for it's children and calls their draw function.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t with, uint16_t height) override
    {
        lv_obj_set_style_pad_gap(placeholder, 0, 0);
        lv_obj_set_style_pad_all(placeholder, 0, 0);
        lv_obj_set_style_border_width(placeholder, 0, 0);

        const auto weightTotal = std::accumulate(elements.begin(), elements.end(), uint32_t(0), [](auto& sum, auto& element) -> uint32_t {
            return sum + element->getWeight();
        });

        uint32_t startingX = 0;
        std::transform(elements.begin(), elements.end(), std::back_inserter(placeholders), [&startingX, placeholder, weightTotal, height, with](auto& element) -> LvglObjectWrapper {
            const auto elementWidth = (with / weightTotal) * element->getWeight();

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), elementWidth, height);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), startingX, 0);
            startingX += elementWidth;
            element->draw(newPlaceholder.get(), elementWidth, height);
            return newPlaceholder;
        });
    }

private:
    std::vector<LvglObjectWrapper> placeholders;
    std::vector<std::unique_ptr<Element>> elements;
    uint16_t weight = 1;
};
}
