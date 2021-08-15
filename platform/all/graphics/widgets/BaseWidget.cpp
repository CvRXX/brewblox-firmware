#include "./BaseWidget.hpp"

BaseWidget::BaseWidget(lv_obj_t* grid, lv_color_t color)
    : grid(grid)
{
    obj = lv_obj_create(grid, nullptr);
    lv_obj_set_size(obj, 145, 132);
    lv_obj_reset_style_list(obj, LV_BTN_PART_MAIN);
    lv_obj_add_style(obj, LV_BTN_PART_MAIN, &style::block);
    lv_obj_set_style_local_bg_color(obj, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, color);
    lv_obj_align(grid, nullptr, LV_ALIGN_CENTER, 0, 0);
    textColor = (getLuminance() > 128) ? LV_COLOR_BLACK : LV_COLOR_WHITE;
}

uint8_t BaseWidget::getLuminance()
{
    auto color = lv_obj_get_style_bg_color(obj, LV_BTN_PART_MAIN);
    return (uint16_t{54} * color.ch.red + uint16_t{183} * color.ch.green + uint16_t{18} * color.ch.blue) / 256;
}
uint8_t BaseWidget::getRed()
{
    auto color = lv_obj_get_style_bg_color(obj, LV_BTN_PART_MAIN);
    return color.ch.red;
}

TempUnit BaseWidget::tempUnit = TempUnit::Celsius;