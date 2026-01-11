#(x86_64-linux-gnu-gcc(-[a-z]+)?)
#
#sudo update-alternatives --install /usr/bin/$1 $1 /usr/bin/$1-12 10
#sudo update-alternatives --install /usr/bin/$1 $1 /usr/bin/$1-13 20
#update-alternatives --display $1

sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc x86_64-linux-gnu-gcc /usr/bin/x86_64-linux-gnu-gcc-12 10
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc x86_64-linux-gnu-gcc /usr/bin/x86_64-linux-gnu-gcc-13 20
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-ar x86_64-linux-gnu-gcc-ar /usr/bin/x86_64-linux-gnu-gcc-ar-12 10
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-ar x86_64-linux-gnu-gcc-ar /usr/bin/x86_64-linux-gnu-gcc-ar-13 20
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-nm x86_64-linux-gnu-gcc-nm /usr/bin/x86_64-linux-gnu-gcc-nm-12 10
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-nm x86_64-linux-gnu-gcc-nm /usr/bin/x86_64-linux-gnu-gcc-nm-13 20
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-ranlib x86_64-linux-gnu-gcc-ranlib /usr/bin/x86_64-linux-gnu-gcc-ranlib-12 10
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-gcc-ranlib x86_64-linux-gnu-gcc-ranlib /usr/bin/x86_64-linux-gnu-gcc-ranlib-13 20

update-alternatives --display x86_64-linux-gnu-gcc
update-alternatives --display x86_64-linux-gnu-gcc-ar
update-alternatives --display x86_64-linux-gnu-gcc-nm
update-alternatives --display x86_64-linux-gnu-gcc-ranlib

rename -n 's/^(x86_64-linux-gnu-gcc(-[a-z]+)?)$/bak$1/' *
rename -n 's/^((x86_64-linux-gnu-)?g\+\+)$/bak$1/' *

sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 20
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-g++ x86_64-linux-gnu-g++ /usr/bin/x86_64-linux-gnu-g++-12 10
sudo update-alternatives --install /usr/bin/x86_64-linux-gnu-g++ x86_64-linux-gnu-g++ /usr/bin/x86_64-linux-gnu-g++-13 20

update-alternatives --display g++
update-alternatives --display x86_64-linux-gnu-g++


