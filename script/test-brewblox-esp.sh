#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd test/brewblox-esp

echo "Building brewblox-esp tests"
subtask make $MAKE_ARGS -s

echo "Running brewblox-esp tests"
subtask build/runner --durations yes

exit $SUBTASK_STATUS
