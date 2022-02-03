#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

echo "Running lib unit tests"
pushd lib/test/build/
subtask ./lib_test_runner --durations yes
popd

echo "Running Controlbox unit tests"
pushd controlbox/build/
subtask ./cbox_test_runner --durations yes
popd

echo "Running Brewblox unit tests"
pushd app/brewblox-particle/test/build/
subtask ./brewblox_test_runner --durations yes
popd

exit $SUBTASK_STATUS
