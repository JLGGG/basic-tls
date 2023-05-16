#!/bin/bash

# Save the result of nproc to a variable
cores=$(nproc)
echo "Number of cores: $cores"

# Install GMP
# Reference: https://gmplib.org/gmp-man-6.1.2.pdf
wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
lzip -d gmp-6.2.1.tar.lz
tar -xvf gmp-6.2.1.tar
cd gmp-6.2.1
./configure --prefix=/usr/local --enable-cxx
make -j "$cores" && make check -j "$cores" && make install -j "$cores"

# Return to workdir
cd ..

# Install CMake
wget https://github.com/Kitware/CMake/releases/download/v3.26.3/cmake-3.26.3.tar.gz
tar -xvf cmake-3.26.3.tar.gz
cd cmake-3.26.3
./bootstrap --prefix=/usr/local
make -j "$cores" && make install -j "$cores"

# Return to workdir
cd ..

# Clone repository to tls
mkdir tls
cd tls
git clone https://github.com/JLGGG/basic-tls.git
