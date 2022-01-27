#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

BUILD_DIR="build/target/user/platform-3/firmware/brewblox"
EXECUTABLE_DIR="build/target/brewblox-gcc"
EXECUTABLE="$EXECUTABLE_DIR/brewblox-gcc"
OUTPUT_DIR="build/coverage"
DEVICE_KEY="$EXECUTABLE_DIR/device_key.der"
SERVER_KEY="$EXECUTABLE_DIR/server_key.der"
# EEPROM_FILE="$EXECUTABLE_DIR/eeprom.bin"
STATE_DIR="$EXECUTABLE_DIR/state"

ls "$EXECUTABLE"
if [ ! -f "$EXECUTABLE" ]; then
    echo "brewblox executable not found!"
    exit 1
fi

touch "$DEVICE_KEY" "$SERVER_KEY" # "$EEPROM_FILE"
mkdir -p "$STATE_DIR"
mkdir -p "$OUTPUT_DIR"

"$EXECUTABLE" --device_id 123456789012345678901234 --device_key="$DEVICE_KEY" --server_key="$SERVER_KEY" --state="$STATE_DIR"
exit 0

echo "resetting lcov counters"
lcov --zerocounters --directory "$BUILD_DIR"

echo "running lcov initial"
lcov --capture --initial --directory "$BUILD_DIR" --output-file "$OUTPUT_DIR/base.info"
"$EXECUTABLE" --device_id 123456789012345678901234 --device_key="$DEVICE_KEY" --server_key="$SERVER_KEY" --state="$STATE_DIR"

echo "running lcov"
lcov --capture --directory "$BUILD_DIR" --output-file "$OUTPUT_DIR/test.info"

echo "combining tracefiles"
lcov --add-tracefile "$OUTPUT_DIR/base.info" --add-tracefile "$OUTPUT_DIR/test.info" --output-file "$OUTPUT_DIR/total.info"

echo "filtering tracefiles"
lcov --remove "$OUTPUT_DIR/total.info" '/boost/*' '/usr/*' '*/build/target/user/platform-3/firmware/brewblox/**' -o "$OUTPUT_DIR/filtered.info"

echo "generating html"
mkdir -p "$OUTPUT_DIR/html"
genhtml --prefix /firmware/ "$OUTPUT_DIR/filtered.info" --ignore-errors source --output-directory="$OUTPUT_DIR/html"
