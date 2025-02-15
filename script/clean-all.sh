#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

make -C test/blocks clean
make -C test/cbox clean
make -C test/control clean
rm -f test/compile_commands.json

bash script/build.sh photon clean
bash script/build.sh p1 clean
bash script/build.sh gcc clean
bash script/build.sh sim clean
bash script/build.sh esp clean
rm -f build/compile_commands_*.json

echo "Removing build/ target directories"
rm -rf build/target
rm -rf build/coverage
