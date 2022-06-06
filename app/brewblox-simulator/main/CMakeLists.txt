target_sources(brewblox PRIVATE
  src/main.cpp
  src/AppLogger.cpp
  src/AppTicks.cpp
  src/Brewblox.cpp
  src/SimulatorApplication.cpp
)

target_include_directories(brewblox PRIVATE
  inc
)
