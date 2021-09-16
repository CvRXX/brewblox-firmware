#!/bin/bash

docker run --rm -v "$PWD":/project -w /project espressif/idf:v4.3.1 idf.py build