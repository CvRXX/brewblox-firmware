## -*- Makefile -*-

CCFLAGS = $(CFLAGS)
CXXFLAGS = $(CFLAGS)

ROOT_DIR = $(shell git rev-parse --show-toplevel)

include ../checkers.mk # sanitizer and gcov

# catch test
INCLUDE_DIRS += $(ROOT_DIR)/external_libs/device-os/third_party/catch2/catch2/single_include/catch2

# add all tests
CPPSRC += $(wildcard $(ROOT_DIR)/test/cbox/*.cpp)

# and sources
INCLUDE_DIRS += $(ROOT_DIR)/lib/cbox/inc
CPPSRC += $(wildcard $(ROOT_DIR)/lib/cbox/src/*.cpp)

CFLAGS += -ffunction-sections -Wall

# Flag compiler error for [-Wdeprecated-declarations]
CFLAGS += -Werror=deprecated-declarations

# Generate dependency files automatically.
CFLAGS += -MD -MP -MF $@.d
CFLAGS += -DDEBUG_BUILD

CPPFLAGS += -std=gnu++17
CFLAGS += -pthread

# the following warnings can help find opportunities for impromevent in virtual functions
# Warn when virtual functions are overriden without override/override final specifier (requires gcc 5.1)
CPPFLAGS += -Wsuggest-override
# Warn when functions and classes can be marked final
CPPFLAGS += -Wsuggest-final-types
CPPFLAGS += -Wsuggest-final-methods

# handles building the target from declared sources
include ../targets.mk
