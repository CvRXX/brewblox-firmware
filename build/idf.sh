#! /usr/bin/env bash
set -ex

# Use repository root
pushd "$(dirname "$0")/.." > /dev/null

docker run \
    -it --rm --privileged \
    -v "$PWD":"$PWD" \
    -w "$PWD"/app/brewblox-esp \
    espressif/idf:v4.3.1 \
    idf.py "$@"