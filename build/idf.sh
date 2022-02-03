#! /usr/bin/env bash
# shellcheck source=./_init.sh
source /opt/esp/idf/export.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd app/brewblox-esp
idf.py "$@"
