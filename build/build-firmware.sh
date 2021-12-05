#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd build

subtask make $MAKE_ARGS -s all APP=brewblox PLATFORM=gcc
subtask make $MAKE_ARGS -s all APP=brewblox PLATFORM=P1
subtask make $MAKE_ARGS -s all APP=brewblox PLATFORM=photon

exit $SUBTASK_STATUS
