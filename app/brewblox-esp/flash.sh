#!/bin/bash

docker run -it --privileged --rm -v "$PWD":/project -w /project espressif/idf:release-v4.4 idf.py flash