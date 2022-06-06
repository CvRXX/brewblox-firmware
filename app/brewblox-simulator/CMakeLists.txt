cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

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

# External packages
find_package(Threads REQUIRED)

add_compile_definitions(PLATFORM_ID=200)
add_compile_definitions(PLATFORM_NAME=\"sim\")

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
# add_subdirectory(components/network)

foreach(comp IN ITEMS ${components})
  add_subdirectory(${REPO_ROOT}/${comp} ./${comp})
endforeach()

# Link against system libraries
target_link_libraries(brewblox PRIVATE
  Threads::Threads
)
