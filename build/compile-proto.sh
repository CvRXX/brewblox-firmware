#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

handle_error() {
  echo "Encountered error when executing $(basename "$0")!" >&2
  echo "Error on line $(caller)" >&2
  exit 1
}
trap handle_error ERR

SCRIPT_DIR="brewblox/blox/compiled_proto"
GENERATOR_DIR="platform/spark/device-os/third_party/nanopb/nanopb/generator/proto"

# rebuild generator, particle doesn't keep the compiled version up to date
if [ -f "${GENERATOR_DIR}/nanopb_pb2.py" ]; then
  rm "${GENERATOR_DIR}/nanopb_pb2.py"
fi
make -C "${GENERATOR_DIR}"

echo -e "Compiling proto files using nanopb for brewblox firmware"
bash "$SCRIPT_DIR/compile_proto.sh"

echo -e "Compiling proto files using google protobuf for unit tests"
bash "$SCRIPT_DIR/compile_test_proto.sh"

echo "Done"
git -C "${GENERATOR_DIR}" checkout nanopb_pb2.py # revert submodule changes
