#!/bin/bash
set -euo pipefail
pushd "$(git rev-parse --show-toplevel)" > /dev/null # always init at repo root

SUBTASK_STATUS=0
MAKE_ARGS=${MAKE_ARGS:-}

# Run command, and echo its result state
# If it fails, do not raise an error, but update SUBTASK_STATUS
function subtask() {
    local_status=0
    "$@" || local_status=$?

    if [ $local_status = 0 ]
    then
        echo "✓ SUCCESS"
    else 
        echo "✗ FAILED"
    fi

    if [ $SUBTASK_STATUS = 0 ]
    then
        SUBTASK_STATUS=$local_status
    fi
}
