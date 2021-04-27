# AHGPBM
<a href="https://www.w3schools.com/cpp/" target="_blank"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a> Advanced Handling for Google Protocol Buffers Message in C++ 

[![CodeFactor](https://www.codefactor.io/repository/github/zigrazor/ahgpbm/badge)](https://www.codefactor.io/repository/github/zigrazor/ahgpbm)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/09b1ecbbca5945609716d468923cf503)](https://www.codacy.com/gh/ZigRazor/AHGPBM/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ZigRazor/AHGPBM&amp;utm_campaign=Badge_Grade)

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
   
#### Install Google Test

1. git clone https://github.com/google/googletest.git -b release-1.10.0
2. cd googletest        # Main directory of the cloned repository.
3. mkdir build          # Create a directory to hold the build output.
4. cd build
5. cmake ..     or     cmake .. -DBUILD_GMOCK=OFF
6. make
7. sudo make install    # Install in /usr/local/ by default        # Generate native build scripts for GoogleTest.
