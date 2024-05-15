#include <lib.h>
#include <stdio.h>

int fputs(
const char *s,
FILE *file
){
  while (*s) putc(*s++, file);
  return(ferror(file));
}
