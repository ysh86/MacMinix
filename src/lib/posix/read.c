#include <lib.h>

PUBLIC int read(
int fd,
char *buffer,
size_t nbytes
){
  unsigned short lo, hi;
  lo = nbytes & 0xffff;
  hi = nbytes >> 16;
  return(callm1(FS, READ, fd, lo, hi, buffer, NIL_PTR, NIL_PTR));
}
