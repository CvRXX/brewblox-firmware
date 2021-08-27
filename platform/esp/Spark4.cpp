#include "Spark4.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <driver/adc.h>
#include <driver/gpio.h>
#include <esp_event.h>
#include <nvs_flash.h>
#pragma GCC diagnostic pop

#include "SX1508.hpp"
#include "driver/gpio.h"
#include "esp_adc_cal.h"
#include "hal/hal_delay.h"
#include "hal/hal_i2c.h"
#include "hal/hal_spi.hpp"
#include "soc/adc_channel.h"
#include <esp_log.h>

namespace spark4 {

constexpr auto PIN_NUM_MISO = GPIO_NUM_12;
constexpr auto PIN_NUM_MOSI = GPIO_NUM_13;
constexpr auto PIN_NUM_CLK = GPIO_NUM_14;
constexpr auto PIN_NUM_DC = GPIO_NUM_2;
constexpr auto PIN_NUM_SD_CS = GPIO_NUM_5;
constexpr auto PIN_NUM_TFT_CS = GPIO_NUM_4;
constexpr auto PIN_NUM_I2C_IRQ = GPIO_NUM_35;
constexpr auto PIN_NUM_I2C_SDA = GPIO_NUM_32;
constexpr auto PIN_NUM_I2C_SCL = GPIO_NUM_33;

SX1508 expander(0);

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
    gpio_set_direction(PIN_NUM_DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_NUM_I2C_IRQ, GPIO_MODE_INPUT);
    gpio_set_pull_mode(PIN_NUM_MISO, GPIO_PULLUP_ONLY);
    gpio_pullup_en(PIN_NUM_MISO);
    gpio_set_level(PIN_NUM_SD_CS, 1);
    gpio_set_level(PIN_NUM_TFT_CS, 1);

    // use weakest drive on 50Mhz oscillator pin for phy
    // using normal drive strength creates overshoot and clamping
    // weakest strength gives a nicer oscillation and much better EMC
    gpio_set_drive_capability(GPIO_NUM_0, GPIO_DRIVE_CAP_0);
    // use low drive strenght for SPI.
    // Fast rise time will bypass mux that disconnects external SPI
    gpio_set_drive_capability(PIN_NUM_MOSI, GPIO_DRIVE_CAP_0);
    gpio_set_drive_capability(PIN_NUM_CLK, GPIO_DRIVE_CAP_0);

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
    }
    ESP_LOGE("Spark4", "Re-initializing on-board port expander");
    expander_init(); // device has reset
}

void expander_init()
{
    expander.reset();

    // Disable input for RGB LED and TFT backlight
    expander.write_reg(SX1508::RegAddr::inputDisable, 0b11101000);
    // Disable pullup for RGB LED and TFT backlight
    expander.write_reg(SX1508::RegAddr::pullUp, 0b00010111);
    // Set direction
    expander.write_reg(SX1508::RegAddr::dir, 0b00010111);
    // Enable open drain for RGB LED, TFT backlight is push/pull
    expander.write_reg(SX1508::RegAddr::openDrain, 0b11001000);
    // logarithmic fading for RGB, PWM frequendy 250 Hz, reset is POR, auto increment register, auto clean nint on read
    expander.write_reg(SX1508::RegAddr::misc, 0b11101000);
    // enable led driver on RGB and backlight
    expander.write_reg(SX1508::RegAddr::ledDriverEnable, 0b11101000);

    // Configure Blue and Green for breathing
    expander.write_reg(SX1508::RegAddr::iOn3, 128);
    expander.write_reg(SX1508::RegAddr::tRise3, 3);
    expander.write_reg(SX1508::RegAddr::tOn3, 1);
    expander.write_reg(SX1508::RegAddr::tFall3, 3);
    expander.write_reg(SX1508::RegAddr::off3, 0b00001010); // 1 period off, intensity 2

    expander.write_reg(SX1508::RegAddr::iOn7, 128);
    expander.write_reg(SX1508::RegAddr::tRise7, 3);
    expander.write_reg(SX1508::RegAddr::tOn7, 1);
    expander.write_reg(SX1508::RegAddr::tFall7, 3);
    expander.write_reg(SX1508::RegAddr::off7, 0b00001010); // 1 period off, intensity 2

    // Configure Red for blinking, but disabled now
    expander.write_reg(SX1508::RegAddr::iOn6, 0);
    expander.write_reg(SX1508::RegAddr::tOn6, 15);
    expander.write_reg(SX1508::RegAddr::off6, 0b01111000); // 1 period off, intensity 0

    // Configure backlight PWM at 50%
    display_brightness(128);

    // Enable outputs
    expander.write_reg(SX1508::RegAddr::data, 0x00);

    // beep also configures clock, which is on the same register
    startup_beep();
}

void hw_deinit()
{
    gpio_uninstall_isr_service();
    nvs_flash_deinit();
}

void display_brightness(uint8_t b)
{
    if (b < 20) {
        b = 128; // if a too low value is set, revert back to default
    }
    // enable signal should be inverted
    expander.write_reg(SX1508::RegAddr::iOn5, uint8_t{255} - b);
}

void startup_beep()
{
    expander.write_reg(SX1508::RegAddr::clock, 0b01011011);
    hal_delay_ms(200);
    expander.write_reg(SX1508::RegAddr::clock, 0b01011010);
    hal_delay_ms(200);
    expander.write_reg(SX1508::RegAddr::clock, 0b01010000);
}

esp_adc_cal_characteristics_t adc_characteristics;
void adc_init()
{
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_6db);
    adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_6db);
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_6db, ADC_WIDTH_BIT_12, 1100, &adc_characteristics);
}

uint32_t adcRead5V()
{

    uint32_t voltage;
    if (!esp_adc_cal_get_voltage(adc_channel_t(ADC1_CHANNEL_0), &adc_characteristics, &voltage)) {
        // voltage divider 10k and 4k7
        return voltage + (voltage * 100) / 47;
    }
    return 0;
}

uint32_t adcReadExternal()
{
    uint32_t voltage;
    if (!esp_adc_cal_get_voltage(adc_channel_t(ADC1_CHANNEL_3), &adc_characteristics, &voltage)) {
        // voltage divider 88k7 and 4k7
        return voltage + (voltage * 887) / 47;
    }
    return 0;
}

// Expander pins:
// 0,1,2,4 -> EX0, EX1, EX2, EX3 (interrupt inputs)
// 3, 6, 7 -> LED B, R, G. (B and G support breathing)
// 5 -> LCD backlight

}