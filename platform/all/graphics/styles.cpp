#include "styles.hpp"
#include "fonts/fonts.hpp"

namespace style {

lv_style_t bar;
lv_style_t grid;
lv_style_t maincontainer;
lv_style_t block;
lv_style_t bg_dark;
lv_style_t bg_light;
lv_style_t widget_name;
lv_style_t number_large;
lv_style_t number_medium;

void init()
{
    lv_style_init(&maincontainer);
    lv_style_set_pad_all(&maincontainer, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_inner(&maincontainer, LV_STATE_DEFAULT, 0);
    lv_style_set_margin_all(&maincontainer, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_color(&maincontainer, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_side(&maincontainer, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

    lv_style_init(&bar);
    lv_style_set_bg_color(&bar, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_font(&bar, LV_STATE_DEFAULT, &fonts::main);
    lv_style_set_border_side(&bar, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);
    lv_style_set_radius(&bar, LV_STATE_DEFAULT, 0);

    lv_style_init(&grid);
    lv_style_set_bg_color(&bar, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_pad_all(&grid, LV_STATE_DEFAULT, 9);
    lv_style_set_pad_inner(&grid, LV_STATE_DEFAULT, 9);
    lv_style_set_border_side(&grid, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);
    lv_style_set_radius(&grid, LV_STATE_DEFAULT, 0);

    lv_style_init(&block);
    lv_style_set_radius(&block, LV_STATE_DEFAULT, 5);
    lv_style_set_bg_opa(&block, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_border_width(&block, LV_STATE_DEFAULT, 1);
    lv_style_set_border_opa(&block, LV_STATE_DEFAULT, 80);
    lv_style_set_pad_all(&block, LV_STATE_DEFAULT, 10);

    lv_style_init(&bg_light);
    lv_style_set_text_color(&bg_light, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&bg_light, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&bg_dark);
    lv_style_set_text_color(&bg_dark, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_color(&bg_dark, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_style_init(&number_large);
    lv_style_set_text_font(&number_large, LV_STATE_DEFAULT, &fonts::numbers_large);

    lv_style_init(&number_medium);
    lv_style_set_text_font(&number_medium, LV_STATE_DEFAULT, &fonts::numbers_medium);

    lv_style_init(&widget_name);
    lv_style_set_text_font(&widget_name, LV_STATE_DEFAULT, &fonts::widget_name);
}
}