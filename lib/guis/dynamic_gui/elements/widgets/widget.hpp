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
#include "dynamic_gui/styles/styles.hpp"

namespace gui::dynamic_interface {

/**
 * A base class for widgets.
 */
class Widget : public Element {
public:
    /**
     * Constructs a widget.
     * @param color The background color of the widget.
     */
    constexpr Widget(Color color, uint16_t weight)
        : color(color)
        , weight(weight)
    {
    }

    Widget(Widget&& widget) = default;

    void update() override
    {
    }

    uint16_t getWeight() const override
    {
        return weight;
    }

    /**
     * Draws the widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t with, uint16_t height) override
    {
        contentArea.reset(lv_obj_create(placeholder));
        lv_obj_set_size(contentArea.get(), lv_pct(100), lv_pct(100));
        lv_obj_add_style(placeholder, &style::block, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(contentArea.get(), color.lvglColor(), LV_STATE_DEFAULT);
        lv_obj_add_style(contentArea.get(), luminance() < 128 ? &style::bg_dark : &style::bg_light, 0);
    }

    /**
     * Returns the luminance of the background color.
     * This is useful for choosing font colors with readable contrast.
     * @return The luminance
     */
    constexpr uint8_t luminance()
    {
        return (uint16_t{54} * color.r + uint16_t{183} * color.g + uint16_t{18} * color.b) / 256;
    }

protected:
    const Color color;
    uint16_t weight;
    LvglObjectWrapper contentArea = nullptr;
};

}
