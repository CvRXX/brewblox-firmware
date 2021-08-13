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

# Version must match 'vMAJOR.MINOR.PATCH', with an optional postfix
if [[ ! "${VERSION}" =~ ^v[0-9]+\.[0-9]+\.[0-9]+(\-.+)?$ ]]
then
    echo "ERROR: Missing or invalid version argument."
    echo "ERROR: Version '${VERSION}' must be formatted as 'vMAJOR.MINOR.PATCH'"
    exit 1
fi

echo "Publishing brewblox/firmware-bin:${TAG} as ${VERSION}"

# Pull image
docker rm bin-box 2> /dev/null || true
docker pull brewblox/firmware-bin:"${TAG}" > /dev/null
docker create --name bin-box brewblox/firmware-bin:"${TAG}" > /dev/null

# Copy files
rm -rf ./release
docker cp bin-box:/binaries ./release

# Remove image
docker rm bin-box > /dev/null

# Add release version info to firmware.ini
echo "firmware_release=${VERSION}" >> ./release/firmware.ini

# Get release SHA from firmware.ini
firmware_sha=$(awk -F "=" '/firmware_sha/ {print $2}' ./release/firmware.ini)

# Publish Github release
gh release create "${VERSION}" ./release/* --title "${VERSION}" --target "${firmware_sha}"
