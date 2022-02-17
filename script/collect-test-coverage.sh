#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

if [ "${1:-}" = "html" ]; then
    FORMAT="html-details"
    FORMAT_ARGS='--html-title coverage'
    OUTPUT="build/coverage/index.html"
else
    FORMAT="xml"
    FORMAT_ARGS=
    OUTPUT="build/coverage/coverage.xml"
fi

mkdir -p build/coverage/html
gcovr --root "$PWD" \
    "$PWD/test/blocks/build/" \
    "$PWD/test/cbox/build/" \
    "$PWD/test/control/build/" \
    -e '.*/boost/.*' \
    -e '^/usr/.*' \
    -e "$PWD/external_libs/device-os/.*" \
    -e "$PWD/external_libs/cnl/.*" \
    -e "$PWD/lib/proto/inc/proto/.*" \
    -e "$PWD/test/blocks/" \
    -e "$PWD/test/cbox/" \
    -e "$PWD/test/control/" \
    --$FORMAT \
    --output "$OUTPUT" \
    $FORMAT_ARGS \
    --delete \
    --print-summary
