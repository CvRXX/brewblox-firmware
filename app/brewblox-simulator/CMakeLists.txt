cmake_minimum_required(VERSION 3.10)

# set the project name
project(simulator)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

add_definitions(-DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SIMPLE)



file(GLOB SOURCES
main/*.cpp
../../lib/control/inc/graphics/fonts/*.cpp
../../platform/simulator/*.cpp
../../lib/compiled_proto/proto/*.c
../../external_libs/device-os/third_party/nanopb/nanopb/*.c
../../lib/blocks/*.cpp
../../lib/blocks/blocks/*.cpp
../../lib/cbox/src/*.cpp
)

include_directories(
    ../../platform/simulator
    ../../platform/all
    ../../lib/control/inc
    ../../lib/cbox/src
    ../../lib/compiled_proto
    ../../lib/blocks
    ../../external_libs/cnl/include
    ../../external_libs/device-os/third_party/nanopb/nanopb
    main
    components/lvgl/src
    )


add_subdirectory (components/lvgl)

# add the executable
add_executable(simulator ${SOURCES})
target_link_libraries (simulator LINK_PUBLIC lvgl)
target_link_libraries(simulator PRIVATE Threads::Threads)
