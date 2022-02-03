# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.209.6/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

RUN apt-get update -q \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        curl \
    && apt-get -y install --no-install-recommends \
        build-essential \
        autoconf \
        automake \
        libtool \
        unzip \
        pkg-config \
        libprotobuf-dev \
        protobuf-compiler \
        tzdata \
        dfu-util \
        python-is-python3 \
        python3-pip \
        python3-protobuf \
        gcovr \
        rsync \
        bear \
        gcc-10

# install arm compiler
ENV GCC_ARM_URL="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.07/gcc-arm-none-eabi-10.3-2021.07-x86_64-linux.tar.bz2" \
  GCC_ARM_VERSION="10.3-2021.07"

RUN dpkg --add-architecture i386 \
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
  && apt-get remove -qy bzip2 \
  && apt-get clean \
  && apt-get purge \
  && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/local/gcc-arm-embedded/share

ENV PATH /usr/local/gcc-arm-embedded/bin:$PATH

# download and compile boost and install as system includes (/usr/local)
ENV BOOST_VERSION=1_72_0 \
  BOOST_ROOT=/boost/boost_1_72_0

RUN mkdir -p /boost && curl -sSL https://s3.amazonaws.com/spark-assets/boost_$BOOST_VERSION.tar.gz | tar -xz -C /boost \
  && export DYLD_LIBRARY_PATH="$BOOST_ROOT/stage/lib:$DYLD_LIBRARY_PATH" \
  && export LD_LIBRARY_PATH="$BOOST_ROOT/stage/lib:$LD_LIBRARY_PATH" \
  && cd $BOOST_ROOT \
  && ./bootstrap.sh \  
  && ./b2  --with-thread --with-system --with-program_options --with-random --with-regex --threading=multi link=static runtime-link=static
