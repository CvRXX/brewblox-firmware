cmake_minimum_required(VERSION 3.10)

# set the project name
project(simulator)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_definitions(-DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SIMPLE)

file(GLOB_RECURSE lvgl_srcs ../../external_libs/lvgl_wrapper/lvgl/src/*.c)


file(GLOB SOURCES
main/*.cpp
../../lib/control/inc/graphics/fonts/*.cpp
../../lib/guis/dynamic_gui/styles/*.cpp
../../lib/guis/dynamic_gui/fonts/*.c
../../platform/simulator/*.cpp
../../external_libs/nanopb/*.c
../../brewblox/blox
../../controlbox/src/
../../lib/proto/inc/proto/*.c
)

include_directories(
    ../../platform/simulator
    ../../lib/guis
    ../../lib/proto/inc
    ../../external_libs/cnl/include
    ../../external_libs/nanopb
    ../../brewblox
    ../../platform/spark/device-os/third_party/nanopb/nanopb
    ../../controlbox/src/
    main
    ../../external_libs/lvgl_wrapper/lvgl/src
    )


# add the executable
add_executable(simulator ${lvgl_srcs} ${SOURCES})
target_link_libraries(simulator PRIVATE Threads::Threads)
