#include "layout.hpp"
#include "Spark4.hpp"
#include "bar.hpp"
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "graphics/widgets.hpp"
#include "lvgl.h"

Layout::Layout(cbox::Box& box)
    : box(box)
{
    mainContainer = lv_obj_create(lv_scr_act());
    lv_obj_set_size(mainContainer, 480, 320);
    lv_obj_add_style(mainContainer, &style::maincontainer, 0);

    bar = std::unique_ptr<Bar>(new Bar(mainContainer));
    grid = lv_obj_create(mainContainer);
    lv_obj_add_style(grid, &style::grid, 0);
    lv_obj_set_size(grid, 480, 298);
    lv_obj_align(grid, LV_ALIGN_OUT_TOP_MID, 0, 22);
    lv_obj_set_layout(grid, LV_LAYOUT_GRID);
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

        auto makeWidget = [&settings, this](uint8_t pos) -> std::unique_ptr<BaseWidget> {
            for (pb_size_t idx = 0; idx < settings.widgets_count; idx++) {
                auto& widget = settings.widgets[idx];
                if (widget.pos == pos) {
                    auto color = lv_color_make(widget.color[0], widget.color[1], widget.color[2]);
                    switch (widget.which_WidgetType) {
                    case blox_DisplaySettings_Widget_tempSensor_tag: {
                        auto lookup = box.makeCboxPtr<TempSensor>(cbox::obj_id_t(widget.WidgetType.tempSensor));
                        return std::unique_ptr<BaseWidget>(new TemperatureWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_DisplaySettings_Widget_setpointSensorPair_tag: {
                        auto lookup = box.makeCboxPtr<SetpointSensorPairBlock>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                        return std::unique_ptr<BaseWidget>(new SetpointWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_DisplaySettings_Widget_actuatorAnalog_tag: {
                        auto lookup = box.makeCboxPtr<ActuatorAnalogConstrained>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                        return std::unique_ptr<BaseWidget>(new ActuatorAnalogWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_DisplaySettings_Widget_pid_tag: {
                        auto lookup = box.makeCboxPtr<PidBlock>(cbox::obj_id_t(widget.WidgetType.pid));
                        return std::unique_ptr<BaseWidget>(new PidWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    default:
                        break;
                    }
                }
            }
            // return base widget as empty placeholder
            return std::unique_ptr<BaseWidget>(new BaseWidget(grid, "", LV_COLOR_MAKE(0x20, 0x20, 0x20)));
        };

        for (uint8_t pos = 0; pos < 6; pos++) {
            // find widget settings for position
            sensorWidgets[pos] = makeWidget(pos + 1);
        }
    }
}