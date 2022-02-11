#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

make -C test/brewblox-particle clean
make -C test/cbox clean
make -C test/control clean

make -C build clean PLATFORM=gcc
make -C build clean PLATFORM=p1
make -C build clean PLATFORM=photon

bash build/idf.sh fullclean

echo "Removing build/target"
rm -rf build/target
