#! /usr/bin/env bash
set -euo pipefail
pushd "$(dirname "$0")" > /dev/null

# The compiler image is expected to remain relatively stable
# It does not contain any firmware code - just the software required to compile the firmware

TAG="${1:?}"
shift

bash ../prepare-buildx.sh

# don't forget to call with --push
docker buildx build \
    --pull \
    --tag brewblox/simulator-compiler:"$TAG" \
    --platform linux/amd64,linux/arm/v7,linux/arm64/v8 \
    "$@" \
    .
