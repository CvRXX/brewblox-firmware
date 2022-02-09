#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

# Build device-os modules
pushd platform/spark/device-os/modules > /dev/null

echo "Building system modules for P1 with SWD"
make clean -s all PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y

echo "Flashing system modules with SWD"
make -s program-dfu PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y

popd > /dev/null

# Build firmware
pushd build

echo "Building brewblox app for P1 with SWD"
make clean -s all PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y APP=brewblox

echo "Flashing brewblox app with SWD"
make -s program-dfu PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y APP=brewblox

popd > /dev/null
