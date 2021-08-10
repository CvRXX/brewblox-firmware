#!/bin/bash

# generates cpp with google's protobuf implementation. Not used in firmware, but used in unit test code
# do some renames so the names don't cause conflicts when both are used
set -e

MY_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}")"  && pwd )"
PROTO_DIR="$( cd "$( readlink -f "${MY_DIR}/../proto")"  && pwd )"

mkdir -p "$MY_DIR/test_proto"

pushd "$PROTO_DIR" # > /dev/null  # .option files are read from execution directory, so have to cd into this dir 

# copy proto files with _test appended and fix includes to prevent name clashes
for file in *.proto 
do
  testfile="$MY_DIR/test_proto/${file%.proto}_test.proto"
  cp -f "$file" "$testfile"
  sed -i 's/brewblox/brewblox_test/g' "$testfile"
  sed -i 's/BrewBlox/BrewBlox_test/g' "$testfile"
  sed -i 's/nanopb/nanopb_test/g' "$testfile"
  sed -i 's/ActuatorDigital.proto/ActuatorDigital_test.proto/g' "$testfile"
  sed -i 's/AnalogConstraints.proto/AnalogConstraints_test.proto/g' "$testfile"
  sed -i 's/DigitalConstraints.proto/DigitalConstraints_test.proto/g' "$testfile"
  sed -i 's/IoArray.proto/IoArray_test.proto/g' "$testfile"
  sed -i 's/SetpointSensorPair.proto/SetpointSensorPair_test.proto/g' "$testfile"
done

popd > /dev/null

# compile modified proto files
pushd "${MY_DIR}/test_proto"
protoc "${MY_DIR}/test_proto"/*.proto --cpp_out=../test_src --proto_path "${MY_DIR}/test_proto"
popd > /dev/null
  
rm -rf "$MY_DIR/test_proto"

# cd ../tmp_cpp
#  rsync -r --checksum . ../cpp/ --delete

