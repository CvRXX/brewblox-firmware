#pragma once
#include <cstdint>

namespace spark4 {
void hw_init();
void expander_init();
void expander_check();
void hw_deinit();
void startup_beep();
void display_brightness(uint8_t b);
}
