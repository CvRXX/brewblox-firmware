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

#include "dynamic_gui/elements/widgets/widget.hpp"
#include "dynamic_gui/styles/styles.hpp"
#include "dynamic_gui/util/color.hpp"
#include "dynamic_gui/util/lvgl_wrapper.hpp"
#include "proto/ScreenConfig.pb.h"

namespace gui::dynamic_interface {

// A widget that displays a singe color.
class ColorWidgetSettings;
class ColorWidget : public Widget {
public:
    friend ColorWidgetSettings;
    /**
     * Constructs the ColorWidget.
     * @param color The background color of the widget.
     */
    constexpr ColorWidget(ScreenConfig_ColorWidget colorWidget)
        : settings(colorWidget)
        , color({colorWidget.color.r, colorWidget.color.g, colorWidget.color.b})
    {
    }

    static void pressed(lv_event_t* event);

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     */
    void serialize(std::vector<ScreenConfig_ContentNode>& contentNodes, uint8_t layOutNodeId) override
    {
        ScreenConfig_ContentNode node = ScreenConfig_ContentNode_init_default;
        node.layoutNodeId = layOutNodeId;
        node.which_content = ScreenConfig_ContentNode_colorWidget_tag;
        node.content.colorWidget = settings;

        contentNodes.push_back(node);
    }

    void update() override
    {
    }

    /**
     * Draws the widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param width The width of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override
    {
        contentArea.reset(lv_obj_create(placeholder));
        lv_obj_clear_flag(placeholder, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(contentArea.get(), LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_size(contentArea.get(), lv_pct(100), lv_pct(100));
        lv_obj_add_style(placeholder, &style::block, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(contentArea.get(), color, LV_STATE_DEFAULT);
        lv_obj_add_style(contentArea.get(), luminance() < 128 ? &style::bg_dark : &style::bg_light, 0);
        lv_obj_add_event_cb(contentArea.get(), pressed, LV_EVENT_CLICKED, this); /*Assign an event callback*/
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
    ScreenConfig_ColorWidget settings;
    Color color;
    LvglObjectWrapper contentArea = nullptr;
};

class ColorWidgetSettings {
public:
    static void draw(ColorWidget& colorWidget)
    {
        auto settings = new ColorWidgetSettings(colorWidget);
        settings->drawSettings();
    }

private:
    ColorWidgetSettings(ColorWidget& colorWidget)
        : colorWidget(colorWidget)
    {
    }

    void exit()
    {
        lv_scr_load(oldScreen);
        delete (this);
    }

    static void timerFunc(lv_timer_t* timer)
    {
        auto settings = reinterpret_cast<ColorWidgetSettings*>(timer->user_data);
        settings->exit();
    }

    static void dropDownHandler(lv_event_t* e)
    {
        auto settings = reinterpret_cast<ColorWidgetSettings*>(e->user_data);
        auto widget = &(settings->colorWidget);
        lv_event_code_t code = lv_event_get_code(e);
        lv_obj_t* obj = lv_event_get_target(e);
        if (code == LV_EVENT_VALUE_CHANGED) {
            char buf[32];
            lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
            if (!strcmp(buf, "red")) {
                widget->color = Color{255, 0, 0};
            } else if (!strcmp(buf, "green")) {
                widget->color = Color{0, 255, 0};
            } else if (!strcmp(buf, "blue")) {
                widget->color = Color{0, 0, 255};
            }
            lv_obj_set_style_bg_color(widget->contentArea.get(), widget->color, LV_STATE_DEFAULT);
            settings->exit();
        }
    }

public:
    void drawSettings()
    {
        scr.reset(lv_obj_create(NULL));
        oldScreen = lv_scr_act();

        dd.reset(lv_dropdown_create(scr.get()));

        lv_dropdown_set_options(dd.get(),
                                "red\n"
                                "green\n"
                                "blue\n");

        lv_obj_align(dd.get(), LV_ALIGN_TOP_MID, 0, 20);
        lv_obj_add_event_cb(dd.get(), dropDownHandler, LV_EVENT_ALL, this);

        lv_scr_load(scr.get());
        timer.reset(lv_timer_create(timerFunc, 30000, this));
        lv_timer_set_repeat_count(timer.get(), 1);
    }
    ColorWidget& colorWidget;
    lv_obj_t* oldScreen = nullptr;
    LvglObjectWrapper scr = nullptr;
    LvglObjectWrapper dd = nullptr;
    LvglTimerWrapper timer = nullptr;
};

inline void ColorWidget::pressed(lv_event_t* event)
{
    auto obj = reinterpret_cast<ColorWidget*>(event->user_data);
    ColorWidgetSettings::draw(*obj);
}
}
