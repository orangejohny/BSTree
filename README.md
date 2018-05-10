# Project BSTree

[![Build Status](https://travis-ci.org/orangejohny/BSTree.svg?branch=master)](https://travis-ci.org/orangejohny/BSTree)

## UNIX-systems

**Copy-paste:**

```shell
cmake -H./sources -Bbuild -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON -DCMAKE_INSTALL_PREFIX=install
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

*Five examples are available!*

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