#!/usr/bin/env bash
set -euo pipefail

# Args
TAG=${1:-"develop"}

# Push repo root
pushd "$(dirname "$0")/.." > /dev/null

if ! command -v az &> /dev/null
then
    echo "ERROR: Azure CLI could not be found. To install: https://docs.microsoft.com/en-us/cli/azure/install-azure-cli-linux?pivots=apt"
    exit 1
fi

# Azure SAS token must have been set to upload to Azure
if [[ -z "${AZURE_STORAGE_SAS_TOKEN:-}" ]]
then
    echo "ERROR: AZURE_STORAGE_SAS_TOKEN variable was not set."
    echo "You can generate a SAS token at https://portal.azure.com -> brewblox -> containers -> firmware -> Shared access tokens"
    exit 1
fi

echo "Pulling brewblox/firmware-bin:${TAG} docker image"

# Pull image
docker rm bin-box 2> /dev/null || true
docker pull brewblox/firmware-bin:"${TAG}" > /dev/null
docker create --name bin-box brewblox/firmware-bin:"${TAG}" > /dev/null

# Copy files
rm -rf ./release
docker cp bin-box:/firmware ./release

# Remove image
docker rm bin-box > /dev/null

# Get release SHA from firmware.ini
firmware_version=$(awk -F "=" '/firmware_version/ {print $2}' ./release/firmware.ini)
firmware_date=$(awk -F "=" '/firmware_date/ {print $2}' ./release/firmware.ini)
firmware_name="${firmware_date}-${firmware_version}"

archive_filename="${firmware_name}-all.tar.gz"

echo "Creating archive /tmp/${archive_filename}"
pushd release
tar -czf "/tmp/${archive_filename}" ./*
popd

echo "Publishing brewblox/firmware-bin:${TAG} as ${archive_filename}"

# Upload files
# - This requires Azure CLI to be installed
# - This requires the environment variable AZURE_STORAGE_SAS_TOKEN to be set
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
    --file "/tmp/${archive_filename}"

# Also upload a ini file named with current branch
az storage blob upload \
    --account-name brewblox \
    --container-name firmware \
    --name "${TAG}/firmware.ini" \
    --file ./release/firmware.ini
