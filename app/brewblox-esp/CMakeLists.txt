# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

get_filename_component(ESP_ROOT
  ${CMAKE_CURRENT_LIST_DIR}/
  ABSOLUTE
)

get_filename_component(REPO_ROOT
  ${ESP_ROOT}/../../
  ABSOLUTE
)

# Includes
include(${REPO_ROOT}/tools/version.cmake)
include(/opt/esp/idf/tools/cmake/project.cmake)

add_compile_definitions(PLATFORM_ID=100)
add_compile_definitions(PLATFORM_NAME=\"esp32\")
add_compile_definitions(SYSTEM_VERSION_STRING="${SYSTEM_VERSION_STRING}")

list(APPEND EXTRA_COMPONENT_DIRS
  ${REPO_ROOT}/external_libs/cnl
  ${REPO_ROOT}/external_libs/expected
  ${REPO_ROOT}/external_libs/lvgl
  ${REPO_ROOT}/external_libs/nanopb
  ${REPO_ROOT}/lib/blocks
  ${REPO_ROOT}/lib/blox_hal
  ${REPO_ROOT}/lib/cbox
  ${REPO_ROOT}/lib/control
  ${REPO_ROOT}/lib/guis
  ${REPO_ROOT}/lib/proto
  ${REPO_ROOT}/platform/esp
)

set(SYSTEM_VERSION_STRING ${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}.${IDF_VERSION_PATCH})

if(NOT SYSTEM_VERSION_STRING STREQUAL "4.4.1")
    message ( FATAL_ERROR "Found esp-idf ${SYSTEM_VERSION_STRING}, Please check out release 4.4.1 for esp-idf")
endif()

message(STATUS "IDF version: " ${SYSTEM_VERSION_STRING})
set(PROJECT_VER "${GIT_DATE}-${GIT_VERSION}")

project(brewblox_esp)

idf_build_set_property(COMPILE_OPTIONS "-fdiagnostics-color=always" APPEND)
