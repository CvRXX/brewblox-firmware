#! /usr/bin/env bash
set -e
pushd "$(dirname "$0")" > /dev/null

# The compiler image is expected to remain relatively stable
# It does not contain any firmware code - just the software required to compile the firmware

# Multi-platform support is handled by simulator-compiler
# We only need the default amd64

if [ -z "$TAG" ]; then echo "Error: TAG is not set"; exit 1; else echo "building brewblox/firmware-compiler:$TAG"; fi

# don't forget to call with --push
docker buildx build \
    --pull \
    --tag brewblox/firmware-compiler:"$TAG" \
    "$@" \
    .
