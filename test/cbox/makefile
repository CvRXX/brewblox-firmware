## -*- Makefile -*-


CCC = gcc
CXX = g++
LD = g++
CCFLAGS = $(CFLAGS)
CXXFLAGS = $(CFLAGS)
RM = rm -f
RMDIR = rm -f -r
MKDIR = mkdir -p

TARGETDIR=build/
TARGET=test_runner

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
remove_slash = $(patsubst %/,%,$1)
SOURCE_PATH = $(call remove_slash,$(abspath $(mkfile_dir)))
ROOT_PATH = $(abspath mkfile_dir/../../..)

include $(ROOT_PATH)/test/checkers.mk # sanitizer and gcov

BUILD_PATH=$(TARGETDIR)

# Recursive wildcard function
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# enumerates files in the filesystem and returns their path relative to the project root
# $1 the directory relative to the project root
# $2 the pattern to match, e.g. *.cpp
target_files = $(patsubst $(ROOT_PATH)/%,%,$(call rwildcard,$(ROOT_PATH)/$1,$2))

# here_files is a non-recursive file search. target_files is recursive.
here_files = $(patsubst $(ROOT_PATH)/%,%,$(wildcard $(ROOT_PATH)/$1/$2))

# catch test
INCLUDE_DIRS += $(ROOT_PATH)/external_libs/device-os/third_party/catch2/catch2/single_include/catch2

# add all tests
CPPSRC += $(call here_files,test/cbox,*.cpp)

# and sources
INCLUDE_DIRS += $(ROOT_PATH)/lib/cbox/src/
CPPSRC += $(call here_files,lib/cbox/src/cbox,*.cpp)

# include dir
CFLAGS += -I$(ROOT_PATH)/lib/cbox/src/cbox

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

CFLAGS += $(patsubst %,-I%,$(INCLUDE_DIRS)) -I.

CSRC := $(filter-out $(CEXCLUDES),$(CSRC))
CPPSRC := $(filter-out $(CPPEXCLUDES),$(CPPSRC))

# Collect all object and dep files
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(CSRC:.c=.o))
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(CPPSRC:.cpp=.o))
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(CCSRC:.pb.cc=.pb.o))

ALLDEPS += $(addprefix $(BUILD_PATH)/, $(CSRC:.c=.o.d))
ALLDEPS += $(addprefix $(BUILD_PATH)/, $(CPPSRC:.cpp=.o.d))
ALLDEPS += $(addprefix $(BUILD_PATH)/, $(CCSRC:.pb.cc=.pb.o.d))

all: runner

runner: $(TARGETDIR)/$(TARGET)

$(TARGETDIR)/$(TARGET) : $(BUILD_PATH) $(ALLOBJ)
	@echo Building target: $@
	@$(MKDIR) $(dir $@)
	@$(LD) $(CFLAGS) $(ALLOBJ) --output $@ $(LDFLAGS)
	@echo

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

# Tool invocations

# C compiler to build .o from .c in $(BUILD_DIR)
$(BUILD_PATH)%.o : $(ROOT_PATH)%.c
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CCC) $(CCFLAGS) -s -c -o $@ $<

# CPP compiler to build .o from .cpp in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_PATH)%.o : $(ROOT_PATH)%.cpp
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -s -c -o $@ $<

# CPP compiler to build .pb.o from .pb.cc in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_PATH)%.pb.o : $(ROOT_PATH)%.pb.cc
	@echo Building file: $<
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -s -c -o $@ $<

# Other Targets
clean:
	$(RM) $(ALLOBJ) $(ALLDEPS) $(TARGETDIR)/$(TARGET)
	$(RMDIR) $(TARGETDIR)
	@echo

# print variable by invoking make print-VARIABLE as VARIABLE = the_value_of_the_variable
print-%  : ; @echo $* = $($*)

.PHONY: all clean runner
.SECONDARY:

# Include auto generated dependency files
-include $(ALLDEPS)
