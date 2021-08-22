#include "graphics.hpp"
#include "TFT035.hpp"
#include "bar.hpp"
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "graphics/widgets.hpp"
#include "lvgl.h"
#include "network/ethernet.hpp"
#include "network/wifi.hpp"

lv_disp_drv_t Graphics::disp_drv;
std::unique_ptr<TFT035> Graphics::display;
std::unique_ptr<Layout> Graphics::layout;

void Graphics::init(cbox::Box& box)
{
    display = std::make_unique<TFT035>([]() { lv_disp_flush_ready(&disp_drv); });
    display->aquire_spi();
    display->init();
    lv_init();
    static lv_disp_buf_t disp_buf1;
    static lv_color_t buf1_1[960];
    static lv_color_t buf1_2[960];
    lv_disp_buf_init(&disp_buf1, buf1_1, buf1_2, 960);

    lv_disp_drv_init(&disp_drv);

    disp_drv.buffer = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    disp_drv.hor_res = 320;
    disp_drv.ver_res = 480;
    disp_drv.rotated = LV_DISP_ROT_270;

    static lv_disp_t* disp;
    disp = lv_disp_drv_register(&disp_drv);
    lv_disp_set_bg_color(disp, LV_COLOR_BLACK);

    style::init();

    layout = std::make_unique<Layout>(box);

    display->release_spi();
}

void Graphics::update()
{
    layout->update();
    display->aquire_spi();
    lv_task_handler();
    display->release_spi();
}

void Graphics::monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
{
    auto nPixels = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
    if (!nPixels) {
        // Log here when a better debug log is available.
    }

    uint8_t* readPtr = reinterpret_cast<uint8_t*>(color_p);
    uint8_t* writePtr = reinterpret_cast<uint8_t*>(color_p);

    for (auto index = 0; index < nPixels; index++) {
        *writePtr = *(readPtr + 2);
        *(writePtr + 1) = *(readPtr + 1);
        *(writePtr + 2) = *readPtr;

        readPtr += 4;
        writePtr += 3;
    }
    display->writePixels(area->x1, area->x2, area->y1, area->y2, reinterpret_cast<uint8_t*>(color_p), nPixels);
}

void Graphics::tick(uint32_t millisElapsed)
{
    lv_tick_inc(millisElapsed);
}

Layout::Layout(cbox::Box& box)
    : box(box)
{
    mainContainer = lv_cont_create(lv_scr_act(), NULL);
    lv_cont_set_fit(mainContainer, LV_FIT_PARENT);
    lv_cont_set_layout(mainContainer, LV_LAYOUT_PRETTY_MID);
    lv_obj_add_style(mainContainer, LV_CONT_PART_MAIN, &style::maincontainer);

    bar = std::make_unique<Bar>(mainContainer);
    grid = lv_cont_create(mainContainer, NULL);
    lv_obj_align_origo(grid, NULL, LV_ALIGN_CENTER, 0, 0); /*These parameters will be used when realigned*/
    lv_obj_set_size(grid, 480, 300);
    lv_cont_set_layout(grid, LV_LAYOUT_PRETTY_MID);
    lv_obj_add_style(grid, LV_CONT_PART_MAIN, &style::grid);
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
                // auto& widget = settings.widgets[idx];
                // if (widget.pos == pos + 1) {
                //     auto color = lv_color_make(widget.color[0], widget.color[1], widget.color[2]);
                //     switch (widget.which_WidgetType) {
                //     case blox_Widget_tempSensor_tag: {
                //         auto lookup = box.makeCboxPtr<TempSensor>(cbox::obj_id_t(widget.WidgetType.tempSensor));
                //         return std::unique_ptr<BaseWidget>(new TemperatureWidget(grid, std::move(lookup), widget.name, color));
                //     } break;
                //     case blox_Widget_setpointSensorPair_tag: {
                //         auto lookup = box.makeCboxPtr<SetpointSensorPairBlock>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                //         return std::unique_ptr<BaseWidget>(new SetpointWidget(grid, std::move(lookup), widget.name, color));
                //     } break;
                //     case blox_Widget_actuatorAnalog_tag: {
                //         auto lookup = box.makeCboxPtr<ActuatorAnalogConstrained>(cbox::obj_id_t(widget.WidgetType.setpointSensorPair));
                //         return std::unique_ptr<BaseWidget>(new ActuatorAnalogWidget(grid, std::move(lookup), widget.name, color));
                //     } break;
                //     case blox_Widget_pid_tag: {
                //         auto lookup = box.makeCboxPtr<PidBlock>(cbox::obj_id_t(widget.WidgetType.pid));
                //         return std::unique_ptr<BaseWidget>(new PidWidget(grid, std::move(lookup), widget.name, color));
                //     } break;
                //     default:
                //         break;
                //     }
                // }
            }
            // return base widget as empty placeholder
            return std::unique_ptr<BaseWidget>{}; // std::unique_ptr<BaseWidget>(new BaseWidget(grid, "empty", LV_COLOR_BLACK));
        };

        for (uint8_t pos = 0; pos < 6; pos++) {
            // find widget settings for this position
            // makeWidget(pos);
        }
    }
}