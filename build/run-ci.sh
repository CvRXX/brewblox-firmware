#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

bash build/build-tests.sh || exit 1
bash build/run-tests.sh || exit 1
