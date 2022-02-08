#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

sudo rm -rf build/target
bash build/idf.sh build
