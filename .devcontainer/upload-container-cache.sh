#!/usr/bin/env bash
set -euo pipefail
pushd "$(git rev-parse --show-toplevel)" >/dev/null

docker buildx build \
    --tag brewblox/firmware-devcontainer:focal \
    --build-arg USERNAME=vscode \
    --push \
    .devcontainer
