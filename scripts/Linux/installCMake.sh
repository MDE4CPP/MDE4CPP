sudo apt remove --purge --auto-remove cmake

sudo apt update
sudo apt install build-essential libtool autoconf unzip wget

version=4.3
build=1
## don't modify from here
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/

./bootstrap
make -j$(nproc)
sudo make install

sudo ln -s /usr/local/bin/cmake /usr/bin/cmake
