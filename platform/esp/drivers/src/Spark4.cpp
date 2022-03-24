#include "drivers/Spark4.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <driver/adc.h>
#include <driver/gpio.h>
#include <esp_event.h>
#include <nvs_flash.h>
#pragma GCC diagnostic pop

#include "blox_hal/hal_delay.hpp"
#include "blox_hal/hal_i2c.hpp"
#include "blox_hal/hal_spi.hpp"
#include "control/SX1508.hpp"
#include "driver/gpio.h"
#include "esp_adc_cal.h"
#include "soc/adc_channel.h"
#include <esp_log.h>

namespace spark4 {

SX1508 expander(0);
uint8_t backLightPwm = 128;

void hw_init()
{
    /* Initialize NVS partition */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        /* NVS partition was truncated
         * and needs to be erased */
        ESP_ERROR_CHECK(nvs_flash_erase());

        /* Retry nvs_flash_init */
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    /* Initialize TCP/IP */
    ESP_ERROR_CHECK(esp_netif_init());

    esp_event_loop_create_default();
    gpio_install_isr_service(0);

    gpio_set_direction(PIN_NUM_MISO, GPIO_MODE_INPUT);
    gpio_set_direction(PIN_NUM_MOSI, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_SD_CS, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_TFT_CS, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_CLK, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_TFT_DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_I2C_IRQ, GPIO_MODE_INPUT);
    gpio_set_pull_mode(PIN_NUM_MISO, GPIO_PULLUP_ONLY);
    gpio_pullup_en(PIN_NUM_MISO);
    gpio_set_level(PIN_NUM_SD_CS, 1);
    gpio_set_level(PIN_NUM_TFT_CS, 1);

    // use weakest drive on 50Mhz oscillator pin for phy
    // using normal drive strength creates overshoot and clamping
    // weakest strength gives a nicer oscillation and much better EMC
    gpio_set_drive_capability(GPIO_NUM_0, GPIO_DRIVE_CAP_0);
    // use low drive strength for SPI.
    // Fast rise time gives ringing and can bypass mux that disconnects external SPI
    gpio_set_drive_capability(PIN_NUM_MOSI, GPIO_DRIVE_CAP_0);
    gpio_set_drive_capability(PIN_NUM_CLK, GPIO_DRIVE_CAP_0);
    gpio_set_drive_capability(PIN_NUM_TFT_CS, GPIO_DRIVE_CAP_0);
    gpio_set_drive_capability(PIN_NUM_TFT_DC, GPIO_DRIVE_CAP_0);

    hal_i2c_master_init();
    hal_spi_host_init(0);

    expander_init();
}

void expander_check()
{
    uint8_t misc = 0;
    if (expander.read_reg(SX1508::RegAddr::misc, misc)) {
        // i2c comms succeeded
        if (misc != 0x00) {
            // device is not in default state
            return;
        }
        // device has reset and needs to be configured again
        ESP_LOGE("Spark4", "Re-initializing on-board port expander");
        expander_init();
    }
    ESP_LOGE("Spark4", "I2c error in expander_check");
}

void set_led(uint8_t R, uint8_t G, uint8_t B, LED_MODE mode, uint8_t duration)
{
    uint8_t tOn3 = duration;
    uint8_t tOn7 = duration;
    uint8_t tOn6 = duration;
    uint8_t off3 = duration << 3;
    uint8_t off7 = duration << 3;
    uint8_t off6 = duration << 3;
    uint8_t tRise3 = 0;
    uint8_t tFall3 = 0;
    uint8_t tRise7 = 0;
    uint8_t tFall7 = 0;

    if (mode == BREATHE) {
        // green
        tOn3 = 1;
        tRise3 = duration - 1;
        tFall3 = duration - 1;
        off3 = 0b00001010; // period off, intensity 2
        tOn7 = 1;
        tRise7 = duration - 1;
        tFall7 = duration - 1;
        off7 = 0b00001010; // period off, intensity 2
    }

    expander.i2c_write(std::array<uint8_t, 16>({
        uint8_t(SX1508::RegAddr::tOn3), // start address
        tOn3,                           // tOn3
        B,                              // iOn3
        off3,                           // off3
        tRise3,                         // tRise3
        tFall3,                         // tFall3
        0,                              // iOn4, led driver is disdabled on this pin but by including it we can use a single transaction
        backLightPwm,                   // iOn5
        tOn6,                           // tOn6
        R,                              // iOn6
        off6,                           // off6
        tOn7,                           // tOn7
        G,                              // iOn7
        off7,                           // off7
        tRise7,                         // tRise7
        tFall7,                         // tFall7
    }));
}

void expander_init()
{
    uint8_t outputs = 0b11101000;
    expander.reset();

    // beep also configures clock, which is on the same register
    beep(Beep::OFF);

    // Disable input for RGB LED and TFT backlight
    expander.write_reg(SX1508::RegAddr::inputDisable, outputs);
    // Disable pullup for RGB LED and TFT backlight
    expander.write_reg(SX1508::RegAddr::pullUp, ~outputs);
    // Set direction
    expander.write_reg(SX1508::RegAddr::dir, ~outputs);
    // Enable open drain for RGB LED, TFT backlight is push/pull
    expander.write_reg(SX1508::RegAddr::openDrain, 0b11001000);
    // logarithmic fading for RGB, PWM frequendy 1 kHz, reset is counter reset, auto increment register, auto clean nint on read
    // reset is only triggered by ESD or otherwise unintentionally, so let it only reset the counters
    expander.write_reg(SX1508::RegAddr::misc, 0b11001100);

    // enable led drivers on outputs
    expander.write_reg(SX1508::RegAddr::ledDriverEnable, outputs);

    // Blink fast orange during boot
    set_led(128, 128, 0, LED_MODE::BLINK, 2);

    // Enable outputs
    expander.write_reg(SX1508::RegAddr::data, ~outputs);
}

void hw_deinit()
{
    gpio_uninstall_isr_service();
    nvs_flash_deinit();
}

void display_brightness(uint8_t b)
{
    if (b < 20) {
        backLightPwm = 128; // if a too low value is set, revert back to default
    } else {
        backLightPwm = 255 - b;
    }
    // enable signal should be inverted
    expander.write_reg(SX1508::RegAddr::iOn5, backLightPwm);
}

void beep(Beep freq)
{
    uint8_t v = uint8_t(0b01010000) + uint8_t(freq);
    expander.write_reg(SX1508::RegAddr::clock, v);
}

void startup_beep()
{
    beep(Beep::LOW);
    hal_delay_ms(200);
    beep(Beep::MID);
    hal_delay_ms(200);
    beep(Beep::OFF);
}

esp_adc_cal_characteristics_t adc_characteristics;
void adc_init()
{
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_6db);
    adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_6db);
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_6db, ADC_WIDTH_BIT_12, 1100, &adc_characteristics);
}

uint32_t adcRead5V(bool cached)
{
    static uint32_t voltage;
    if (!cached) {
        uint32_t result;
        if (!esp_adc_cal_get_voltage(adc_channel_t(ADC1_CHANNEL_0), &adc_characteristics, &result)) {
            // voltage divider 10k and 4k7
            voltage = result + (result * 100) / 47;
        }
    }
    return voltage;
}

uint32_t adcReadExternal(bool cached)
{
    static uint32_t voltage;
    if (!cached) {
        uint32_t result;
        if (!esp_adc_cal_get_voltage(adc_channel_t(ADC1_CHANNEL_3), &adc_characteristics, &result)) {
            // voltage divider 88k7 and 4k7
            voltage = result + (result * 887) / 47;
        }
    }
    return voltage;
}

// Expander pins:
// 0,1,2,4 -> EX0, EX1, EX2, EX3 (interrupt inputs)
// 3, 6, 7 -> LED B, R, G. (B and G support breathing)
// 5 -> LCD backlight
}
