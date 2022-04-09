#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

FW_DATE="${1:-}"    # Example: 2022-03-28
FW_VERSION="${2:-}" # Example: b3c5a50f
DUMP_INPUT="${3:-}" # Local file, or termbin URL

mkdir -p ./dump
rm -rf ./dump/*
pushd ./dump >/dev/null

echo "Collecting coredump file..."
if [[ "${DUMP_INPUT}" =~ ^http.+ ]]; then
    curl -sSL -o ./coredump.b64 "${DUMP_INPUT}"
else
    cp "${DUMP_INPUT}" ./coredump.b64
fi

echo "Downloading .elf file..."
curl -sSLO \
    "https://brewblox.blob.core.windows.net/firmware/${FW_DATE}-${FW_VERSION}/brewblox-release.tar.gz"
tar -xzf brewblox-release.tar.gz ./brewblox-esp32.elf

echo "Parsing coredump file..."
set +u # export.sh can use undefined variables
source /opt/esp/idf/export.sh >/dev/null
espcoredump.py info_corefile -c ./coredump.b64 --core-format=b64 ./brewblox-esp32.elf >./coredump.txt

echo "$PWD/coredump.txt"
