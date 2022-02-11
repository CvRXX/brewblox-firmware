#! /usr/bin/env bash
# shellcheck source=./_init.sh
source /opt/esp/idf/export.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

cd app/brewblox-esp
idf.py "$@"
