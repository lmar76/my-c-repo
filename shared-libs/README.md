# Example of how to build a share library and how to use it

## Build the shared library

Build `mylib` shared library.

```
make
```

The command generates:

- object file: `mylib.o`
- shared library: `libmylib.so`

in the current directory.

## Install the shared library

Install `mylib` shared library:

```
sudo make install
```

The command creates the following files:

- `/opt/mylib/include/mylib.h`
- `/opt/mylib/lib/libmylib.so`

## Use the shared library

Create a `test.c` file in a separate directory, i.e. not the one containing
`mylib` source files, with this contents:

```c
#include <stdio.h>

#include "mylib.h"

int main()
{
  int num1 = 2;
  int num2 = 3;
  printf("Sum of %d and %d is: %d\n", num1, num2, sum(num1, num2));
  return 0;
}
```

Build `test` executable:

```
gcc -o test -I /opt/mylib/include -L /opt/mylib/lib -l mylib test.c
```

Set the `LD_LIBRARY_PATH`:

```
export LD_LIBRARY_PATH=/opt/mylib/lib
```

Run the program:

```
./test
```

## Uninstall the shared library

Change directory to the one containing `mylib` sourc files and run:

```
sudo make uninstall
```

