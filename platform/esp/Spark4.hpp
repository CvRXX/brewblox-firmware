#pragma once
#include "hal/gpio_types.h"
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

static constexpr auto PIN_NUM_MISO = GPIO_NUM_12;
static constexpr auto PIN_NUM_MOSI = GPIO_NUM_13;
static constexpr auto PIN_NUM_CLK = GPIO_NUM_14;
static constexpr auto PIN_NUM_TFT_DC = GPIO_NUM_2;
static constexpr auto PIN_NUM_SD_CS = GPIO_NUM_5;
static constexpr auto PIN_NUM_TFT_CS = GPIO_NUM_4;
static constexpr auto PIN_NUM_I2C_IRQ = GPIO_NUM_35;
static constexpr auto PIN_NUM_I2C_SDA = GPIO_NUM_32;
static constexpr auto PIN_NUM_I2C_SCL = GPIO_NUM_33;
}
