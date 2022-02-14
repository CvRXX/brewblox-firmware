#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd test/cbox

echo "Building cbox unit tests"
subtask make $MAKE_ARGS -s

echo "Running cbox unit tests"
subtask build/runner --durations yes

exit $SUBTASK_STATUS
