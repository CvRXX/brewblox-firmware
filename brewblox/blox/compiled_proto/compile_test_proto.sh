#!/usr/bin/env bash
set -euo pipefail

# generates cpp with google's protobuf implementation. Not used in firmware, but used in unit test code
# do some renames so the names don't cause conflicts when both are used

SCRIPT_DIR="$(readlink -f "$(dirname "$0")")"
PROTO_DIR="${SCRIPT_DIR}/../proto"
TEST_PROTO_DIR="${SCRIPT_DIR}/test_proto"
CPP_DIR="${SCRIPT_DIR}/test_src"

mkdir -p "${TEST_PROTO_DIR}"

# copy proto files with _test appended and fix includes to prevent name clashes
for file in "${PROTO_DIR}/"*.proto
do
  testfile="${TEST_PROTO_DIR}/$(basename "$file" .proto)_test.proto"
  cp -f "$file" "$testfile"
  sed -ri 's/import "(\w+)\.proto";/import "\1_test.proto";/g' "$testfile"
  sed -ri 's/package blox/package blox_test/g' "$testfile"
  sed -ri 's/brewblox!(.proto)/brewblox_test/g' "$testfile"
  sed -ri 's/controlbox!(.proto)/controlbox_test/g' "$testfile"
  sed -ri 's/nanopb!(.proto)/nanopb_test/g' "$testfile"
done

# compile modified proto files
pushd "${TEST_PROTO_DIR}"
protoc \
  --cpp_out="${CPP_DIR}" \
  --proto_path "${TEST_PROTO_DIR}" \
  "${TEST_PROTO_DIR}/"*.proto
popd > /dev/null

rm -rf "${TEST_PROTO_DIR}"
