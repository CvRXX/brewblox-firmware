target_sources(brewblox PRIVATE
  src/hal_delay_stub.cpp
  src/hal_i2c_stub.cpp
  src/TimerInterrupts_stub.cpp
  src/virtualScreen.cpp
)

target_include_directories(brewblox PRIVATE
  inc
)
