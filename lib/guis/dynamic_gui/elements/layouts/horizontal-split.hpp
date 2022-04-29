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
 * A GUI block which takes a set of blocks which are displayed on a horizontal splitted parent.
 */
class HorizontalSplit : public Element {
public:
    /**
     * Constructs a horizontal split.
     * @param ratioBlocks a list of ratioblocks to be displayed.
     */
    HorizontalSplit(std::vector<std::unique_ptr<Element>>&& elements, uint16_t weight)
        : elements(std::move(elements))
        , weight(weight)
    {
    }

    HorizontalSplit(HorizontalSplit&& horizontalSplit)
        : elements(std::move(horizontalSplit.elements))
        , placeholders(std::move(horizontalSplit.placeholders))
        , weight(horizontalSplit.weight)
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

        const auto weightTotal = std::accumulate(elements.begin(), elements.end(), uint16_t(0), [](uint16_t sum, const auto& element) -> uint16_t {
            return sum + element->getWeight();
        });

        uint32_t startingY = 0;
        std::transform(elements.begin(), elements.end(), std::back_inserter(placeholders), [&startingY, placeholder, weightTotal, height, with](auto& element) -> LvglObjectWrapper {
            const auto elementHeight = (height / weightTotal) * element->getWeight(); /// first multiply then divide

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), with, elementHeight);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), 0, startingY);
            startingY += elementHeight;
            element->draw(newPlaceholder.get(), with, elementHeight);
            return newPlaceholder;
        });
    }

private:
    std::vector<LvglObjectWrapper> placeholders;
    std::vector<std::unique_ptr<Element>> elements;
    uint16_t weight = 1;
};
}
