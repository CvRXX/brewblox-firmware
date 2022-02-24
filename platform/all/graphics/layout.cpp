#include "layout.hpp"
#include "bar.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "cbox/CboxPtr.hpp"
#include "cbox/Box.hpp"
#include "drivers/Spark4.hpp"
#include "graphics/widgets.hpp"
#include "lvgl.h"
#include <algorithm>

Layout::Layout()
{
    lv_obj_clear_flag(lv_scr_act(), LV_OBJ_FLAG_SCROLLABLE);
    mainContainer = lv_obj_create(lv_scr_act());
    lv_obj_set_size(mainContainer, 480, 320);
    lv_obj_add_style(mainContainer, &style::maincontainer, 0);
    lv_obj_clear_flag(mainContainer, LV_OBJ_FLAG_SCROLLABLE);

    static lv_coord_t col_dsc[] = {148, 148, 148, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {134, 134, LV_GRID_TEMPLATE_LAST};

    bar = std::unique_ptr<Bar>(new Bar(mainContainer));
    grid = lv_obj_create(mainContainer);
    lv_obj_clear_flag(grid, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_grid_column_dsc_array(grid, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(grid, row_dsc, 0);
    lv_obj_set_layout(grid, LV_LAYOUT_GRID);
    lv_obj_set_style_pad_row(grid, 9, 0);
    lv_obj_set_style_pad_column(grid, 9, 0);
    lv_obj_add_style(grid, &style::grid, 0);
    lv_obj_set_size(grid, 480, 298);
    lv_obj_align(grid, LV_ALIGN_OUT_TOP_MID, 0, 22);
    lv_obj_set_grid_align(grid, LV_GRID_ALIGN_CENTER, LV_GRID_ALIGN_CENTER);
}

Layout::~Layout()
{
    lv_obj_del(grid);
    lv_obj_del(mainContainer);
}

void Layout::update()
{
    updateConfig();
    updateWidgets();
    bar->update();
}

void Layout::updateWidgets()
{
    for (auto& widget : sensorWidgets) {
        if (widget) {
            widget->update();
        }
    }
}

std::unique_ptr<BaseWidget> Layout::makeWidget(uint8_t pos)
{
    auto& settings = DisplaySettingsBlock::settings();
    auto row = (pos - 1) / 3;
    auto col = (pos - 1) % 3;

    auto widget = std::find_if(std::begin(settings.widgets), std::end(settings.widgets), [pos](auto& widget) {
        return widget.pos == pos;
    });

    if (widget != std::end(settings.widgets)) {
        auto color = lv_color_make(widget->color[0], widget->color[1], widget->color[2]);
        switch (widget->which_WidgetType) {
        case blox_DisplaySettings_Widget_tempSensor_tag: {
            auto lookup = cbox::CboxPtr<TempSensor>(cbox::obj_id_t(widget->WidgetType.tempSensor));
            return std::unique_ptr<BaseWidget>(new TemperatureWidget(grid, row, col, std::move(lookup), widget->name, color));
        } break;
        case blox_DisplaySettings_Widget_setpointSensorPair_tag: {
            auto lookup = cbox::CboxPtr<SetpointSensorPairBlock>(cbox::obj_id_t(widget->WidgetType.setpointSensorPair));
            return std::unique_ptr<BaseWidget>(new SetpointWidget(grid, row, col, std::move(lookup), widget->name, color));
        } break;
        case blox_DisplaySettings_Widget_actuatorAnalog_tag: {
            auto lookup = cbox::CboxPtr<ActuatorAnalogConstrained>(cbox::obj_id_t(widget->WidgetType.setpointSensorPair));
            return std::unique_ptr<BaseWidget>(new ActuatorAnalogWidget(grid, row, col, std::move(lookup), widget->name, color));
        } break;
        case blox_DisplaySettings_Widget_pid_tag: {
            auto lookup = cbox::CboxPtr<PidBlock>(cbox::obj_id_t(widget->WidgetType.pid));
            return std::unique_ptr<BaseWidget>(new PidWidget(grid, row, col, std::move(lookup), widget->name, color));
        } break;
        }
    }
    return std::unique_ptr<BaseWidget>(new BaseWidget(grid, row, col, "", LV_COLOR_MAKE(0x20, 0x20, 0x20)));
};

void Layout::updateConfig()
{
    if (DisplaySettingsBlock::newSettingsReceived()) {
        auto& settings = DisplaySettingsBlock::settings();

        if (settings.tempUnit == blox_DisplaySettings_TemperatureUnit_TEMP_CELSIUS) {
            BaseWidget::tempUnit = TempUnit::Celsius;
        } else {
            BaseWidget::tempUnit = TempUnit::Fahrenheit;
        }

        spark4::display_brightness(settings.brightness);

        setenv("TZ", settings.timeZone, 1);
        tzset();

        for (uint8_t pos = 0; pos < 6; pos++) {
            // find widget settings for position
            sensorWidgets[pos] = makeWidget(pos + 1);
        }
    }
}
