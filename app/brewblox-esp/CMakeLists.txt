# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

get_filename_component(ESP_ROOT
${CMAKE_CURRENT_LIST_DIR}/
ABSOLUTE)

get_filename_component(REPO_ROOT
${ESP_ROOT}/../../
ABSOLUTE)

execute_process (
    COMMAND git rev-parse --short=8 HEAD
    OUTPUT_VARIABLE GIT_VERSION
    WORKING_DIRECTORY ${REPO_ROOT}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process (
    COMMAND git log -1 --format=%cd --date=short
    OUTPUT_VARIABLE GIT_DATE
    WORKING_DIRECTORY ${REPO_ROOT}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process (
    COMMAND git rev-parse --short=8 HEAD
    OUTPUT_VARIABLE PROTO_VERSION
    WORKING_DIRECTORY ${REPO_ROOT}/external_libs/brewblox-proto
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process (
    COMMAND git log -1 --format=%cd --date=short
    OUTPUT_VARIABLE PROTO_DATE
    WORKING_DIRECTORY ${REPO_ROOT}/external_libs/brewblox-proto
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_definitions(GIT_VERSION=\"${GIT_VERSION}\")
add_compile_definitions(GIT_DATE=\"${GIT_DATE}\")
add_compile_definitions(PROTO_VERSION=\"${PROTO_VERSION}\")
add_compile_definitions(PROTO_DATE=\"${PROTO_DATE}\")
add_compile_definitions(PLATFORM_ID=100)
add_compile_definitions(SYSTEM_VERSION_STRING="${SYSTEM_VERSION_STRING}")
add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)



include($ENV{IDF_PATH}/tools/cmake/project.cmake)

list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/platform)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/platform/all)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/controlbox)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/lib)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/brewblox)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/external_libs)
list(APPEND EXTRA_COMPONENT_DIRS ${REPO_ROOT}/external_libs/lvgl)

set(SYSTEM_VERSION_STRING ${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}.${IDF_VERSION_PATCH})

if(NOT SYSTEM_VERSION_STRING STREQUAL "4.4.0")
    message ( FATAL_ERROR "Found esp-idf ${SYSTEM_VERSION_STRING}, Please check out release 4.4 for esp-idf")
endif()

message(STATUS "Git version: " ${GIT_VERSION})
message(STATUS "Git date: " ${GIT_DATE})
message(STATUS "Proto version: " ${PROTO_VERSION})
message(STATUS "Proto date: " ${PROTO_DATE})
message(STATUS "IDF version: " ${SYSTEM_VERSION_STRING})
set(PROJECT_VER "${GIT_DATE}-${GIT_VERSION}")


project(brewblox_esp)

idf_build_set_property(COMPILE_OPTIONS "-fdiagnostics-color=always" APPEND)
