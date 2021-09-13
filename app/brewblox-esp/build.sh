#!/bin/bash

docker run --rm -v "$PWD":/project -w /project espressif/idf:v4.3 idf.py build