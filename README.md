# AHGPBM

<a href="https://www.w3schools.com/cpp/" target="_blank"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a> Advanced Handling for Google Protocol Buffers Message in C++ 

[![CodeFactor](https://www.codefactor.io/repository/github/zigrazor/ahgpbm/badge)](https://www.codefactor.io/repository/github/zigrazor/ahgpbm)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/09b1ecbbca5945609716d468923cf503)](https://www.codacy.com/gh/ZigRazor/AHGPBM/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ZigRazor/AHGPBM&amp;utm_campaign=Badge_Grade)

[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/ZigRazor/AHGPBM.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/ZigRazor/AHGPBM/context:cpp)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/ZigRazor/AHGPBM.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/ZigRazor/AHGPBM/alerts/)

<a href="https://github.com/ZigRazor/AHGPBM/issues">
      <img alt="Issues" src="https://img.shields.io/github/issues/ZigRazor/AHGPBM?color=0088ff" />
</a>
<a href="https://github.com/ZigRazor/AHGPBM/pulls">
      <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/ZigRazor/AHGPBM?color=0088ff" />
</a>

## Introduction

The AHGPBM (Advanced Handling for Google Protocol Buffer Message) is a C++ library for the handling of the Google Protocol Buffer Message.

This library give a simple interface to handle this kind of message ( in general data to analize ).

After a first instrumentation of the internal network of the handler, you can easily inject message in the network that will handle the routing and the dispatching of the message.

## Building

The following are the operations to build the library

### Pre-Requirements

In order to create the library we need:
  1. A Linux System
  2. A G++ compiler with support for C++17
  3. CMake > 3.0.0
  4. Google Protocol Buffer Library
  5. Google Test Library

### Pre-Build Operations

The Pre-Build operations are defined to install the required Google library dependencies.

#### Install Google Protocol Buffers

##### First Mode
  
  1. `sudo apt-get install autoconf automake libtool curl make g++ unzip`
  2. From [this page](https://github.com/protocolbuffers/protobuf/releases), download the `protobuf-all-[VERSION].tar.gz`. 
  3. Extract the contents and change in the directory ( `tar xzf protobuf-all-[VERSION].tar.gz` and `cd protobuf-all-[VERSION]` )
  4. `./configure`
  5. `make`
  6. `make check`
  7. `sudo make install`
  8. `sudo ldconfig # refresh shared library cache.`

##### Second Mode
  
  1. `sudo apt-get install autoconf automake libtool curl make g++ unzip -y`
  2. `git clone https://github.com/google/protobuf.git`
  3. `cd protobuf`
  4. `git submodule update --init --recursive`
  5. `./autogen.sh`
  6. `./configure`
  7. `make`
  8. `make check` 
  9. `sudo make install`
  10. `sudo ldconfig`
   
#### Install Google Test

 1. `git clone https://github.com/google/googletest.git -b release-1.10.0`
 2. `cd googletest`        # Main directory of the cloned repository.
 3. `mkdir build`          # Create a directory to hold the build output.
 4. `cd build`
 5. `cmake ..`     or     `cmake .. -DBUILD_GMOCK=OFF`
 6. `make`
 7. `sudo make install`    # Install in /usr/local/ by default        # Generate native build scripts for GoogleTest.

### Build Operations

In order to build the AHGPBM library, you need to do the following operation:
  1. `git clone https://github.com/ZigRazor/AHGPBM.git`
  2. `cd AHGPBM` # Enter the root of the project
  3. `mkdir build` # Create Build directory
  4. `cd build` # Enter Build directory
  5. `cmake ..` # Prepare Makefile
  6. `make` # Make library

## Testing

When compiling the library is generated also a Google Test executable called `ahgpbm_test`.

In order to run the test just enter the `build` directory and execute `./ahgpbm_test`

## Usage

Work in progress...

## Example

Work in progress...

## Contributing

For detailed information on how to contribute, see <a href="https://github.com/ZigRazor/AHGPBM/blob/main/CONTRIBUTING.md">`CONTRIBUTING`</a>.


## License

Distributed under the GNU General Public License v3.0. See <a href="https://github.com/ZigRazor/AHGPBM/blob/main/LICENSE">`LICENSE`</a> for more information.


## Contact

Zig Razor - <a href="mailto:zigrazor@gmail.com">zigrazor@gmail.com</a>
