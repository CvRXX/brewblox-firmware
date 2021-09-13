#! /usr/bin/env bash
set -ex

# Use repository root
pushd "$(dirname "$0")/.." > /dev/null

# clean target dir
sudo rm -rf build/target

# Build with idf.py in a container
bash build/idf.sh build
