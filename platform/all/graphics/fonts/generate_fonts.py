#!/usr/bin/env python3

# when you get a syntax error running this script, you are probably not using python 3

import os
import sys
from shutil import which

# to find icon code, search in https://raw.githubusercontent.com/Templarian/MaterialDesign-Font/master/cheatsheet.html
# convert hex to utf8 and add to fonts.hpp

icons = [
    "0xF091F",  # Wifi strength 1
    "0xF0922",  # Wifi strength 2
    "0xF0925",  # Wifi strength 3
    "0xF0928",  # Wifi strength 4
    "0xF092E",  # Wifi off
    "0xF0200",  # Ethernet
    "0xF0055",  # arrow-thick-right
]

# from space to ~. Includes punctuation and numbers, not accent letters
letters = '0x20-0x7E'
numbers = [
    '0x20',  # space
    '0x25',  # %
    '0xB0',  # degree symbol
    '0x43',  # C
    '0x46',  # F
    '0x2D',  # -
    '0x30-0x39',  # 0-9
    '0x2E',  # period
]

degree = '0xB0'
bullet = '0x2022'

size_numbers_medium = 20
size_numbers_large = 36
size_main = 16
size_main_small = 12

if not which("npx"):
    print("npx not found, to install, run 'npm i -g npx'")
    exit(1)

os.system(
    f"npx lv_font_conv --no-compress --no-prefilter --bpp 4 --format lvgl --size {size_numbers_medium} "
    f"--font Roboto-Medium.ttf -r {','.join(numbers)} "
    f"-o font_numbers_medium.c"
)

os.system(
    f"npx lv_font_conv --no-compress --no-prefilter --bpp 4 --format lvgl --size {size_numbers_large} "
    f"--font Roboto-Medium.ttf -r {','.join(numbers)} "
    f"-o font_numbers_large.c"
)

os.system(
    f"npx lv_font_conv --no-compress --no-prefilter --bpp 4 --format lvgl --size {size_main} "
    f"--font Roboto-Medium.ttf -r {','.join([letters, degree])} "
    f"--font materialdesignicons-webfont.ttf -r {','.join(icons)} "
    f"-o font_main.c"
)

os.system(
    f"npx lv_font_conv --no-compress --no-prefilter --bpp 4 --format lvgl --size {size_main_small} "
    f"--font Roboto-Medium.ttf -r {','.join([letters, degree])} "
    f"--font materialdesignicons-webfont.ttf -r {','.join(icons)} "
    f"-o font_main_small.c"
)
