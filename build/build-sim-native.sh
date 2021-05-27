#! /usr/bin/env bash
set -e
pushd "$(dirname "$0")" > /dev/null

if [[ $(arch) != 'x86_64' ]]; then
    # -m64 is not supported for ARM
    sed -i 's/-m64//g' platform/spark/device-os/build/gcc-tools.mk
fi

make APP=brewblox PLATFORM=gcc

# reset modified file
cd platform/spark/device-os
git checkout -- build/gcc-tools.mk 
