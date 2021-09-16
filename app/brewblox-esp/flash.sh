#!/bin/bash

docker run -it --privileged --rm -v "$PWD":/project -w /project espressif/idf:v4.3.1 idf.py flash