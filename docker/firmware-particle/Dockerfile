FROM node:14-bullseye-slim

WORKDIR /app

ENV PIP_EXTRA_INDEX_URL=https://www.piwheels.org/simple

RUN set -ex \
  && apt-get update \
  && apt-get install -y \
    build-essential \
    udev \
    libudev-dev \
    libffi-dev \
    python3-dev \
    python3-pip \
    usbutils \
    curl \
    dfu-util \
  && python3 -m pip install \
    esptool \
  && npm install --production --build-from-source --unsafe-perm \
    serialport \
    particle-cli \
    particle-usb \
  && apt-get remove -y \
    build-essential \
  && apt-get autoremove -y \
  && rm -rf /var/lib/apt/lists/*

COPY particle /usr/local/bin/particle

ENTRYPOINT [ "/bin/bash" ]
