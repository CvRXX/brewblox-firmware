#! /usr/bin/env bash
set -e
MY_DIR=$(dirname "$0")

# shellcheck disable=2086,2068
bear make $MAKE_ARGS $@ || exit 1

rm -f "$MY_DIR/compile_commands.json"
pushd "$MY_DIR" > /dev/null
shopt -s globstar
jq -s '[.[][]]' ./**/compile_commands.json > compile_commands.json
chmod 777 compile_commands.json
find . -name "*.gcda" -type f -delete # remove old profile results
popd > /dev/null
rm -f "compile_commands.json"
