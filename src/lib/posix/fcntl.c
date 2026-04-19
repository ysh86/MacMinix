#include <lib.h>
#include <fcntl.h>		/* for the proto; emphasize varargs kludge */
#include <stdarg.h>

PUBLIC int fcntl(
int fd,
int cmd,
...
){
  int barf;
  va_list arg;
  va_start(arg, cmd);
  barf = va_arg(arg, int);
  va_end(arg);
  return(callm1(FS, FCNTL, fd, cmd, barf, NIL_PTR, NIL_PTR, NIL_PTR));
}
