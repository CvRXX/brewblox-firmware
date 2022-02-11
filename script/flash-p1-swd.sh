#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

# Build device-os modules
pushd platform/spark/device-os/modules >/dev/null

echo "Building system modules for P1 with SWD"
make -s clean all PLATFORM=p1 USE_SWD=y

echo "Flashing system modules with SWD"
make -s program-dfu PLATFORM=p1 USE_SWD=y

popd >/dev/null

# Build firmware
pushd build

echo "Building brewblox app for P1 with SWD"
make -s clean all PLATFORM=p1 USE_SWD=y

echo "Flashing brewblox app with SWD"
make -s program-dfu PLATFORM=p1 USE_SWD=y

popd >/dev/null
