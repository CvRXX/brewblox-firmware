include ../build/platform-id.mk

here_files = $(patsubst $(SOURCE_PATH)/%,%,$(wildcard $(SOURCE_PATH)/$1/$2))

# add all lib source files
INCLUDE_DIRS += $(SOURCE_PATH)/lib/control/inc
CPPSRC += $(call here_files,lib/control/src,*.cpp)
ifneq ($(PLATFORM_ID),3)
CPPSRC += lib/control/src/spark/TimerInterrupts.cpp
endif

ifeq ($(PLATFORM_ID),3)
# cnl as system includes to suppress warnings
CPPFLAGS += -isystem $(SOURCE_PATH)/external_libs/cnl/include
else
# arm compiler automatically includes system headers as external c, use normal include
CPPFLAGS += -I $(SOURCE_PATH)/external_libs/cnl/include
endif

# add all cbox source files
INCLUDE_DIRS += $(SOURCE_PATH)/lib/cbox/src/
CPPSRC += $(call here_files,lib/cbox/src/cbox,*.cpp)
# don't include file based persistance on spark platform
# arm-gcc doesn't support dirent
CPPEXCLUDES += lib/cbox/src/cbox/FileObjectStorage.cpp

# add blocks files
INCLUDE_DIRS += $(SOURCE_PATH)/lib/blocks
CPPSRC += $(call here_files,lib/blocks,*.cpp)
CPPSRC += $(call here_files,lib/blocks/blocks,*.cpp)

# add auto-generated protobuf includes
INCLUDE_DIRS += $(SOURCE_PATH)/lib/compiled_proto
CSRC += $(call here_files,lib/compiled_proto/proto,*.c)


ifeq ($(PLATFORM_ID),6)
MODULAR?=y
endif
ifeq ($(PLATFORM_ID),8)
MODULAR?=y
endif
ifeq ($(PLATFORM_ID),10)
MODULAR?=y
endif

# add nanopb dependencies
include $(SOURCE_PATH)/external_libs/device-os/third_party/nanopb/import.mk
ifeq ($(MODULAR),y)
# include sources that are part of nanopb, but not included in shared libraries of particle
CSRC += app/brewblox-particle/nanopb_not_in_particle_dynalib.c
endif

# define platform parameters to avoid -Wundef warnings
CFLAGS += -DLITTLE_ENDIAN=1234
CFLAGS += -DBYTE_ORDER=LITTLE_ENDIAN

# App
INCLUDE_DIRS += $(SOURCE_PATH)/app/brewblox
INCLUDE_DIRS += $(SOURCE_PATH)/app/brewblox-particle

CPPSRC += $(call here_files,app/brewblox-particle,*.cpp)
CPPSRC += $(call here_files,app/brewblox-particle/blocks,*.cpp)

#wiring
CSRC += $(call here_files,platform/wiring/,*.c)
CPPSRC += $(call here_files,platform/wiring/,*.cpp)

INCLUDE_DIRS += $(SOURCE_PATH)/platform

CSRC += $(call here_files,platform/spark/modules/Board,*.c)
CPPSRC += $(call here_files,platform/spark/modules/Board,*.cpp)

# buzzer
INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/Buzzer
CPPSRC += $(call here_files,platform/spark/modules/Buzzer,*.cpp)

# add board files (tests use emulated hardware)
INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/Board
CPPSRC += $(call here_files,platform/spark/modules/Board,*.cpp)

# add display dependencies
INCLUDE_DIRS += $(SOURCE_PATH)/app/brewblox-particle/display
CPPSRC += $(call target_files,app/brewblox-particle/display,*.cpp)
CSRC += $(call target_files,app/brewblox-particle/display,*.c)

INCLUDE_DIRS +=  $(SOURCE_PATH)/platform/spark/modules/eGUI/D4D
CSRC +=  $(call target_files,platform/spark/modules/eGUI/D4D,*.c)
CPPSRC +=  $(call target_files,platform/spark/modules/eGUI/D4D,*.cpp)
INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/BrewPiTouch
CPPSRC +=  $(call here_files,platform/spark/modules/BrewPiTouch,*.cpp)
INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/SPIArbiter
CPPSRC +=  $(call here_files,platform/spark/modules/SPIArbiter,*.cpp)

INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/WebSockets/firmware
CPPSRC +=  $(call here_files,platform/spark/modules/WebSockets/firmware,*.cpp)
CSRC += $(call here_files,platform/spark/modules/WebSockets/firmware/libb64,*.c)
CSRC += $(call here_files,platform/spark/modules/WebSockets/firmware/libsha1,*.c)

# mdns
INCLUDE_DIRS += $(SOURCE_PATH)/platform/spark/modules/mdns/src
CPPSRC += $(call here_files,platform/spark/modules/mdns/src,*.cpp)

# include boost
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

# Warn when virtual functions are overriden without override/override final specifier (requires gcc 5.1)
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
