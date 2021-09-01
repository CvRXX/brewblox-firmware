#!/usr/bin/env bash
set -euo pipefail

# Args
VERSION=${1:-""}
TAG=${2:-"develop"}

# Push repo root
pushd "$(dirname "$0")/.." > /dev/null

# Check for required tools
if ! command -v gh &> /dev/null
then
    echo "ERROR: Github CLI could not be found. To install: https://cli.github.com/manual/installation"
    exit 1
fi
if ! command -v az &> /dev/null
then
    echo "ERROR: Azure CLI could not be found. To install: https://docs.microsoft.com/en-us/cli/azure/install-azure-cli-linux?pivots=apt"
    exit 1
fi

# Version must match 'vMAJOR.MINOR.PATCH', with an optional postfix
if [[ ! "${VERSION}" =~ ^v[0-9]+\.[0-9]+\.[0-9]+(\-.+)?$ ]]
then
    echo "ERROR: Missing or invalid version argument."
    echo "ERROR: Version '${VERSION}' must be formatted as 'vMAJOR.MINOR.PATCH'"
    exit 1
fi

# Azure SAS token must have been set to upload to Azure
if [[ -z "${AZURE_STORAGE_SAS_TOKEN}" ]]
then
    echo "ERROR: AZURE_STORAGE_SAS_TOKEN was not set."
    exit 1
fi

echo "Publishing brewblox/firmware-bin:${TAG} as ${VERSION}"

# Pull image
docker rm bin-box 2> /dev/null || true
docker pull brewblox/firmware-bin:"${TAG}" > /dev/null
docker create --name bin-box brewblox/firmware-bin:"${TAG}" > /dev/null

# Copy files
rm -rf ./release
docker cp bin-box:/firmware ./release

# Remove image
docker rm bin-box > /dev/null

# Add release version info to firmware.ini
echo "firmware_release=${VERSION}" >> ./release/firmware.ini

# Get release SHA from firmware.ini
firmware_sha=$(awk -F "=" '/firmware_sha/ {print $2}' ./release/firmware.ini)

# Publish Github release
gh release create "${VERSION}" ./release/* --title "${VERSION}" --target "${firmware_sha}"

# Upload ESP32 firmware to Azure
# - This requires Azure CLI to be installed
# - This requires the environment variable AZURE_STORAGE_SAS_TOKEN to be set
az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "brewblox-esp32-${VERSION}.bin" \
    --file ./release/brewblox-esp32.bin
