#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd controlbox

echo "Building Brewblox Controlbox unit tests"
subtask make -j $MAKE_ARGS -s runner
subtask build/cbox_test_runner

exit $SUBTASK_STATUS
