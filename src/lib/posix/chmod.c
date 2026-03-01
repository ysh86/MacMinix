#include <lib.h>

PUBLIC int chmod(
_CONST char *name,
mode_t mode
){
  return(callm3(FS, CHMOD, mode, name));
}
