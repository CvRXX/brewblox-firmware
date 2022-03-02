#pragma once
#include <array>
#include <lvgl.h>
#include <memory>

/// Represents the graphics for the TFT screen of the Spark 4.
template <typename Display, typename Touchscreen, typename GUI>
class Graphics {
public:
    /**
     * This function will be called by lvgl to write pixels to the screen.
     * @param disp_drv A pointer to the display driver as saved by lvgl.
     * @param area The area of pixels to be written.
     * @param color_p A pointer to the beginning of the pixels to be written.
     */
    static void monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
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

    /**
     * Initialises the graphics module.
     * @param box The Cbox box.
     */
    static void init()
    {
        display = std::make_unique<Display>([]() { lv_disp_flush_ready(&disp_drv); });
        display->aquire_spi();
        display->init();
        lv_init();
        static lv_disp_draw_buf_t disp_buf1;
        static lv_color_t buf1_1[960];
        static lv_color_t buf1_2[960];
        lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, 960);

        lv_disp_drv_init(&disp_drv);

        disp_drv.draw_buf = &disp_buf1;
        disp_drv.flush_cb = monitor_flush;
        disp_drv.hor_res = 320;
        disp_drv.ver_res = 480;
        disp_drv.rotated = LV_DISP_ROT_270;

        static lv_disp_t* disp;
        disp = lv_disp_drv_register(&disp_drv);
        lv_disp_set_bg_color(disp, lv_color_black());

        gui = std::make_unique<GUI>();

        display->release_spi();
        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);

        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = checkForTouches;
        touchscreen = std::make_unique<Touchscreen>(0x00);
        touchscreen->init();
        lv_indev_drv_register(&indev_drv);
    }

    /**
     * Updates the gui and calls the lvgl task handler.
     */
    static void update()
    {
        gui->update();
        display->aquire_spi();
        lv_task_handler();
        display->release_spi();
    }

    /**
     * Indicates to lvlg that a certain amount of time has elapsed.
     * @param millisElapsed amount of time that has elapsed since the last call in ms.
     */
    static void tick(uint32_t millisElapsed)
    {
        lv_tick_inc(millisElapsed);
    }

private:
    static void checkForTouches(lv_indev_drv_t* drv, lv_indev_data_t* data)
    {
        if (auto touch = touchscreen->getTouch()) {
            data->point.x = touch->x;
            data->point.y = touch->y;
            data->state = LV_INDEV_STATE_PR;
        } else {
            auto lastTouch = touchscreen->getLastTouch();
            data->point.x = lastTouch.x;
            data->point.y = lastTouch.y;
            data->state = LV_INDEV_STATE_REL;
        }
    }
    static lv_disp_drv_t disp_drv;
    static std::unique_ptr<Display> display;
    static std::unique_ptr<GUI> gui;
    static std::unique_ptr<Touchscreen> touchscreen;
};

template <typename Display, typename Touchscreen, typename GUI>
std::unique_ptr<Display> Graphics<Display, Touchscreen, GUI>::display;

template <typename Display, typename Touchscreen, typename GUI>
std::unique_ptr<GUI> Graphics<Display, Touchscreen, GUI>::gui;

template <typename Display, typename Touchscreen, typename GUI>
std::unique_ptr<Touchscreen> Graphics<Display, Touchscreen, GUI>::touchscreen;

template <typename Display, typename Touchscreen, typename GUI>
lv_disp_drv_t Graphics<Display, Touchscreen, GUI>::disp_drv;
