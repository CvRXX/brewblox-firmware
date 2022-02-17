#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

SUITE="${1:?}"
shift

if [ -x "$(command -v bear)" ]; then
    CMD="bear --append make -s ${MAKE_ARGS}"
else
    CMD="make -s ${MAKE_ARGS}"
fi

echo "Building ${SUITE} unit tests"
subtask $CMD -C "test/${SUITE}"

echo "Running ${SUITE} unit tests"
subtask "test/${SUITE}/build/runner" --durations yes

exit $SUBTASK_STATUS
