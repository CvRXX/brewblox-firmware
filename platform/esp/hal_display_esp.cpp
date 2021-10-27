#include "TFT035.hpp"
#include <memory>

#include "hal/hal_display.hpp"

namespace platform_display {

static std::unique_ptr<TFT035> display;

void init(void (*finishCallback)(void))
{
    display = std::make_unique<TFT035>(finishCallback);
    acquire();
    display->init();
    release();
}

uint32_t getHorResolution()
{
    return 320;
}
uint32_t getVerResolution()
{
    return 480;
}
uint32_t getRotation()
{
    return LV_DISP_ROT_270;
}

void acquire()
{
    display->aquire_spi();
}

void release()
{
    display->release_spi();
}

void monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
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
}