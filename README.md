# AHGPBM
Advanced Handling for Google Protocol Buffers Message in C++

[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/ZigRazor/AHGPBM.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/ZigRazor/AHGPBM/context:cpp)

[![Total alerts](https://img.shields.io/lgtm/alerts/g/ZigRazor/AHGPBM.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/ZigRazor/AHGPBM/alerts/)



### Pre-Build Operations
#### Install Google Protocol Buffers
##### First Mode
 1. sudo apt-get install autoconf automake libtool curl make g++ unzip
 2. From [this page](https://github.com/protocolbuffers/protobuf/releases), download the `protobuf-all-[VERSION].tar.gz`. 
 3. Extract the contents and change in the directory 
 4. `./configure`
 5. `make`
 6. `make check`
 7. `sudo make install`
 8. `sudo ldconfig # refresh shared library cache.`

##### Second Mode
 1. sudo apt-get install autoconf automake libtool curl make g++ unzip -y
 2. git clone https://github.com/google/protobuf.git
 3. cd protobuf
 4. git submodule update --init --recursive
 5. ./autogen.sh
 6. ./configure
 7. make
 8. makecheck 
 9. sudo make install
 10. sudo ldconfig
