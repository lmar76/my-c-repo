# Example of shared and static libraries

This is an Example of how to build `mylib` library as a shared library and as
a static library and how to use it.

## Build the shared library

### Manually

Build `mylib` shared library:
```
gcc -Wall -fPIC -shared -o libmylib.so mylib.c
```
where:
- `-Wall` is a warning option turning on many warning flags (see [Warning
  Options]: <https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Warning-Options.html>)
- `-fPIC` is an option for creating shared libraries (see [Code Generation
  Options]: <https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Code-Gen-Options.html>)
- `-shared`: is an option for the linker allowing to generate a shared object
  which can be linked with other objects to form an executable (see [Link
  Options]: <https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Link-Options.html>).

The command generates the `libmylib.so` file.

### Using `make`

Build `mylib` shared library.
```
make
```
The command generates the object file `mylib.o` and the shared library
`libmylib.so`.

## Install the shared library

In this example, `mylib` is installed into `/opt/mylib`:
- header file is installed into `/opt/mylib/include`
- shared object is installed into `/opt/mylib/lib`.

### Manually

Create the directory structure defined above and copy the header file and the
shared object to their destinations.

### Using `make`

Install `mylib` shared library:
```
sudo make install
```
The command creates the following files:
- `/opt/mylib/include/mylib.h`
- `/opt/mylib/lib/libmylib.so`

## Use the shared library

Copy the `test.c` file into `/tmp` and go to that directory.

Build `test` executable:
```
gcc -o test -I /opt/mylib/include -L /opt/mylib/lib -l mylib test.c
```
where:
- `-I` adds the specified directory to the list of directories to be searched
  for header files during preprocessing (see [Directory Options]:
  <https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Directory-Options.html>)
- `-l` search the named library when linking (see [Link Options])
- `-L` adds the specified directory to the list of directories to be searched
  for the one specified by `-l`.

This command generates the `test` executable file.

Set the `LD_LIBRARY_PATH` to the one of `libmylib.so`:
```
export LD_LIBRARY_PATH=/opt/mylib/lib
```
Run the program:
```
./test
```
## Uninstall the shared library

### Manually

Remove `/opt/mylib` and its contents.

### Using `make`

Change directory to the one containing `mylib` source files and run:
```
sudo make uninstall
```
## Build the static library

### Manually

Compile `mylib` source code `mylib.c`:
```
gcc -Wall -c -o mylib.o mylib.c
```
Create the static library:
```
ar rcs libmylib.a mylib.o
```
The static library is just an archive containing the object file.

## Install the static library

In this example, `mylib` is installed into `/opt/mylib`:
- header file is installed into `/opt/mylib/include`
- static library is installed into `/opt/mylib/lib`.

### Manually

Create the directory structure defined above and copy the header file and the
static library to their destinations.

## Use the static library

Copy the `test.c` file into `/tmp` and go to that directory.

Build `test` executable:
```
gcc test.c -I /opt/mylib/include -L /opt/mylib/lib -l mylib -o test
```
where:
- `-I` adds the specified directory to the list of directories to be searched
  for header files during preprocessing (see [Directory Options]:
  <https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/Directory-Options.html>)
- `-l` search the named library when linking (see [Link Options])
- `-L` adds the specified directory to the list of directories to be searched
  for the one specified by `-l`.

This command generates the `test` executable file.

Run the program:
```
./test
```
## Uninstall the static library

### Manually

Remove `/opt/mylib` and its contents.

