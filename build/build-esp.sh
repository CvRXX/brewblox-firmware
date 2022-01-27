#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

# clean target dir
sudo rm -rf build/target

# Build with idf.py in a container
bash build/idf.sh build
