#include <lib.h>
#include <sys/types.h>
#include <sys/stat.h>

PUBLIC int mkfifo(
_CONST char *name,
mode_t mode
){
  mode = (mode & 0777) | S_IFIFO;
  return(callm1(FS, MKNOD, len(name), (int)mode, 0,
	 (char *)name, NIL_PTR, NIL_PTR));
}
