#include "lvgl.h"
#include <cstdint>

namespace platform_display {

void init(void (*finishCallback)(void));

uint32_t getHorResolution();
uint32_t getVerResolution();
uint32_t getRotation();

void acquire();
void release();

void monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p);

}