#! /usr/bin/env bash
# shellcheck source=./_init.sh
source /opt/esp/idf/export.sh
source "$(git rev-parse --show-toplevel)/script/_init.sh"

espsecure.py generate_signing_key --version 1 app/brewblox-esp/secure_boot_signing_key.pem
