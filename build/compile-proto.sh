#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

handle_error() {
    echo "Encountered error when executing $(basename "$0")!" >&2
    echo "Error on line $(caller)" >&2
    exit 1
}
trap handle_error ERR

PROTO_DIR="$(readlink -f external_libs/brewblox-proto)" # must be absolute
OUT_DIR="$(readlink -f lib/compiled_proto/proto)"
TEST_PROTO_DIR="$(readlink -f test/proto/src)"
TEST_OUT_DIR="$(readlink -f test/proto)"

NANOPB_DIR="$(readlink -f platform/spark/device-os/third_party/nanopb/nanopb)"
NANOPB_GENERATOR_DIR="${NANOPB_DIR}/generator/proto"
NANOPB_PLUGIN="${NANOPB_DIR}/generator/protoc-gen-nanopb"

# rebuild generator, particle doesn't keep the compiled version up to date
echo -e "Rebuilding nanopb generator"
{
    if [ -f "${NANOPB_GENERATOR_DIR}/nanopb_pb2.py" ]; then
        rm "${NANOPB_GENERATOR_DIR}/nanopb_pb2.py"
    fi
    make -C "${NANOPB_GENERATOR_DIR}"
}

echo -e "Compiling proto files using nanopb for brewblox firmware"
{
    pushd "${PROTO_DIR}" >/dev/null

    protoc -I"${PROTO_DIR}" -I"${NANOPB_GENERATOR_DIR}" \
        --nanopb_out="${OUT_DIR}" \
        --proto_path="${PROTO_DIR}" \
        --plugin=protoc-gen-nanopb="${NANOPB_PLUGIN}" \
        "${PROTO_DIR}"/*.proto # don't quote

    # nanopb.h and nanopb.c are not needed and generate compiler warnings
    rm -f "${OUT_DIR}"/nanopb.*

    # remove timestamp from generated files to ensure reproducible builds
    for file in "${OUT_DIR}"/*; do
        sed -i '/Generated by nanopb-/d' "${file}"
    done

    COMPILED_PROTO_VERSION=$(
        cd "${PROTO_DIR}"
        git rev-parse --short=8 HEAD
    )
    COMPILED_PROTO_DATE=$(
        cd "${PROTO_DIR}"
        git log -1 --format=%cd --date=short
    )

    rm -rf "${OUT_DIR}/proto_version.h"
    {
        echo "#pragma once"
        echo "#define COMPILED_PROTO_VERSION \"${COMPILED_PROTO_VERSION}\""
        echo "#define COMPILED_PROTO_DATE \"${COMPILED_PROTO_DATE}\""
    } >>"${OUT_DIR}/proto_version.h"

    popd >/dev/null
}

echo -e "Compiling proto files using google protobuf for unit tests"
{
    rm -rf "${TEST_PROTO_DIR}"
    mkdir -p "${TEST_PROTO_DIR}"

    # copy proto files with _test appended and fix includes to prevent name clashes
    for file in "${PROTO_DIR}/"*.proto; do
        testfile="${TEST_PROTO_DIR}/$(basename "$file" .proto)_test.proto"
        cp -f "$file" "$testfile"
        sed -ri 's/import "(\w+)\.proto";/import "\1_test.proto";/g' "$testfile"
        sed -ri 's/package blox/package blox_test/g' "$testfile"
        sed -ri 's/brewblox!(.proto)/brewblox_test/g' "$testfile"
        sed -ri 's/controlbox!(.proto)/controlbox_test/g' "$testfile"
        sed -ri 's/nanopb!(.proto)/nanopb_test/g' "$testfile"
    done

    pushd "${TEST_PROTO_DIR}" >/dev/null
    protoc \
        --cpp_out="${TEST_OUT_DIR}" \
        --proto_path "${TEST_PROTO_DIR}" \
        "${TEST_PROTO_DIR}/"*.proto
    popd >/dev/null

    rm -rf "${TEST_PROTO_DIR}"
}

git -C "${NANOPB_GENERATOR_DIR}" checkout nanopb_pb2.py # revert submodule changes

echo "Done"
