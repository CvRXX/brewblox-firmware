# Brewblox ESP32 firmware
This folder contains the ESP32 specific files for the Brewblox application.

Some ESP32 hardware-specific files can be found in platform/esp

# Building
The firmware must be compiled with esp-idf version 4.3. Check out tag v4.3, not branch release/4.3.
To ensure that you have all needed submodules, run 
```
git checkout --recurse-submodules
```
You might also need 
```
git submodule sync
```
and 
```
git submodule update --init --recursive
```


First, run your platform-specific export.xx file from the esp-idf directly to enable the tools.
Then run `idf.py build` in this directory.

To build, flash and start the USB monitor: 
```
idf.py build && idf.py flash --port /dev/ttyUSB0 && idf.py monitor --port /dev/ttyUSB0
```
When running the monitor, you can rebuild and flash with CTRL-T A.

Instead of installing the toolchain locally, you can use the esp-idf docker container. See `build.sh`.

# Secure boot and OTA
We use a secure boot signing key to verify binaries that are flashed over-the-air (OTA).
This key is generated by running 
```
espsecure.py generate_signing_key --version 1 secure_boot_signing_key.pem
```

Firmware that is built in our Azure pipeline uses the real (secret) signing key. Pull requests are built with `PLACEHOLDER_SIGNING_KEY.pem`.
When you want to flash over-the-air with firmware you have built yourself, you first have to do a full USB flash including the bootloader to use your own signing key.
To flash over-the-air locally, you can use 

```
ota-flash.sh <ip address of the esp32>
```

It starts a python HTTP server to host the firmware and sends the URL to the ESP.

# Wifi provisioning
This app uses Wifi provisioning, as described here:
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/provisioning/wifi_provisioning.html

A unique QR code is generated by the firmware.
This QR code is printed over USB serial when Wifi has not been provisioned yet.

Scan it with the [Android app](https://play.google.com/store/apps/details?id=com.espressif.provble) or [Ios App](https://apps.apple.com/in/app/esp-softap-provisioning/id1474040630).
It will ask for Wifi credentials and send them to the ESP32 over BLE.

To reset provisioning and erase WiFi credentials, hold the OK button for 5 seconds after reset.

# Data persistence
Blocks data is persisted on the blocks spiffs partition. The NVS partition is used for system config like Wifi provisioning.
Both are automatically formatted when they are not initialized correctly.

# Core dump
When a hard crash occurs, the ESP writes a core dump to flash.
To read the core dump, run:
```
espcoredump.py -p /dev/ttyUSB0 info_corefile build/brewblox_esp.elf
```

To analyze a core dump exported with `brewblox-ctl coredump`, run:

```
espcoredump.py info_corefile -c filename --core-format=b64 build/brewblox_esp.elf
```


# Code formatting
We use clang-format for formatting. This repo includes a `.clang-format` file with a spec. Please use it when submitting a PR.

