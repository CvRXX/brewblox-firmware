#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd test/brewblox-particle

echo "Building brewblox-particle tests"
subtask make $MAKE_ARGS -s

echo "Running brewblox-particle tests"
subtask build/test_runner --durations yes

exit $SUBTASK_STATUS
