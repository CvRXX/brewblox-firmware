target_sources(brewblox PRIVATE
  src/main.cpp
  src/AppLogger.cpp
  src/AppTicks.cpp
  src/SimulatorSystem.cpp
  src/SimulatorApplication.cpp
  src/SimulatorBox.cpp
)

target_include_directories(brewblox PRIVATE
  inc
)
