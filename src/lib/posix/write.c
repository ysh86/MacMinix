#include <lib.h>

PUBLIC int write(
int fd,
char *buffer,
size_t nbytes
){
  unsigned short lo, hi;
  lo = nbytes & 0xffff;
  hi = nbytes >> 16;
  return(callm1(FS, WRITE, fd, lo, hi, buffer, NIL_PTR, NIL_PTR));
}
