#include "graphics.hpp"
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "hal/hal_display.hpp"
#include "layout.hpp"
#include "lvgl.h"

lv_disp_drv_t Graphics::disp_drv;
std::unique_ptr<Layout> Graphics::layout;

void Graphics::init(cbox::Box& box)
{
    platform_display::init([]() { lv_disp_flush_ready(&disp_drv); });
    lv_init();
    static lv_disp_buf_t disp_buf1;
    static lv_color_t buf1_1[960];
    static lv_color_t buf1_2[960];
    lv_disp_buf_init(&disp_buf1, buf1_1, buf1_2, 960);

    lv_disp_drv_init(&disp_drv);

    disp_drv.buffer = &disp_buf1;
    disp_drv.flush_cb = platform_display::monitor_flush;
    disp_drv.hor_res = platform_display::getHorResolution();
    disp_drv.ver_res = platform_display::getVerResolution();
    disp_drv.rotated = platform_display::getRotation();

    static lv_disp_t* disp;
    disp = lv_disp_drv_register(&disp_drv);
    lv_disp_set_bg_color(disp, LV_COLOR_BLACK);

    style::init();

    layout = std::make_unique<Layout>(box);
}

void Graphics::update()
{
    layout->update();
    platform_display::acquire();
    lv_task_handler();
    platform_display::release();
}

void Graphics::tick(uint32_t millisElapsed)
{
    lv_tick_inc(millisElapsed);
}
