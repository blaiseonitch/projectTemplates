## COMPILING WITH CMAKE

```bash
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=/home/blaze/vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DCMAKE_CXX_COMPILER=g++
# make and run
make
./main

```
