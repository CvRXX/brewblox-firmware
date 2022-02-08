#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

make -C app/brewblox-particle/test clean
make -C lib/test clean
make -C controlbox clean

make -C build clean PLATFORM=gcc
make -C build clean PLATFORM=p1
make -C build clean PLATFORM=photon
