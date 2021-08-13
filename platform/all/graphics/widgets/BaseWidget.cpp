#include "./BaseWidget.hpp"

BaseWidget::BaseWidget(lv_obj_t* grid, lv_color_t color)
    : grid(grid)
{
    obj = lv_obj_create(grid, NULL);
    lv_obj_set_size(obj, 145, 132);
    lv_obj_reset_style_list(obj, LV_BTN_PART_MAIN);
    lv_obj_add_style(obj, LV_BTN_PART_MAIN, &style::block);
    lv_obj_set_style_local_bg_color(obj, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, color);
    lv_obj_align(grid, NULL, LV_ALIGN_CENTER, 0, 0);
}

uint8_t BaseWidget::getLuminance()
{
    auto color = lv_obj_get_style_bg_color(obj, LV_BTN_PART_MAIN);
    return 0.2126 * color.ch.red + 0.7152 * color.ch.green + 0.0722 * color.ch.blue;
}
uint8_t BaseWidget::getRed()
{
    auto color = lv_obj_get_style_bg_color(obj, LV_BTN_PART_MAIN);
    return color.ch.red;
}

TempUnit BaseWidget::tempUnit = TempUnit::Celsius;