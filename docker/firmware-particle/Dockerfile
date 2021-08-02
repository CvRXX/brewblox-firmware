FROM node:14-buster-slim

WORKDIR /app

RUN set -ex \
  && apt-get update \
  && apt-get install -y \
    make \
    gcc \
    g++ \
    udev \
    libudev-dev \
    python \
    python-pip \
    usbutils \
    curl \
    dfu-util \
  && python -m pip install \
    esptool \
  && npm install --production --build-from-source --unsafe-perm \
    serialport \
    particle-cli \
    particle-usb \
  && apt-get remove -y \
    make \
    gcc \
    g++ \
  && apt-get autoremove -y \
  && rm -rf /var/lib/apt/lists/*

COPY particle /usr/local/bin/particle

ENTRYPOINT [ "/bin/bash" ]
