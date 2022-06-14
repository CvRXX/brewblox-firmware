include ../build/platform-id.mk

here_files = $(patsubst $(SOURCE_PATH)/%,%,$(wildcard $(SOURCE_PATH)/$1/$2))

ifeq ($(PLATFORM_ID),3)
# cnl as system includes to suppress warnings
CPPFLAGS += -isystem $(SOURCE_PATH)/external_libs/cnl/cnl/include
else
# arm compiler automatically includes system headers as external c, use normal include
CPPFLAGS += -I $(SOURCE_PATH)/external_libs/cnl/cnl/include
endif

# add lib/blocks
INCLUDE_DIRS += $(SOURCE_PATH)/lib/blocks/inc
CPPSRC += $(call here_files,lib/blocks/src,*.cpp)

# add lib/cbox
INCLUDE_DIRS += $(SOURCE_PATH)/lib/cbox/inc
CPPSRC += $(call here_files,lib/cbox/src,*.cpp)
# don't include file based persistance on spark platform
# arm-gcc doesn't support dirent
CPPEXCLUDES += lib/cbox/src/FileObjectStorage.cpp

# add lib/control
INCLUDE_DIRS += $(SOURCE_PATH)/lib/control/inc
CPPSRC += $(call here_files,lib/control/src,*.cpp)
ifneq ($(PLATFORM_ID),3)
CPPSRC += lib/control/src/spark/TimerInterrupts.cpp
endif

# lib/blox_hal
INCLUDE_DIRS += $(SOURCE_PATH)/lib/blox_hal/inc
CPPSRC += $(call here_files,lib/blox_hal/src,*.cpp)

# lib/proto
INCLUDE_DIRS += $(SOURCE_PATH)/lib/proto/inc
CSRC += $(call here_files,lib/proto/inc/proto,*.c)

# photon/p1 are modular, gcc is not
ifeq ($(PLATFORM_ID),6)
MODULAR?=y
endif
ifeq ($(PLATFORM_ID),8)
MODULAR?=y
endif
ifeq ($(PLATFORM_ID),10)
MODULAR?=y
endif

# expected
INCLUDE_DIRS += $(SOURCE_PATH)/external_libs/expected/expected/include

# nanopb
include $(SOURCE_PATH)/external_libs/device-os/third_party/nanopb/import.mk
ifeq ($(MODULAR),y)
# include sources that are part of nanopb, but not included in shared libraries of particle
CSRC += app/brewblox-particle/nanopb_not_in_particle_dynalib.c
endif

# define platform parameters to avoid -Wundef warnings
CFLAGS += -DLITTLE_ENDIAN=1234
CFLAGS += -DBYTE_ORDER=LITTLE_ENDIAN

# App
INCLUDE_DIRS += $(SOURCE_PATH)/app/brewblox-particle/inc
CPPSRC += $(call here_files,app/brewblox-particle/src,*.cpp)

# platform/particle/d4d_display
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/d4d_display/inc
CPPSRC += $(call target_files,platform/particle/d4d_display/src,*.cpp)
CSRC += $(call target_files,platform/particle/d4d_display/src,*.c)

# platform/particle/eGUI
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/eGUI/D4D
CSRC += $(call target_files,platform/particle/eGUI/D4D,*.c)
CPPSRC +=  $(call target_files,platform/particle/eGUI/D4D,*.cpp)

# platform/particle/mdns
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/mdns/inc
CPPSRC += $(call here_files,platform/particle/mdns/src,*.cpp)

# platform/particle/spark
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/spark/inc
CPPSRC += $(call target_files,platform/particle/spark/src,*.cpp)

# platform/particle/WebSockets
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/WebSockets/firmware
CPPSRC += $(call here_files,platform/particle/WebSockets/firmware,*.cpp)
CSRC += $(call here_files,platform/particle/WebSockets/firmware/libb64,*.c)
CSRC += $(call here_files,platform/particle/WebSockets/firmware/libsha1,*.c)

# platform/particle/ntp
INCLUDE_DIRS += $(SOURCE_PATH)/platform/particle/ntp/inc
CPPSRC += $(call target_files,platform/particle/ntp/src,*.cpp)

# Check whether boost is available
ifeq ($(BOOST_ROOT),)
$(error BOOST_ROOT not set. Download boost and add BOOST_ROOT to your environment variables.)
endif


ifeq ($(PLATFORM_ID),3)
# boost as system includes to suppress warnings
CPPFLAGS += -isystem $(BOOST_ROOT)
else
# arm compiler automatically includes system headers as external c, use normal include
CPPFLAGS += -I $(BOOST_ROOT)
endif


# the following warnings can help find opportunities for impromevent in virtual functions
# they are disabled in the default build, because the dependencies (particle firmware, flashee) have many violations

# Warn when virtual functions are overriden without override/final specifier (requires gcc 5.1)
# CPPFLAGS += -Wsuggest-override
# Warn when functions and classes can be marked final
# CPPFLAGS += -Wsuggest-final-types
# CPPFLAGS += -Wsuggest-final-methods

ifeq ($(PLATFORM_ID),3)
ifeq ("$(TEST_BUILD)","y") # coverage, address sanitizer, undefined behavior
include $(SOURCE_PATH)/test/checkers.mk # sanitizer and gcov
endif
endif

# keep temporary files for disassembly viewer in vscode
CPPFLAGS += -save-temps=obj

# use C++17 and disable warnings about the deprecated register storage class specifier
CPPFLAGS += -std=gnu++17 -Wno-register

LDFLAGS += -Wl,-Map,output.map

CSRC := $(filter-out $(CEXCLUDES),$(CSRC))
CPPSRC := $(filter-out $(CPPEXCLUDES),$(CPPSRC))

GIT_VERSION = $(shell cd $(SOURCE_PATH); git rev-parse --short=8 HEAD)
$(info using $(GIT_VERSION) as version)
CFLAGS += -DGIT_VERSION="\"$(GIT_VERSION)"\"

GIT_DATE = $(shell cd $(SOURCE_PATH); git log -1 --format=%cd --date=short)
$(info using $(GIT_DATE) as release date)
CFLAGS += -DGIT_DATE="\"$(GIT_DATE)\""

PROTO_VERSION = $(shell cd $(SOURCE_PATH)/external_libs/brewblox-proto; git rev-parse --short=8 HEAD)
$(info using $(PROTO_VERSION) as protocol version)
CFLAGS += -DPROTO_VERSION="\"$(PROTO_VERSION)\""

PROTO_DATE = $(shell cd $(SOURCE_PATH)/external_libs/brewblox-proto; git log -1 --format=%cd --date=short)
$(info using $(GIT_DATE) as protocol date)
CFLAGS += -DPROTO_DATE="\"$(PROTO_DATE)\""

COMPILER_VERSION = $(shell $(CC) -dumpfullversion)
$(info using compiler: $(COMPILER_VERSION))
