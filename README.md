# Project BSTree

[![Build Status](https://travis-ci.org/orangejohny/BSTree.svg?branch=master)](https://travis-ci.org/orangejohny/BSTree)

## UNIX-systems

**Copy-paste:**

```shell
cmake -H./sources -Bbuild -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON -DBUILD_BENCHS=OFF -DCMAKE_INSTALL_PREFIX=install
cmake --build build --target install
cmake --build build --target test -- ARGS=--verbose
```

**Building of a project:**

```shell
cmake -H./sources -Bbuild -DCMAKE_INSTALL_PREFIX=install
cmake --build build --target install
```

**Using of program:**

Now program is ready for use in install/bin directory

```shell
cd install/bin
./BSTree <item1> <item2> ...
```

**Building of a project with examples:**

Use the option `-DBUILD_EXAMPLES=ON`

```shell
cmake -H./sources -Bbuild -DCMAKE_INSTALL_PREFIX=install -DBUILD_EXAMPLES=ON
cmake --build build --target install
```

**To run examples:**

*Six examples are available!*

```shell
cd build/bin
./example<number>
```

**Building of a project with tests:**

Use the option `-DBUILD_TESTS=ON`

```shell
cmake -H./sources -Bbuild -DCMAKE_INSTALL_PREFIX=install -DBUILD_TESTS=ON
cmake --build build --target install
```

**To run tests:**

```shell
cmake --build build --target test -- ARGS=--verbose
```

**To generate coverage report:**

*You need lcov installed!*

```shell
source ./tests/coverage.sh
```

Open the report in /debug/report/index.html

**Building of a project with benchmark:**

Use the option `-DBUILD_BENCHS=ON`

```shell
cmake -H./sources -Bbuild -DCMAKE_INSTALL_PREFIX=install -DBUILD_BENCHS=ON
cmake --build build --target install
```

**To run benchmark:**

```shell
cmake --build build --target test -- ARGS=--verbose
cat ./build/out.txt
```

It will run tests and bench simultaneously. If you want to run benchmark separately,
you should use:

```shell
./build/bench
cat out.txt
```

## Results of the benchmark

**10^1**

```java
INSERT for 10^1 elements takes 0 seconds
EXISTS for 10^1 elements takes 1e-06 seconds
PRINT_TREE for 10^1 elements takes 1.9e-05 seconds
PRINT_NODES for 10^1 elements takes 2e-06 seconds
REMOVE for 10^1 elements takes 1e-06 seconds
SAVE for 10^1 elements takes 2.3e-05 seconds
LOAD for 10^1 elements takes 1.4e-05 seconds
```

**10^2**

```java
INSERT for 10^2 elements takes 0 seconds
EXISTS for 10^2 elements takes 0 seconds
PRINT_TREE for 10^2 elements takes 0.000126 seconds
PRINT_NODES for 10^2 elements takes 8e-06 seconds
REMOVE for 10^2 elements takes 0 seconds
SAVE for 10^2 elements takes 8e-06 seconds
LOAD for 10^2 elements takes 1.1e-05 seconds
```

**10^3**

```java
INSERT for 10^3 elements takes 1e-06 seconds
EXISTS for 10^3 elements takes 1e-06 seconds
PRINT_TREE for 10^3 elements takes 0.001519 seconds
PRINT_NODES for 10^3 elements takes 0.0001 seconds
REMOVE for 10^3 elements takes 1e-06 seconds
SAVE for 10^3 elements takes 2.9e-05 seconds
LOAD for 10^3 elements takes 4.3e-05 seconds
```

**10^4**

```java
INSERT for 10^4 elements takes 1e-06 seconds
EXISTS for 10^4 elements takes 2e-06 seconds
PRINT_TREE for 10^4 elements takes 0.015946 seconds
PRINT_NODES for 10^4 elements takes 0.001527 seconds
REMOVE for 10^4 elements takes 2e-06 seconds
SAVE for 10^4 elements takes 5.8e-05 seconds
LOAD for 10^4 elements takes 0.000255 seconds
```

**10^5**

```java
INSERT for 10^5 elements takes 1e-06 seconds
EXISTS for 10^5 elements takes 1e-06 seconds
PRINT_TREE for 10^5 elements takes 0.150038 seconds
PRINT_NODES for 10^5 elements takes 0.008383 seconds
REMOVE for 10^5 elements takes 1e-06 seconds
SAVE for 10^5 elements takes 2.7e-05 seconds
LOAD for 10^5 elements takes 0.002658 seconds
```

**10^6**

```java
INSERT for 10^6 elements takes 1e-06 seconds
EXISTS for 10^6 elements takes 1e-06 seconds
PRINT_TREE for 10^6 elements takes 1.64352 seconds
PRINT_NODES for 10^6 elements takes 0.13579 seconds
REMOVE for 10^6 elements takes 3e-06 seconds
SAVE for 10^6 elements takes 2.5e-05 seconds
LOAD for 10^6 elements takes 0.093475 seconds
```

**10^7**

```java
INSERT for 10^7 elements takes 2e-06 seconds
EXISTS for 10^7 elements takes 1e-06 seconds
PRINT_TREE for 10^7 elements takes 17.3796 seconds
PRINT_NODES for 10^7 elements takes 1.60726 seconds
REMOVE for 10^7 elements takes 3e-06 seconds
SAVE for 10^7 elements takes 2.6e-05 seconds
LOAD for 10^7 elements takes 1.16019 seconds
```
