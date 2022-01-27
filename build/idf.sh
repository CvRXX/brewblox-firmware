#! /usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

docker run \
    -it --rm --privileged \
    -v "$PWD":"$PWD" \
    -w "$PWD"/app/brewblox-esp \
    espressif/idf:release-v4.4 \
    idf.py "$@"
