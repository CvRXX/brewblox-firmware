#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd test/cbox

echo "Building cbox unit tests"
subtask make $MAKE_ARGS -s runner

echo "Running cbox unit tests"
subtask build/test_runner --durations yes

exit $SUBTASK_STATUS
