#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd build
make PLATFORM=p1 all program-dfu
