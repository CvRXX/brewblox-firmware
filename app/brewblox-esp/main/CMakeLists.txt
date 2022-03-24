cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)


idf_component_register(
  SRCS
    blocks/ExpOwGpioBlock.cpp
    main.cpp
    ota.cpp
    AppTicks.cpp
    Brewblox.cpp
    EspApplication.cpp
    EspBox.cpp
    ExpOwGpio.cpp
    I2cScanningFactory.cpp
    TimerInterrupts.cpp
  INCLUDE_DIRS
    .
)
