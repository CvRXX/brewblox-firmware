target_sources(brewblox PRIVATE
  src/cbox_connection.cpp
  src/cbox_connection_manager.cpp
  src/cbox_stdio_connection.cpp
  src/cbox_tcp_connection.cpp
)

target_include_directories(brewblox PRIVATE
  inc
)
