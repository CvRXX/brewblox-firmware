#if 0
#include "App.h"
#include "httpserver/server.hpp"
#include "network/Ethernet.h"
#include "network/Server.hpp"
#include "network/Wifi.h"
#include "network/wifi_creds.h"
#include <asio.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <driver/gpio.h>
#include <nvs_flash.h>
#pragma GCC diagnostic pop

#include "ADS124S08.hpp"
#include "ChemSense.hpp"
#include "PCA9555.hpp"
#include "esp_log.h"
#include "hal/hal_i2c.h"
#include <string>

using namespace std::chrono;
using tcp = asio::ip::tcp;

App::App()
    : io_expander{0x20}
    , ads{
          0,                       // select spi idx 0 on platform
          -1,                      // no SS pin (io expander pin set in onAquire and onRelease)
          [this](bool pinIsHigh) { // set reset pin
              io_expander.set_output(3, pinIsHigh);
          },
          [this](bool pinIsHigh) { // set start pin
              io_expander.set_output(5, pinIsHigh);
          },
          [this]() {              // read ready pin state
              bool result = true; // default to high (not ready) in case of i2c error
              io_expander.get_input(10, result);
              return result;
          },
          [this]() { // cs low
              io_expander.set_output(4, false);
          },
          [this]() { // cs high
              io_expander.set_output(4, true);
          }}
{
    nvs_flash_init();
    gpio_install_isr_service(0);
    esp_event_loop_create_default();
}

App::~App()
{
    esp_event_loop_delete_default();
    gpio_uninstall_isr_service();
    nvs_flash_deinit();
}

void App::start()
{
    init_hw();
    init_asio();
    //init_tcp81();

    /*while (true) {
        auto nextChan = chemSense.update();
        if (nextChan == 0) {
            ESP_LOGI("adc read", "%d, %d, %d, %d",
                     chemSense.results[0],
                     chemSense.results[1],
                     chemSense.results[2],
                     chemSense.results[3]);
        }

        hal_delay_ms(245);
    }*/
}

void App::init_hw()
{
    hal_i2c_master_init();

    auto err = io_expander.set_directions(0x0700);
    if (err != 0) {
        ESP_LOGW("app", "io_expander error: %d", err);
    }

    io_expander.set_output(0, true);
    io_expander.set_output(1, false);
    io_expander.set_output(2, true);
    ESP_LOGW("app", "io_expander initialized");

    if (!ads.startup()) {
        ESP_LOGE("ADC", "Init failed");
        exit(1);
    }
}

// asio::io_context& App::get_io_context()
// {
//     static asio::io_context* context = new asio::io_context;
//     return *context;
// }

void App::init_asio()
{
    asio::io_context io;

    std::array<int32_t, 4> sensor_values = {0};
    std::array<std::string, 4> sensor_values_str; // in mv and ohm, 3 decimals

    chemSense = new ChemSense{
        ads, io, [&sensor_values, &sensor_values_str](const std::array<int32_t, 4>& results) {
            // update local copy of sensor values
            sensor_values = results;
            // print to log
            //ESP_LOGI("Sensors", "%d, %d, %d, %d", results[0], results[1], results[2], results[3]);
            auto mvResults = ChemSense::convertToMilliVolt(results);
            ESP_LOGI("Sensors", "%d, %d, %d, %d", results[0], results[1], results[2], results[3]);
            auto resultStr = sensor_values_str.begin();
            for (auto& v : mvResults) {
                *resultStr++ = to_string_dec(v, 3);
            }
            ESP_LOGI("Sensors", "%s, %s, %s, %s",
                     sensor_values_str[0].c_str(),
                     sensor_values_str[1].c_str(),
                     sensor_values_str[2].c_str(),
                     sensor_values_str[3].c_str());
        }};

    http::server::server s(io, 80);

    s.add_uri_handler("/", "text/html", [](std::string& content) {
        content.append(
            R"(<!doctype html>)"
            R"(<html lang=en>)"
            R"(<head>)"
            R"(<meta charset=utf-8>)"
            R"(<title>ChemSense</title>)"
            R"(</head>)"
            R"(<body>)"
            R"(<p>)"
            R"(<a href="/test">Test page</a>)"
            R"(<br />)"
            R"(<a href="/sensors">Sensors JSON</a>)"
            R"(</p>)"
            R"(<div id="sensors"/>)"
            R"(<script>)"
            R"(var interval = setInterval(function () {)"
            R"(fetch('/sensors').then(function (response) {)"
            R"(return response.json();}).then(function(data){)"
            R"(var el = document.getElementById("sensors"); el.innerHTML = JSON.stringify(data);)"
            R"(}).catch(function (err) { console.log('error: ' + err); });)"
            R"(}, 1000);)"
            R"(</script>"))");
        // ending tags are implicit
    });

    s.add_uri_handler("/test", "text/html", [](std::string& content) {
        content.append("It works!");
    });

    s.add_uri_handler("/sensors", "application/json", [&sensor_values_str](std::string& content) {
        content.reserve(80);
        content.append(R"({"ph[mV]":)");
        content.append(sensor_values_str[0]);
        content.append(R"(,"orp[mV]":)");
        content.append(sensor_values_str[1]);
        content.append(R"(,"rt1[Ohm]":)");
        content.append(sensor_values_str[2]);
        content.append(R"(,"rtd2[Ohm]":)");
        content.append(sensor_values_str[3]);
        content.append("}");
    });
    io.run();
}

void App::init_tcp81()
{
    // Server srv(get_io_context(), tcp::endpoint(tcp::v4(), 81));
}
#endif