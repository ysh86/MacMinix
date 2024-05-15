#include <lib.h>
#include "stdio.h"

int puts(const char *s)
{
  char c;

  c = fputs(s, stdout);
  putchar('\n');
  return(c);
}
