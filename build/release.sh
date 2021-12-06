#! /usr/bin/env bash
set -euo pipefail
pushd "$(dirname "$0")/.." > /dev/null # Run from repo root

# This script does not build various binary and executable files.
# They are assumed to be present in {root}/release already.

if [[ -z "${TAG:-}" ]]
then
    echo "ERROR: TAG variable was not set."
    exit 1
fi

# Azure SAS token must have been set to upload to Azure
if [[ -z "${AZURE_STORAGE_SAS_TOKEN:-}" ]]
then
    echo "ERROR: AZURE_STORAGE_SAS_TOKEN variable was not set."
    echo "You can generate a SAS token at https://portal.azure.com -> brewblox -> containers -> firmware -> Shared access tokens"
    exit 1
fi

# Determine ini variables
git submodule sync
git submodule update --init --depth 1 brewblox/blox/proto
git submodule update --init --depth 1 platform/spark/device-os

firmware_version=$(git rev-parse --short=8 HEAD)
firmware_date=$(git log -1 --format=%cd --date=short)
firmware_sha="$(git rev-parse HEAD)"
firmware_name="${firmware_date}-${firmware_version}"
firmware_tarball="${firmware_name}-all.tar.gz"

proto_version=$(git --git-dir ./brewblox/blox/proto/.git rev-parse --short=8 HEAD)
proto_date=$(git --git-dir ./brewblox/blox/proto/.git log -1 --format=%cd --date=short)

particle_tag=$(git --git-dir "./platform/spark/device-os/.git" fetch --tags --no-recurse-submodules && git --git-dir "./platform/spark/device-os/.git" describe --tags)
particle_releases=https://github.com/particle-iot/device-os/releases/download/${particle_tag}
particle_version=${particle_tag:1} # remove the 'v' prefix

curl -fL -o ./release/bootloader-p1.bin "${particle_releases}/p1-bootloader@${particle_version}+lto.bin"
curl -fL -o ./release/system-part1-p1.bin "${particle_releases}/p1-system-part1@${particle_version}.bin"
curl -fL -o ./release/system-part2-p1.bin "${particle_releases}/p1-system-part2@${particle_version}.bin"

curl -fL -o ./release/bootloader-photon.bin "${particle_releases}/photon-bootloader@${particle_version}+lto.bin"
curl -fL -o ./release/system-part1-photon.bin "${particle_releases}/photon-system-part1@${particle_version}.bin"
curl -fL -o ./release/system-part2-photon.bin "${particle_releases}/photon-system-part2@${particle_version}.bin"

# Write to firmware.ini
{
    echo "[FIRMWARE]"
    echo "firmware_version=${firmware_version}"
    echo "firmware_date=${firmware_date}"
    echo "firmware_sha=${firmware_sha}"
    echo "proto_version=${proto_version}"
    echo "proto_date=${proto_date}"
    echo "system_version=${particle_version}"
} | tee "./release/firmware.ini"

# Create tarball archive
echo "Creating archive /tmp/${firmware_tarball}"
pushd ./release
tar -czf "/tmp/${firmware_tarball}" ./*
popd

# Upload files
# - This requires Azure CLI to be installed
# - This requires the environment variable AZURE_STORAGE_SAS_TOKEN to be set
echo "Publishing ${firmware_tarball} to Azure, tag=${TAG}"

az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/firmware.ini" \
    --file ./release/firmware.ini

az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/brewblox-esp32.bin" \
    --file ./release/brewblox-esp32.bin

az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "${firmware_name}/brewblox-release.tar.gz" \
    --file "/tmp/${firmware_tarball}"

# Also upload a ini file named with $TAG
az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "${TAG}/firmware.ini" \
    --file ./release/firmware.ini
