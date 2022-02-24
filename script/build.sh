#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"
SUBTASK_SILENT=y

PLATFORM="${1:-}"

if [[ ! "${PLATFORM}" =~ ^(esp|photon|p1|gcc|sim)$ ]]; then
    echo "Unknown platform argument: '${PLATFORM}'"
    echo "Options: 'esp', 'photon', 'p1', 'gcc', 'sim'"
    exit 1
fi

shift

if [[ "${PLATFORM}" == esp ]]; then
    if [ "$#" -eq 0 ]; then
        CMD="idf.py build"
    else
        CMD="idf.py"
    fi

    set +u # export.sh can use undefined variables
    source /opt/esp/idf/export.sh
    cd app/brewblox-esp
    subtask $CMD "$@"

elif [[ "${PLATFORM}" =~ ^(photon|p1|gcc)$ ]]; then
    if [ -x "$(command -v bear)" ]; then
        CMD="bear --append -o build/compile_commands_${PLATFORM}.json make -s ${MAKE_ARGS}"
    else
        CMD="make -s ${MAKE_ARGS}"
    fi

    subtask $CMD \
        -C external_libs/device-os/main \
        APPNAME=brewblox \
        PLATFORM="${PLATFORM}" \
        APPDIR="$(pwd)" \
        USER_MAKEFILE=app/brewblox-particle/build.mk \
        USE_PRINTF_FLOAT=n \
        WARNINGS_AS_ERRORS=n \
        PARTICLE_DEVELOP=y \
        TARGET_FILE="brewblox-${PLATFORM}" \
        TARGET_DIR="$(pwd)/build/target/brewblox-${PLATFORM}" \
        BUILD_PATH_BASE="$(pwd)/build/target" \
        "$@"

elif [[ "${PLATFORM}" == sim ]]; then
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

    # Now build GCC with the custom settings
    subtask script/build.sh gcc

    # reset modified file
    git -C external_libs/device-os checkout -- build/gcc-tools.mk
fi

exit $SUBTASK_STATUS
