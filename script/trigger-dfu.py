#!/usr/bin/env python3

import sys
from time import sleep

import usb
from serial import Serial
from serial.tools import list_ports

VID_PARTICLE = 0x2b04
PID_PARTICLE = [
    0xc006,  # Photon
    0xc008,  # P1
]
PID_PARTICLE_DFU = [
    0xd006,  # Photon
    0xd008,  # P1
]


def main():
    if port := next((p for p in list_ports.comports()
                    if p.vid == VID_PARTICLE and p.pid in PID_PARTICLE), None):
        print('Triggering DFU:', port.product, port.serial_number)
        serial = Serial(port.device, 14400)
        sleep(1)
        serial.close()

    elif usb.core.find(
            custom_match=lambda d: (d.idVendor == VID_PARTICLE and d.idProduct in PID_PARTICLE_DFU)):
        print('Device is already in DFU mode')

    else:
        return 'ERROR: No Photon/P1 USB device found'


if __name__ == '__main__':
    sys.exit(main())
