#!/usr/bin/env bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

bash script/idf.sh flash
