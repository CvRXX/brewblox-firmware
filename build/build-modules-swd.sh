#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd platform/spark/device-os/modules

echo "Building system modules for P1 with SWD"
subtask make clean -s all PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y

echo "Flashing system modules with SWD"
subtask make -s program-dfu PLATFORM=p1 PARTICLE_DEVELOP=y USE_SWD=y

exit $SUBTASK_STATUS
