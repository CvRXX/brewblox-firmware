#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

# Build device-os modules
pushd external_libs/device-os/modules >/dev/null

echo "Building system modules for P1 with SWD"
make -s PLATFORM=p1 USE_SWD=y $MAKE_ARGS clean all

echo "Flashing system modules with SWD"
make -s PLATFORM=p1 USE_SWD=y $MAKE_ARGS program-dfu

popd >/dev/null

# Build firmware
pushd build

echo "Building brewblox app for P1 with SWD"
make -s PLATFORM=p1 USE_SWD=y $MAKE_ARGS clean all

echo "Flashing brewblox app with SWD"
make -s PLATFORM=p1 USE_SWD=y $MAKE_ARGS program-dfu

popd >/dev/null
