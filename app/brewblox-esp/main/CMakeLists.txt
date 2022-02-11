cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)


idf_component_register(
  SRCS
    main.cpp
    AppTicks.cpp
    brewblox_esp.cpp
    ExpOwGpio.cpp
    I2cScanningFactory.cpp
    blox/ExpOwGpioBlock.cpp
    TimerInterrupts.cpp
    ota.cpp
  INCLUDE_DIRS
    .
  PRIV_REQUIRES
    app_update
    esp_http_client
    bootloader_support
    nvs_flash
  REQUIRES
    compiled_proto
    controlbox
    lib
    esp
    httpserver
    spiffs
    external_libs
)
