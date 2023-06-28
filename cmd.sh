export CC="/usr/local/bin/gcc"
export CFLAGS="-I/usr/local/opt/llvm/include -fopenmp -I/opt/homebrew/opt/fftw/include"
export LDFLAGS="-L/usr/local/opt/llvm/lib -L/opt/homebrew/opt/fftw/lib"

sh autogen.sh
./configure --prefix=$(pwd)
make
sudo make install
