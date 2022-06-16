get_filename_component(REPO_ROOT
  ${CMAKE_CURRENT_LIST_DIR}/../
  ABSOLUTE
)

execute_process(
  COMMAND git rev-parse --short=8 HEAD
  OUTPUT_VARIABLE GIT_VERSION
  WORKING_DIRECTORY ${REPO_ROOT}
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git log -1 --format=%cd --date=short
  OUTPUT_VARIABLE GIT_DATE
  WORKING_DIRECTORY ${REPO_ROOT}
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git rev-parse --short=8 HEAD
  OUTPUT_VARIABLE PROTO_VERSION
  WORKING_DIRECTORY ${REPO_ROOT}/external_libs/brewblox-proto
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git log -1 --format=%cd --date=short
  OUTPUT_VARIABLE PROTO_DATE
  WORKING_DIRECTORY ${REPO_ROOT}/external_libs/brewblox-proto
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_definitions(GIT_VERSION=\"${GIT_VERSION}\")
add_compile_definitions(GIT_DATE=\"${GIT_DATE}\")
add_compile_definitions(PROTO_VERSION=\"${PROTO_VERSION}\")
add_compile_definitions(PROTO_DATE=\"${PROTO_DATE}\")

message(STATUS "Git version: " ${GIT_VERSION})
message(STATUS "Git date: " ${GIT_DATE})
message(STATUS "Proto version: " ${PROTO_VERSION})
message(STATUS "Proto date: " ${PROTO_DATE})
