#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

BRANCH="${1:-develop}"

echo "Using branch $BRANCH..."

pushd external_libs/brewblox-proto >/dev/null
git fetch
git checkout "$BRANCH"
git pull
popd >/dev/null

subtask script/compile-proto.sh

exit $SUBTASK_STATUS
