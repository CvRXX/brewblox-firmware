#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

# BUILD_DIR="build/target/user/platform-3/firmware/brewblox"
EXECUTABLE_DIR="build/target/brewblox-gcc"
EXECUTABLE="$EXECUTABLE_DIR/brewblox"
OUTPUT_DIR="build/coverage"
DEVICE_KEY="$EXECUTABLE_DIR/device_key.der"
SERVER_KEY="$EXECUTABLE_DIR/server_key.der"
STATE_DIR="$EXECUTABLE_DIR/state"
EEPROM_FILE="$EXECUTABLE_DIR/eeprom.bin"

ls "$EXECUTABLE"
if [ ! -f "$EXECUTABLE" ]; then
    echo "brewblox executable not found!"
    exit 1
fi

pushd "$EXECUTABLE_DIR"

touch "$DEVICE_KEY" "$SERVER_KEY" "$EEPROM_FILE"
mkdir -p "$STATE_DIR"
mkdir -p "$OUTPUT_DIR"

valgrind --suppressions=/usr --tool=callgrind --callgrind-out-file="$EXECUTABLE_DIR/callgrind.out" "$EXECUTABLE" --device_id 123456789012345678901234 --device_key="$DEVICE_KEY" --server_key="$SERVER_KEY"

popd

# open result.kcg with kcachegrind
kcachegrind "$EXECUTABLE_DIR/callgrind.out" &
