echo $MDE4CPP_CMAKE_VERSION
echo $MDE4CPP_CMAKE_BUILD_VERSION

sudo -S apt remove --purge --auto-remove cmake

sudo -S apt update
sudo -S apt install build-essential libtool autoconf unzip wget 

version=$MDE4CPP_CMAKE_VERSION
build=$MDE4CPP_CMAKE_BUILD_VERSION
## don't modify from here
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/

./bootstrap
make -j$(nproc)
sudo -S make install

sudo -S ln -s /usr/local/bin/cmake /usr/bin/cmake
