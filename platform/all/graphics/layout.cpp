#include "layout.hpp"
#include "bar.hpp"
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "graphics/widgets.hpp"
#include "lvgl.h"
#include "network/ethernet.hpp"
#include "network/wifi.hpp"

Layout::Layout(cbox::Box& box)
    : box(box)
{
    mainContainer = lv_obj_create(lv_scr_act(), nullptr);
    lv_obj_set_size(mainContainer, 480, 320);
    lv_obj_add_style(mainContainer, LV_OBJ_PART_MAIN, &style::maincontainer);

    bar = std::unique_ptr<Bar>(new Bar(mainContainer));
    grid = lv_cont_create(mainContainer, nullptr);
    lv_obj_add_style(grid, LV_CONT_PART_MAIN, &style::grid);
    lv_obj_set_size(grid, 480, 298);
    lv_obj_align(grid, nullptr, LV_ALIGN_IN_TOP_MID, 0, 22);
    lv_cont_set_layout(grid, LV_LAYOUT_GRID);
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

    bar->setWifiIp(wifi::ip4().addr);
    bar->setWifiEnabled(wifi::isConnected());
    bar->setWifiRssi(wifi::getRssi());
    bar->setEthernetIp(ethernet::ip4().addr);
    bar->setEthernetEnabled(ethernet::isConnected());

    bar->updateTime();
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

        setenv("TZ", settings.timeZone, 1);
        tzset();

        auto makeWidget = [&settings, this](uint8_t pos) -> std::unique_ptr<BaseWidget> {
            for (pb_size_t idx = 0; idx < settings.widgets_count; idx++) {
                auto& widget = settings.widgets[idx];
                if (widget.pos == pos) {
                    auto color = lv_color_make(widget.color[0], widget.color[1], widget.color[2]);
                    switch (widget.which_WidgetType) {
                    case blox_Widget_tempSensor_tag: {
                        auto lookup = box.makeCboxPtr<TempSensor>(cbox::obj_id_t(widget.WidgetType.tempSensor));
                        return std::unique_ptr<BaseWidget>(new TemperatureWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_Widget_setpointSensorPair_tag: {
                        auto lookup = box.makeCboxPtr<SetpointSensorPairBlock>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                        return std::unique_ptr<BaseWidget>(new SetpointWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_Widget_actuatorAnalog_tag: {
                        auto lookup = box.makeCboxPtr<ActuatorAnalogConstrained>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                        return std::unique_ptr<BaseWidget>(new ActuatorAnalogWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    case blox_Widget_pid_tag: {
                        auto lookup = box.makeCboxPtr<PidBlock>(cbox::obj_id_t(widget.WidgetType.pid));
                        return std::unique_ptr<BaseWidget>(new PidWidget(grid, std::move(lookup), widget.name, color));
                    } break;
                    default:
                        break;
                    }
                }
            }
            // return base widget as empty placeholder
            return std::unique_ptr<BaseWidget>(new BaseWidget(grid, "empty", LV_COLOR_GRAY));
        };

        for (uint8_t pos = 0; pos < 6; pos++) {
            // find widget settings for position
            sensorWidgets[pos] = makeWidget(pos + 1);
        }
    }
}