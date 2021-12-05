#! /usr/bin/env bash
set -euo pipefail
pushd "$(dirname "$0")/.." > /dev/null # Run from repo root

# This script does not build various binary and executable files.
# They are assumed to be present in {root}/release already.
# Particle binaries are downloaded into {root}/release.

# Azure SAS token must have been set to upload to Azure
if [[ -z "${AZURE_STORAGE_SAS_TOKEN:-}" ]]
then
    echo "ERROR: AZURE_STORAGE_SAS_TOKEN variable was not set."
    echo "You can generate a SAS token at https://portal.azure.com -> brewblox -> containers -> firmware -> Shared access tokens"
    exit 1
fi

# A duplicate firmware.ini is uploaded to a tag.
# This lets clients get firmware version/date associated with a tag.
TAG="${1:?}"
shift

# Fetch git index for submodules
git submodule sync --quiet
git submodule update --init --depth 1 brewblox/blox/proto
git submodule update --init --depth 1 platform/spark/device-os
git --git-dir platform/spark/device-os/.git fetch --quiet --tags --no-recurse-submodules

# Get firmware metadata
firmware_version=$(git rev-parse --short=8 HEAD)
firmware_date=$(git log -1 --format=%cd --date=short)
firmware_sha="$(git rev-parse HEAD)"
firmware_name="${firmware_date}-${firmware_version}"

# Get proto metadata
proto_version=$(git --git-dir brewblox/blox/proto/.git rev-parse --short=8 HEAD)
proto_date=$(git --git-dir brewblox/blox/proto/.git log -1 --format=%cd --date=short)

# Get particle metadata
particle_tag=$(git --git-dir platform/spark/device-os/.git describe --tags --abbrev=0 --match v*)
particle_releases=https://github.com/particle-iot/device-os/releases/download/${particle_tag}
particle_version=${particle_tag:1} # remove the 'v' prefix

# Download particle binaries for P1
curl -sSfL -o ./release/bootloader-p1.bin "${particle_releases}/p1-bootloader@${particle_version}+lto.bin"
curl -sSfL -o ./release/system-part1-p1.bin "${particle_releases}/p1-system-part1@${particle_version}.bin"
curl -sSfL -o ./release/system-part2-p1.bin "${particle_releases}/p1-system-part2@${particle_version}.bin"

# Download particle binaries for Photon
curl -sSfL -o ./release/bootloader-photon.bin "${particle_releases}/photon-bootloader@${particle_version}+lto.bin"
curl -sSfL -o ./release/system-part1-photon.bin "${particle_releases}/photon-system-part1@${particle_version}.bin"
curl -sSfL -o ./release/system-part2-photon.bin "${particle_releases}/photon-system-part2@${particle_version}.bin"

# Write to firmware.ini
{
    echo "[FIRMWARE]"
    echo "firmware_version=${firmware_version}"
    echo "firmware_date=${firmware_date}"
    echo "firmware_sha=${firmware_sha}"
    echo "proto_version=${proto_version}"
    echo "proto_date=${proto_date}"
    echo "system_version=${particle_version}"
} > "./release/firmware.ini"

# Create tarball archive
pushd ./release > /dev/null
tar -czf /tmp/brewblox-release.tar.gz ./*
popd > /dev/null

# Diagnostics
echo "============env============="
echo "TAG=$TAG"
echo "========firmware.ini========"
cat ./release/firmware.ini
echo "==========release/=========="
ls -Ahl ./release

# Upload files
# - This requires Azure CLI to be installed
# - This requires the environment variable AZURE_STORAGE_SAS_TOKEN to be set

az storage blob upload \
    --output none \
    --no-progress \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/firmware.ini" \
    --file ./release/firmware.ini

az storage blob upload \
    --output none \
    --no-progress \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/brewblox-esp32.bin" \
    --file ./release/brewblox-esp32.bin

az storage blob upload \
    --output none \
    --no-progress \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/brewblox-release.tar.gz" \
    --file /tmp/brewblox-release.tar.gz

# Upload the $TAG reference firmware.ini
az storage blob upload \
    --output none \
    --no-progress \
    --account-name brewblox \
    --container-name firmware \
    --name "${TAG}/firmware.ini" \
    --file ./release/firmware.ini
