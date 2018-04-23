# Project BSTree

## UNIX-systems

**Building of a project:**

```ShellSession
$ cmake -H./sources -Bbuild
$ cmake --build build
```

**Using of program:**

Now program is ready for use in build directory

```ShellSession
$ cd build
$ ./BSTree <item1> <item2> ...
```

**Building of a project with examples:**

Just turn on the option

```ShellSession
$ cmake -DBUILD_EXAMPLES=ON -H./sources -Bbuild
$ cmake --build build
```

**Running examples:**

*Two examples are available!*

```ShellSession
$ cd build
$ ./example<number>
```