#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd lib/test

echo "Building BrewBlox app unit tests"
subtask make -j $MAKE_ARGS -s runner
subtask build/lib_test_runner

exit $SUBTASK_STATUS
