# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.209.6/containers/debian/.devcontainer/base.Dockerfile
FROM mcr.microsoft.com/vscode/devcontainers/base:0-focal

RUN : \
    && apt-get update -q \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        curl \
        wget \
        software-properties-common \
    && apt-get update -q \
    && add-apt-repository ppa:aos1/diff-so-fancy \
    && apt-get -y install --no-install-recommends \
        autoconf \
        automake \
        bash-completion \
        bear \
        bison \
        build-essential \
        ca-certificates \
        ccache \
        check \
        diff-so-fancy \
        dfu-util \
        flex \
        g++-10 \
        gcc-10 \
        gcovr \
        gdb \
        git \
        gperf \
        jq \
        lcov \
        libffi-dev \
        libncurses-dev \
        libprotobuf-dev \
        libpython2.7 \
        libtool \
        libusb-1.0-0-dev \
        make \
        ninja-build \
        pkg-config \
        protobuf-compiler \
        python3 \
        python3-pip \
        python3-protobuf \
        python-is-python3 \
        ripgrep \
        rsync \
        shellcheck \
        tzdata \
        udev \
        unzip \
        usbutils \
        xz-utils \
        zip \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 20 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 20 \
    && python3 -m pip install --upgrade \
        autopep8 \
        pip \
        pyserial \
        pyusb \
        virtualenv \
    && :

# Set udev rules so we can flash Particle devices
RUN : \
    && mkdir -p /etc/udev/rules.d \
    && echo 'SUBSYSTEMS=="usb", ATTRS{idVendor}=="2b04", ATTRS{idProduct}=="[cd]00?", GROUP="plugdev", MODE="0666"' \
        > /etc/udev/rules.d/50-particle.rules \
    && :

# install arm compiler (required for Particle builds)
ENV GCC_ARM_URL="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2" \
  GCC_ARM_VERSION="10.3-2021.07"

RUN : \
    && dpkg --add-architecture i386 \
    && apt-get update -q \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        isomd5sum \
        bzip2 \
        vim-common \
        libarchive-zip-perl \
        libc6:i386 \
    && curl -o /tmp/gcc-arm-none-eabi.tar.bz2 -sSL ${GCC_ARM_URL} \
    && tar xjvf /tmp/gcc-arm-none-eabi.tar.bz2 -C /usr/local \
    && mv /usr/local/gcc-arm-none-eabi-${GCC_ARM_VERSION}/ /usr/local/gcc-arm-embedded \
    && rm -rf /usr/local/gcc-arm-embedded/share \
    && :

ENV PATH /usr/local/gcc-arm-embedded/bin:$PATH

# download and compile boost and install as system includes (/usr/local)
ARG BOOST_VERSION=1_72_0
ENV BOOST_ROOT=/boost/boost_${BOOST_VERSION}

RUN : \
    && mkdir -p /boost \
    && curl -sSL https://s3.amazonaws.com/spark-assets/boost_$BOOST_VERSION.tar.gz | tar -xz -C /boost \
    && export DYLD_LIBRARY_PATH="$BOOST_ROOT/stage/lib:$DYLD_LIBRARY_PATH" \
    && export LD_LIBRARY_PATH="$BOOST_ROOT/stage/lib:$LD_LIBRARY_PATH" \
    && cd $BOOST_ROOT \
    && ./bootstrap.sh \
    && ./b2 --with-thread --with-system --with-program_options --with-random --with-regex --threading=multi link=static runtime-link=static \
    && :

# Install idf.py
ARG IDF_CLONE_URL=https://github.com/espressif/esp-idf.git
ARG IDF_CLONE_BRANCH_OR_TAG=v4.4
ARG IDF_CHECKOUT_REF=

ENV IDF_PATH=/opt/esp/idf
ENV IDF_TOOLS_PATH=/opt/esp
ENV IDF_CCACHE_ENABLE=1

RUN echo IDF_CHECKOUT_REF=$IDF_CHECKOUT_REF IDF_CLONE_BRANCH_OR_TAG=$IDF_CLONE_BRANCH_OR_TAG && \
    git clone --recursive \
      ${IDF_CLONE_BRANCH_OR_TAG:+-b $IDF_CLONE_BRANCH_OR_TAG} \
      $IDF_CLONE_URL $IDF_PATH && \
    if [ -n "$IDF_CHECKOUT_REF" ]; then \
      cd $IDF_PATH && \
      git checkout $IDF_CHECKOUT_REF && \
      git submodule update --init --recursive; \
    fi

RUN : \
    && update-ca-certificates --fresh \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install required \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install cmake \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install-python-env \
    && rm -rf $IDF_TOOLS_PATH/dist \
    && :

# Give the user the required permissions for using USB devices
ARG USERNAME=vscode
RUN : \
    && usermod -aG dialout $USERNAME \
    && usermod -aG plugdev $USERNAME \
    && :
