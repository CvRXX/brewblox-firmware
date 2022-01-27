#!/bin/bash
# shellcheck source=./_init.sh
source "$(git rev-parse --show-toplevel)/build/_init.sh"

cd docker

docker-compose exec compiler make -C "../app/brewblox-particle/test" clean
docker-compose exec compiler make -C "../lib/test" clean
docker-compose exec compiler make -C "../controlbox" clean

docker-compose exec compiler make clean PLATFORM=gcc
docker-compose exec compiler make clean PLATFORM=p1
docker-compose exec compiler make clean PLATFORM=photon
