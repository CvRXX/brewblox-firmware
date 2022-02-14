#! /usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

if [[ $(arch) != 'x86_64' ]]; then
    # -m64 is not supported for ARM
    sed -i 's/-m64//g' external_libs/device-os/build/gcc-tools.mk
fi

# remove debug info and optimize for size
sed -i 's/-g3//g' external_libs/device-os/build/gcc-tools.mk
sed -i 's/-gdwarf-2//g' external_libs/device-os/build/gcc-tools.mk
# We want to match the shell expression, not expand it before matching
# shellcheck disable=SC2016
sed -i 's/-O$(GCC_OPTIMIZE)/-Os/g' external_libs/device-os/build/gcc-tools.mk

subtask make -C build PLATFORM=gcc $MAKE_ARGS

# reset modified file
git -C external_libs/device-os checkout -- build/gcc-tools.mk

exit $SUBTASK_STATUS
