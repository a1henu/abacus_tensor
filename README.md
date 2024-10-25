# abacus_tensor

**Compile**

```shell
mkdir build
cd build
cmake ..
make
```

**Run unit test**

```shell
mkdir build
cd build
cmake -DBUILD_TESTING=ON -DENABLE_MPI=ON ..
make
ctest
```