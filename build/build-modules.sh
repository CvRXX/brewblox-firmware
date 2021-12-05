#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd platform/spark/device-os/modules

echo "Building system modules for P1"
subtask make -s all PLATFORM=p1 PARTICLE_DEVELOP=y

echo "Building system modules for Photon"
subtask make -s all PLATFORM=photon PARTICLE_DEVELOP=y

exit $SUBTASK_STATUS
