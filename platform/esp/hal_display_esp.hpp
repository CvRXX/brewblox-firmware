#include "TFT035.hpp"
#include "lvgl.h"
#include <memory>

/// The display implementation of the esp version of the spark.
class DisplayEsp {
public:
    /**
     * Initialises the display.
     * @param finishCallback This function pointer is called after the pixels have been transferred to the screen.
     */
    static void init(void (*finishCallback)(hal_spi::TransactionData& transaction))
    {
        display = std::make_unique<TFT035>(finishCallback);
        display->init();
    }

    /// Returns the horizontal resultion of the screen.
    static uint32_t getHorResolution()
    {
        return 320;
    }

    /// Returns the vertical resultion of the screen.
    static uint32_t getVerResolution()
    {
        return 480;
    }

    /// Returns the rotation of the screen.
    static uint32_t getRotation()
    {
        return LV_DISP_ROT_270;
    }

    /// Takes ownership of the bus.
    static void acquire()
    {
        display->acquire_spi();
    }

    /// Releases ownership of the bus.
    static void release()
    {
        display->release_spi();
    }

    /**
     * Writes pixels to the screen.
     * The pixels are written asynchronously and the callback passed to init is called after the pixels are written. 
     * @param disp_drv The lvgl driver that this screen belongs to.
     * @param area The are of the screen to be written.
     * @param color_p A pointer pointing to the first color in the buffer to be written.
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

private:
    static std::unique_ptr<TFT035> display;
};

std::unique_ptr<TFT035> DisplayEsp::display{};
