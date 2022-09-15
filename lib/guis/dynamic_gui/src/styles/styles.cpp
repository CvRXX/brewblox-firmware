#include "dynamic_gui/styles/styles.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
namespace gui::dynamic_interface {

namespace style {

    lv_style_t bar;
    lv_style_t grid;
    lv_style_t maincontainer;
    lv_style_t block;
    lv_style_t block_disabled;
    lv_style_t bg_dark;
    lv_style_t bg_light;
    lv_style_t widget_name;
    lv_style_t number_large;
    lv_style_t number_huge;
    lv_style_t number_medium;
    lv_style_t number_small;
    lv_style_t field_label;
    lv_style_t widget_title;

    void init()
    {
        lv_style_init(&maincontainer);
        lv_style_set_pad_all(&maincontainer, 0);
        lv_style_set_bg_color(&maincontainer, lv_color_black());
        lv_style_set_border_side(&maincontainer, LV_BORDER_SIDE_NONE);
        lv_style_set_text_font(&maincontainer, &fonts::main);
        lv_style_set_radius(&maincontainer, 0);

        lv_style_init(&bar);
        lv_style_set_bg_color(&bar, lv_color_white());
        lv_style_set_border_side(&bar, LV_BORDER_SIDE_NONE);
        lv_style_set_radius(&bar, 0);
        lv_style_set_pad_all(&bar, 0);

        lv_style_init(&grid);
        lv_style_set_bg_color(&grid, lv_color_black());
        lv_style_set_pad_all(&grid, 0);
        lv_style_set_border_side(&grid, LV_BORDER_SIDE_NONE);
        lv_style_set_radius(&grid, 0);

        lv_style_init(&block);
        lv_style_set_border_width(&block, 0);
        lv_style_set_pad_all(&block, 10);
        lv_style_set_bg_opa(&block, LV_OPA_COVER);

        lv_style_init(&block_disabled);
        lv_style_set_bg_opa(&block_disabled, 50);
        lv_style_set_text_opa(&block_disabled, 50);

        lv_style_init(&bg_light);
        lv_style_set_text_color(&bg_light, lv_color_black());
        lv_style_set_border_color(&bg_light, lv_color_black());

        lv_style_init(&bg_dark);
        lv_style_set_text_color(&bg_dark, lv_color_white());
        lv_style_set_border_color(&bg_dark, lv_color_white());

        lv_style_init(&number_large);
        lv_style_set_text_font(&number_large, &fonts::numbers_large);

        lv_style_init(&number_huge);
        lv_style_set_text_font(&number_huge, &fonts::numbers_huge);

        lv_style_init(&number_medium);
        lv_style_set_text_font(&number_medium, &fonts::numbers_medium);

        lv_style_init(&number_small);
        lv_style_set_text_font(&number_small, &fonts::numbers_small);

        lv_style_init(&widget_name);
        lv_style_set_text_font(&widget_name, &fonts::widget_name);

        lv_style_init(&widget_title);
        lv_style_set_text_font(&widget_title, &fonts::main_medium);

        lv_style_init(&field_label);
        lv_style_set_text_font(&field_label, &fonts::main_small);
    }
}
}
