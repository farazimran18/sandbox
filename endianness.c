#include <stdio.h>

union {
  unsigned char c[4];
  unsigned int i;
} u;

void print_bytes() {
  printf("u.c = {");
  char const *delim = "";

  for (int i = 0; i < 4; i++) {
    printf("%s%02x", delim, u.c[i]);
    delim = ", ";
  }

  puts("}");
}

int main() {
  printf("The size of u is [%lu]\n", sizeof(u));

  for (int i = 0; i < 4; i++) {
    u.c[i] = 0;
  }

  u.i = 0xBEEFCAFE;
  print_bytes();

  return 0;
}

/*
Bit Numbers:   31       24  23       16  15       8  7       0
Bytes:         0xBE         0xEF         0xCA        0xFE

On a little-endian system, the least significant byte is stored first in memory.
For example, if &u is 0x601030, the memory layout would look like this:

0x601030:  0xFE
0x601031:  0xCA
0x601032:  0xEF
0x601033:  0xBE

On a big-endian system, the most significant byte is stored first in memory.
The memory layout would look like this:

0x601030:  0xBE
0x601031:  0xEF
0x601032:  0xCA
0x601033:  0xFE

*/
