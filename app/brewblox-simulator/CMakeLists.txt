cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_RULE_MESSAGES OFF)

cmake_policy(SET CMP0076 NEW)

# Declare the project
project(brewblox_sim)
add_executable(brewblox)

# Get system variables
get_filename_component(APP_ROOT
  ${CMAKE_CURRENT_LIST_DIR}/
  ABSOLUTE
)

get_filename_component(REPO_ROOT
  ${APP_ROOT}/../../
  ABSOLUTE
)

# Includes
include(${REPO_ROOT}/tools/version.cmake)

set(SYSTEM_VERSION_STRING ${CMAKE_CXX_COMPILER_VERSION})

add_compile_definitions(PLATFORM_ID=200)
add_compile_definitions(PLATFORM_NAME=\"sim\")
add_compile_definitions(SYSTEM_VERSION_STRING=${SYSTEM_VERSION_STRING})

set(components
  external_libs/cnl
  external_libs/expected
  external_libs/lvgl
  external_libs/nanopb
  lib/blocks
  lib/blox_hal
  lib/cbox
  lib/control
  lib/guis/dynamic_gui
  lib/proto
  platform/simulator
)

add_subdirectory(main)
# add_subdirectory(components/httpserver)
add_subdirectory(components/network)

foreach(comp IN ITEMS ${components})
  add_subdirectory(${REPO_ROOT}/${comp} ./${comp})
endforeach()

find_package(Boost REQUIRED
  COMPONENTS
    system
    program_options
    random
    thread
)

target_link_libraries(brewblox PRIVATE
  ${Boost_LIBRARIES}
)
