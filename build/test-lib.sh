#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd lib/test

echo "Building lib unit tests"
subtask make -j $MAKE_ARGS -s runner

echo "Running lib unit tests"
subtask build/lib_test_runner --durations yes

exit $SUBTASK_STATUS
