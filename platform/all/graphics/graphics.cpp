#include "graphics.hpp"
#include "TFT035.hpp"
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "layout.hpp"
#include "lvgl.h"

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
