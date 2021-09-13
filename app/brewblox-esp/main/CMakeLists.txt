cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(srcs 
  main.cpp
  AppTicks.cpp
  brewblox_esp.cpp
  ExpOwGpio.cpp
  I2cScanningFactory.cpp
  blox/ExpOwGpioBlock.cpp
  TimerInterrupts.cpp
  network/CboxConnection.cpp
  network/CboxTcpConnection.cpp
  network/CboxConnectionManager.cpp
  network/CboxStdioConnection.cpp
  ota.cpp
 )

file(GLOB network_srcs ./network/*.cpp)
file(GLOB http_srcs ./httpserver/*.cpp)
file(GLOB graphics_srcs ../../../platform/all/graphics/*.cpp ../../../platform/all/graphics/fonts/*.c ../../../platform/all/graphics/widgets/*.cpp)

file(GLOB cbox_srcs ../../../controlbox/src/cbox/*.cpp)
set(cbox_inc "../../../controlbox/src/")

file(GLOB brewblox_srcs ../../../brewblox/*.cpp ../../../brewblox/blox/*.cpp ../../../brewblox/blox/compiled_proto/src/*.c)
set(brewblox_inc "../../../brewblox/")

file(GLOB esp_srcs ../../../platform/esp/*.cpp ../../../platform/esp/*.c)
set(esp_inc "../../../platform/esp/")

file(GLOB lib_srcs ../../../lib/src/*.cpp)
set(lib_inc "../../../lib/inc/")

set(cnl_inc "../../../lib/cnl/include")

file(GLOB nanopb_srcs ../../../platform/spark/device-os/third_party/nanopb/nanopb/*.c)
set(nanopb_inc "../../../platform/spark/device-os/third_party/nanopb/nanopb")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGIT_VERSION=\\\"${GIT_VERSION}\\\"")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGIT_DATE=\\\"${GIT_DATE}\\\"")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROTO_VERSION=\\\"${PROTO_VERSION}\\\"")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROTO_DATE=\\\"${PROTO_DATE}\\\"")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_ID=100")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSYSTEM_VERSION_STRING=${SYSTEM_VERSION_STRING}") # not quoted for compatibility with particle
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLV_LVGL_H_INCLUDE_SIMPLE")


idf_component_register(
  SRCS
    ${srcs}
    ${graphics_srcs}
    ${cbox_srcs}
    ${brewblox_srcs}
    ${lib_srcs}
    ${esp_srcs}
    ${nanopb_srcs}
    ${network_srcs}
    ${http_srcs}
  INCLUDE_DIRS 
    .
    ${REPO_ROOT}/brewblox/blox/compiled_proto/src
    ${brewblox_inc}
    ${nanopb_inc}
    ${cbox_inc}
    ${lib_inc}
    ${cnl_inc}
    ${esp_inc}
    ${REPO_ROOT}/platform/all
)
