#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd controlbox

echo "Building Controlbox unit tests"
subtask make -j $MAKE_ARGS -s runner

echo "Running Controlbox unit tests"
subtask build/cbox_test_runner --durations yes

exit $SUBTASK_STATUS
