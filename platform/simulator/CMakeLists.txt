target_sources(brewblox PRIVATE
  src/hal_delay.cpp
  src/hal_i2c.cpp
  src/hal_network.cpp
  src/TimerInterrupts.cpp
  src/virtualScreen.cpp
)

target_include_directories(brewblox PRIVATE
  inc
)
