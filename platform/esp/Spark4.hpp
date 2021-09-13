#pragma once
#include <cstdint>

namespace spark4 {
enum LED_MODE : uint8_t {
    BREATHE,
    BLINK,
};

void set_led(uint8_t R, uint8_t G, uint8_t B, LED_MODE mode, uint8_t duration);

void hw_init();
void expander_init();
void expander_check();
void hw_deinit();
void startup_beep();
void display_brightness(uint8_t b);
void adc_init();
uint32_t adcRead5V();
uint32_t adcReadExternal();
}
