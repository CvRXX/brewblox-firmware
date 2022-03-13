cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)


idf_component_register(
  SRCS
    main.cpp
    AppTicks.cpp
    Brewblox.cpp
    EspApplication.cpp
    ExpOwGpio.cpp
    I2cScanningFactory.cpp
    blocks/ExpOwGpioBlock.cpp
    TimerInterrupts.cpp
    ota.cpp
  INCLUDE_DIRS
    .
)
