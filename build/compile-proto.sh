#!/bin/bash

handle_error() {
  echo "Encountered error when executing $(basename $0)!" >&2
  echo "Error on line $(caller)" >&2
  exit 1
}
trap handle_error ERR

MY_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SCRIPT_DIR="$(readlink -f "${MY_DIR}/../brewblox/blox/compiled_proto")"

# rebuild generator, particle doesn't keep the compiled version up to date
pushd "$MY_DIR/../platform/spark/device-os/third_party/nanopb/nanopb/generator/proto" > /dev/null || exit 1
if [ -f nanopb_pb2.py ]; then
  rm nanopb_pb2.py 
fi
make
popd > /dev/null || exit 1

echo -e "Compiling proto files using nanopb for brewblox firmware"
bash "$SCRIPT_DIR/compile_proto.sh"

echo -e "Compiling proto files using google protobuf for unit tests"
bash "$SCRIPT_DIR/compile_test_proto.sh"

echo "Done"

pushd "$MY_DIR/../platform/spark/device-os/third_party/nanopb/nanopb/generator/proto" > /dev/null || exit 1
git checkout nanopb_pb2.py # revert submodule changes
popd > /dev/null || exit 1
exit
