#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

bash build/clean-all.sh
bash docker/start-compiler.sh
docker exec firmware-compiler bash build-tests.sh
docker exec firmware-compiler ../app/brewblox-particle/test/build/brewblox_test_runner
docker exec firmware-compiler ../controlbox/build/cbox_test_runner
docker exec firmware-compiler ../lib/test/build/lib_test_runner
