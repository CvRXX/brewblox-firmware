#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

make -C app/brewblox-particle/test clean
make -C lib/test clean
make -C controlbox clean

make -C build clean PLATFORM=gcc
make -C build clean PLATFORM=p1
make -C build clean PLATFORM=photon

bash build/idf.sh fullclean

echo "Removing build/target"
rm -rf build/target

# Somehow this file gets generated during device-os clean
rm -f build/clean
