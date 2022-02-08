#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

bash build/clean-all.sh
bash build/build-tests.sh
bash build/run-tests.sh
