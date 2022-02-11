#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

make -C test/brewblox-particle clean
make -C test/cbox clean
make -C test/control clean

make -C build clean PLATFORM=gcc
make -C build clean PLATFORM=p1
make -C build clean PLATFORM=photon

bash script/idf.sh fullclean

echo "Removing build/ target directories"
rm -rf build/target
rm -rf build/coverage
