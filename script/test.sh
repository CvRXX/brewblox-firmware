#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

SUITE="${1:?}"
shift

cd "test/${SUITE}"

echo "Building ${SUITE} unit tests"
subtask make $MAKE_ARGS -s

echo "Running ${SUITE} unit tests"
subtask build/runner --durations yes

exit $SUBTASK_STATUS
