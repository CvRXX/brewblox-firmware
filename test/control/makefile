## -*- Makefile -*-
ROOT_DIR = $(shell git rev-parse --show-toplevel)

# include ../checkers.mk # sanitizer and gcov

# lib/control
INCLUDE_DIRS += $(ROOT_DIR)/lib/control/inc
CPPSRC += $(wildcard $(ROOT_DIR)/lib/control/src/*.cpp)

# lib/blox_hal
# only build the stubs
INCLUDE_DIRS += $(ROOT_DIR)/lib/blox_hal/inc
CPPSRC += $(wildcard $(ROOT_DIR)/platform/stub/*.cpp)

# set cnl as system includes to suppress warnings
CPPFLAGS += -isystem $(ROOT_DIR)/external_libs/cnl/cnl/include

# catch2
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/device-os/third_party/catch2/catch2/single_include/catch2

# test/shared (only include what is needed)
INCLUDE_DIRS += $(ROOT_DIR)/test/shared
CPPSRC += test/shared/AppLogger.cpp

# test/control
CPPSRC += $(ROOT_DIR)/test/control/runner.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorAnalogConstrained_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorAnalogMock_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorDigitalChangeLogged_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorDigitalConstrained_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorOffset_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ActuatorPwm_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ADS124S08_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/FilterChain_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/FixedPoint_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/FpFilterChain_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/hal_spi_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/IiFilter_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/IntervalHelperTest.cpp
CPPSRC += $(ROOT_DIR)/test/control/OneWireMock_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/Pid_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/ringBuffer_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/SetpointProfile_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/SetpointSensorPair_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/staticAllocator_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/Temperature_to_string_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/TempSensorCombi_test.cpp
CPPSRC += $(ROOT_DIR)/test/control/TempSensorMock_test.cpp


CFLAGS += -DPLATFORM_ID=3

# include boost
CPPFLAGS += -isystem $(BOOST_ROOT)

# Generate dependency files automatically.
CFLAGS += -g -Og
CFLAGS += -MD -MP -MF $@.d
CFLAGS += -DDEBUG_BUILD

CFLAGS += -ffunction-sections -Wall
CFLAGS += -Werror=deprecated-declarations

CPPFLAGS += -std=gnu++17
CFLAGS += -pthread

CPPFLAGS += -Wsuggest-override
CPPFLAGS += -Wsuggest-final-types
CPPFLAGS += -Wsuggest-final-methods

# don't generate warnings for system headers
CFLAGS += -Wno-system-headers

# handles building the target from declared sources
include ../targets.mk
