#include <stdio.h>

typedef struct
{
  int x, y;
} Foo;

typedef union {
  unsigned char x, y;
  unsigned short z;
} Bar;

typedef struct {
  Bar bar;
  double d;
} Baz;

typedef union {
  unsigned int x: 2, y: 3, z: 3;
  unsigned short w; 
} Sprot;

int main(void)
{
  Foo foo = {10, 20};
  printf("Foo(x=%d, y=%d)\n", foo.x, foo.y);
  printf("- size of foo.x: %lu\n", sizeof(foo.x));
  printf("- size of foo.y: %lu\n", sizeof(foo.y));

  Bar bar;
  bar.z = 65535;
  printf("Bar(x=%u, y=%u, z=%u)\n", bar.x, bar.y, bar.z);
  printf("- size of bar.x: %lu\n", sizeof(bar.x));
  printf("- size of bar.y: %lu\n", sizeof(bar.y));
  printf("- size of bar.z: %lu\n", sizeof(bar.z));

  Baz baz;
  baz.bar = bar;
  baz.d = 543.234;
  printf("Baz(bar=Bar(x=%uc, y=%uc, z=%u), d=%f)\n", baz.bar.x, baz.bar.y, baz.bar.z, baz.d);
  printf("- size of baz.bar.x: %lu\n", sizeof(baz.bar.x));
  printf("- size of baz.bar.y: %lu\n", sizeof(baz.bar.y));
  printf("- size of baz.bar.z: %lu\n", sizeof(baz.bar.z));
  printf("- size of baz.d: %lu\n", sizeof(baz.d));

  Sprot sprot;
  sprot.w = 65535;
  printf("Sprot(x=%u, y=%u, z=%u, w=%u)\n", sprot.x, sprot.y, sprot.z, sprot.w);

  return 0;
}
