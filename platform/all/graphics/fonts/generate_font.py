#!/usr/bin/env python3.6

import argparse
from argparse import RawTextHelpFormatter
import os
import sys


#Symbols to add
syms = "0xF091F" # Wifi strength 1
syms += ",0xF0922" # Wifi strength 2
syms += ",0xF0925" # Wifi strength 3
syms += ",0xF0928" # Wifi strength 4
syms += ",0xF092E" # Wifi off
syms += ",0xF0201" # Ethernet on
syms += ",0xF0202" # Ethernet off

sizesToGen = [8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48]

#Run the command (Add degree and bbullet symbol)
for size in sizesToGen:
    cmd = "lv_font_conv --no-compress --no-prefilter --bpp 4 --size {} --font Roboto-Medium.ttf -r '0x20-0x7F,0xB0,0x2022' --font materialdesignicons-webfont.ttf -r {} --format lvgl -o main_font_{}.cpp --force-fast-kern-format".format(size,syms,size)
    os.system(cmd)
