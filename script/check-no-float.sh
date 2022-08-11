#!/usr/bin/env bash

grep __...sf3 build/target/brewblox-p1/brewblox-p1.map
if [[ $? -eq 0 ]]; then
    echo "Single floating point math found in firmare!" 1>&2
    echo "Check lst file for these: build/target/brewblox-p1/brewblox-p1.lst" 1>&2
    exit 1
fi
grep __...df3 build/target/brewblox-p1/brewblox-p1.map
if [[ $? -eq 0 ]]; then
    echo "Double floating point math found in firmare!" 1>&2
    echo "Check lst file for these: build/target/brewblox-p1/brewblox-p1.lst" 1>&2
    exit 1
fi
