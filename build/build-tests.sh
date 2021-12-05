#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

echo "Building lib unit tests"
subtask make -C lib/test -j $MAKE_ARGS -s runner

echo "Building Brewblox app unit tests"
subtask make -C app/brewblox-particle/test -j $MAKE_ARGS -s runner

echo "Building controlbox unit tests"
subtask make -C controlbox -j $MAKE_ARGS -s runner

exit $SUBTASK_STATUS
