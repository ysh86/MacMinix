#include <lib.h>

PUBLIC int read(
int fd,
char *buffer,
size_t nbytes
){
  return(callm1(FS, READ, fd, nbytes, 0, buffer, NIL_PTR, NIL_PTR));
}
