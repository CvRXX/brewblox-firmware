#pragma once

#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/blocks/core/color.hpp"
#include "dynamic_gui/styles/styles.hpp"

class Widget : public Block {
public:
    constexpr Widget(Color color)
        : color(color)
    {
    }

    Widget(Widget&& widget)
        : color(widget.color)
        , contentArea(std::move(widget.contentArea))
    {
    }

    void update() override
    {
    }

    void draw(lv_obj_t* placeholder) override
    {
        contentArea.reset(lv_obj_create(placeholder));
        lv_obj_set_size(contentArea.getPtr(), lv_pct(100), lv_pct(100));
        lv_obj_add_style(placeholder, &style::block, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(contentArea.getPtr(), color.lvglColor(), LV_STATE_DEFAULT);
        lv_obj_add_style(contentArea.getPtr(), luminance() < 128 ? &style::bg_dark : &style::bg_light, 0);
    }

    constexpr uint8_t luminance()
    {
        return (uint16_t{54} * color.r + uint16_t{183} * color.g + uint16_t{18} * color.b) / 256;
    }

    const Color color;
    LvglObjectWrapper contentArea = nullptr;
};
