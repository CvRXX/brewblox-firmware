#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

scp build/target/brewblox-p1/brewblox-p1.bin elco@diskstation:brewblox/binaries
# run on server: 'sudo docker cp binaries/brewblox-p1.bin brewblox_sparkey_1:/app/binaries/'
# flash from ui
