# Brewblox firmware
[![Build Status](https://dev.azure.com/brewblox/brewblox/_apis/build/status/BrewBlox.brewblox-firmware?branchName=develop)](https://dev.azure.com/brewblox/brewblox/_build/latest?definitionId=10&branchName=develop)

This is the main firmware source code repository for the Brewblox Spark.
For user documentation and install guides, see https://www.brewblox.com.

## Development
The development environment is based on the [development container](https://code.visualstudio.com/docs/remote/containers) feature in the [Visual Studio Code](https://code.visualstudio.com/) editor.
A [Dockerfile](./.devcontainer/Dockerfile) is provided that includes the required dependencies for most build types.

When opening the repository in VSCode, you will be prompted to reload the editor in the container.
On first load, it will build the Docker image. This will take somewhere between 5 and 30 minutes, depending on your machine.

When this is done, intellisense, build tasks, and the VSCode terminal will run in the container.

If you wish to use a different editor, you will need to either manually build the Docker image, or reproduce the installation steps on your local machine.

## Submodules
The repository includes multiple nested [Git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules).
These are not loaded by default when you clone the repository.
To load them, run:
```
git submodule update --init --recursive
```

## Build targets
The Spark firmware is built for six targets, using two separate toolchains.
A generic simulator that does not depend on a device-specific toolchain is in the works.

| Target | Platform | Toolchain |
|---|---|---|
| Photon | Spark 2 | Particle |
| P1 | Spark 3 | Particle |
| ESP32 | Spark 4 | ESP-IDF |
| AMD64 | Simulator | Particle |
| ARM32 | Simulator | Particle |
| ARM64 | Simulator | Particle |

In addition to this, there are three separate test suites:
- [lib](./lib/test)
- [brewblox-particle](./app/brewblox-particle/test)
- [controlbox](./controlbox/test)

## Protobuf
Communication with the [Spark service](https://github.com/brewblox/brewblox-devcon-spark) is encoded using [Protocol Buffers](https://developers.google.com/protocol-buffers) (protobuf).

The message definitions are stored in the [brewblox-proto](https://github.com/BrewBlox/brewblox-proto) repository, which is included as a submodule.
The messages are compiled to C/C++, and the generated files are committed in this repository.
A build-time check is done whether the compiled files match the active brewblox-proto submodule commit.

To assist with tests, messages are compiled twice: once using [Nanopb](https://github.com/nanopb/nanopb) for the actual firmware, and once using the Google compiler for the brewblox-particle test suite.

To compile proto files, use the [build/compile-proto.sh](build/compile-proto.sh) script. This is only required if the submodule commit for brewblox-proto was changed.

## Deployment and releases
The CI build collects the artifacts for all build targets, and uploads a tarball to Azure file storage along with a `firmware.ini` file detailing build dates and version hashes. This is done for every non-PR CI build.

For the firmware build to be released to users, the [Spark service](https://github.com/brewblox/brewblox-devcon-spark) must include the new firmware in its Docker image.
This is done by downloading and committing the new `firmware.ini` file, and then triggering a CI build.

During the Spark service CI build, the firmware tarball that matches the version hash in `firmware.ini` is downloaded from Azure storage, and included in the resulting Docker image.

## License
Unless stated elsewhere, file headers or otherwise, all files herein are licensed under an GPLv3 license. For more information, please read the LICENSE file.

## Contributing
Contributions to our firmware are very welcome. To avoid wasted efforts, we recommend first discussing proposed changes on the [community forum](https://community.brewpi.com/) or [Discord](https://discord.gg/WaFYD2jaaT).

Please send pull requests against the develop branch. We can only accept your pull request if you have signed our [Contributor License Agreement (CLA)](http://www.brewpi.com/cla/).
