#include <lib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>

PUBLIC int open(
const char *name,
int flags,
...
){
  if (flags & O_CREAT) {
		mode_t mode;
		va_list argp;
		va_start(argp, flags);
		mode = va_arg(argp, mode_t);
		va_end(argp);
		return callm1(FS, OPEN, len(name), flags, mode,
		      (char *)name, NIL_PTR, NIL_PTR);
  }
  return(callm3(FS, OPEN, flags, name));
}
