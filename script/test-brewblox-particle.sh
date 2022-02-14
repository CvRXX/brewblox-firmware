#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd test/brewblox-particle

echo "Building brewblox-particle tests"
subtask make $MAKE_ARGS -s

echo "Running brewblox-particle tests"
subtask build/runner --durations yes

exit $SUBTASK_STATUS
