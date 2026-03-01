#include <lib.h>
#include <sys/stat.h>

PUBLIC int stat(
_CONST char *name,
struct stat *buffer
){
  return(callm1(FS, STAT, len(name), 0, 0,
  		(char *)name, (char *)buffer, NIL_PTR));
}
