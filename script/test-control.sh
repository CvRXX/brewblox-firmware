#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd test/control

echo "Building control unit tests"
subtask make $MAKE_ARGS -s

echo "Running control unit tests"
subtask build/runner --durations yes

exit $SUBTASK_STATUS
