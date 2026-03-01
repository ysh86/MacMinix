#include <lib.h>

PUBLIC int dup2(int fd, int fd2)
{
  return(callm1(FS, DUP, fd + 0100, fd2, 0, NIL_PTR, NIL_PTR, NIL_PTR));
}
