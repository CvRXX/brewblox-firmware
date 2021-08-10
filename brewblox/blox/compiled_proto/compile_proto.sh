#!/bin/bash

set -e

PROTO_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}")/../proto"  && pwd )"
NANOPB_PATH="$(readlink -f "${PROTO_DIR}/../../../platform/spark/device-os/third_party/nanopb/nanopb")"
PROTOC_NANOPB_PLUGIN="${NANOPB_PATH}/generator/protoc-gen-nanopb"
if [[ "${OSTYPE}" == "msys" ]]; then
	PROTOC_NANOPB_PLUGIN="${PROTOC_NANOPB_PLUGIN}.bat" # add .bat when on windows
fi

pushd "$PROTO_DIR" > /dev/null # .option files are read from execution directory, so have to cd into this dir 

protoc -I"${PROTO_DIR}" -I"${NANOPB_PATH}/generator" \
--nanopb_out=../compiled_proto/src \
--proto_path="${PROTO_DIR}" \
--plugin=protoc-gen-nanopb="${PROTOC_NANOPB_PLUGIN}" \
${PROTO_DIR}/*.proto # don't quote

rm -f ../compiled_proto/src/nanopb.* # nanopb.h and nanopb.c are not needed and generate compiler warnings when they are not removed

popd > /dev/null 
