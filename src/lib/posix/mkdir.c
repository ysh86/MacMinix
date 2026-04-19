#include <lib.h>

PUBLIC int mkdir(
char *name,
mode_t mode
){
  return(callm1(FS, MKDIR, len(name), mode, 0, name, NIL_PTR, NIL_PTR));
}
