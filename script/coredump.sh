#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

FW_IDENTIFIER="${1:-}" # Examples: '2022-03-28-b3c5a50f', 'edge', 'feature-experimental'
DUMP_INPUT="${2:-}"    # Local file, or termbin URL

mkdir -p ./dump
rm -rf ./dump/*
pushd ./dump >/dev/null

echo "Collecting coredump file..."
if [[ "${DUMP_INPUT}" =~ ^http.+ ]]; then
    curl -sSL -o ./coredump.b64 "${DUMP_INPUT}"
else
    cp "${DUMP_INPUT}" ./coredump.b64
fi

if [[ "${FW_IDENTIFIER}" =~ ^\d{4}-\d{2}-\d{2}-\w{8}$ ]]; then
    echo "Using CLI firmware identifier..."
    FW_DATE=${FW_IDENTIFIER:0:10}
    FW_VERSION=${FW_IDENTIFIER:11:8}
else
    echo "Downloading firmware.ini file..."
    curl -sSLO \
        "https://brewblox.blob.core.windows.net/firmware/${FW_IDENTIFIER}/firmware.ini"
    FW_DATE=$(awk -F "=" '/firmware_date/ {print $2}' firmware.ini)
    FW_VERSION=$(awk -F "=" '/firmware_version/ {print $2}' firmware.ini)
fi

echo "[Firmware date = ${FW_DATE}]"
echo "[Firmware version = ${FW_VERSION}]"

echo "Downloading .elf file..."
curl -sSLO \
    "https://brewblox.blob.core.windows.net/firmware/${FW_DATE}-${FW_VERSION}/brewblox-release.tar.gz"
tar -xzf brewblox-release.tar.gz ./brewblox-esp32.elf

echo "Parsing coredump file..."
set +u # export.sh can use undefined variables
source /opt/esp/idf/export.sh >/dev/null
espcoredump.py info_corefile -c ./coredump.b64 --core-format=b64 ./brewblox-esp32.elf >./coredump.txt

echo "$PWD/coredump.txt"
