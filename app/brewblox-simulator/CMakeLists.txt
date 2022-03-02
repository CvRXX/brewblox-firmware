cmake_minimum_required(VERSION 3.10)

# set the project name
project(simulator)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

add_definitions(-DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SIMPLE)

file(GLOB_RECURSE lvgl_srcs ../../external_libs/lvgl_wrapper/lvgl/src/*.c)


file(GLOB SOURCES
main/*.cpp
../../lib/control/inc/graphics/fonts/*.cpp
../../platform/simulator/*.cpp
# ../../brewblox/blox/compiled_proto/src/*.c
# ../../platform/spark/device-os/third_party/nanopb/nanopb/*.c
../../brewblox/blox
../../controlbox/src/
)

include_directories(
    ../../platform/simulator
    ../../lib/guis
    # ../../lib/inc
    ../../external_libs/cnl/include
    # ../../brewblox/blox/compiled_proto/src
    ../../brewblox
    ../../platform/spark/device-os/third_party/nanopb/nanopb
    ../../controlbox/src/
    main
    ../../external_libs/lvgl_wrapper/lvgl/src
    )


# add the executable
add_executable(simulator ${lvgl_srcs} ${SOURCES})
target_link_libraries(simulator PRIVATE Threads::Threads)
