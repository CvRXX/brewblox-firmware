#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd app/brewblox-particle/test

echo "Building Brewblox app unit tests"
subtask make -j $MAKE_ARGS -s runner

echo "Running Brewblox app unit tests"
subtask build/brewblox_test_runner --durations yes

exit $SUBTASK_STATUS
