#!/usr/bin/env bash
# shellcheck source=./_init.sh
set -m

EXECUTABLE_DIR="$(git rev-parse --show-toplevel)/app/brewblox-simulator/build"

run() (
    echo 'start'
    valgrind --tool=massif --threshold=0.1 \
        --xtree-memory=full --xtree-memory-file="$EXECUTABLE_DIR/xtmemory.kcg" \
        --ignore-fn=call_init.part.0 \
        --ignore-fn=_IO_file_doallocate \
        --massif-out-file="$EXECUTABLE_DIR/massif.out" "$EXECUTABLE_DIR/simulator"
    echo 'stop'
)

if [ ! -f "$EXECUTABLE_DIR/simulator" ]; then
    echo "simulator executable not found!"
    exit 1
fi

rm -f massif.out
rm -f xtmemory.kcg

run
echo "main"

# open massif.out with massif-visualizer
massif-visualizer "$EXECUTABLE_DIR/massif.out" &
# open xtmemory.kcg with kcachegrind
kcachegrind "$EXECUTABLE_DIR/xtmemory.kcg" &

popd
