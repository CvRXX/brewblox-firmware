#! /usr/bin/env bash
set -ex

# Use repository root
pushd "$(dirname "$0")/.." > /dev/null

# Only use TTY flags if possible
test -t 1 && USE_TTY="-it"

# clean target dir to not have amd64 leftovers. Sudo needed because docker has created some files as privileged
sudo rm -rf build/target

# Enable emulation
if [[ $(arch) != 'armv7l' ]]; then
    docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
fi

# -m64 is not supported for ARM
sed -i 's/-m64//g' platform/spark/device-os/build/gcc-tools.mk

# remove debug info and optimize for size
sed -i 's/-g3//g' platform/spark/device-os/build/gcc-tools.mk
sed -i 's/-gdwarf-2//g' platform/spark/device-os/build/gcc-tools.mk
sed -i 's/-O$(GCC_OPTIMIZE)/-Os/g' platform/spark/device-os/build/gcc-tools.mk

# Pull compiler image for target arch
docker pull \
    --platform=linux/arm/v7 \
    brewblox/simulator-compiler:8

# Build
docker run \
    ${USE_TTY} \
    --rm \
    --platform=linux/arm/v7 \
    -v "$(pwd)/":/firmware/ \
    brewblox/simulator-compiler:8 \
    make APP=brewblox PLATFORM=gcc

# reset modified file
cd platform/spark/device-os
git checkout -- build/gcc-tools.mk 
