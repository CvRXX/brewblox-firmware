#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

if [ "${1:-}" = "html" ]
then
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
  "$PWD/controlbox/build/" \
  "$PWD/lib/test/build/" \
  "$PWD/app/brewblox-particle/test/build/" \
  -e '.*/boost/.*' \
  -e '^/usr/.*' \
  -e "$PWD/platform/spark/device-os/.*" \
  -e "$PWD/brewblox/blox/proto/.*" \
  -e "$PWD/lib/cnl/.*" \
  -e "$PWD/controlbox/test/.*" \
  -e "$PWD/lib/test/" \
  -e "$PWD/app/brewblox-particle/test/" \
  --$FORMAT \
  --output "$OUTPUT" \
  $FORMAT_ARGS \
  --delete \
  --print-summary
