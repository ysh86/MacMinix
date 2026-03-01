#include <lib.h>

PUBLIC int creat(
_CONST char *name,
mode_t mode
){
  return(callm3(FS, CREAT, mode, name));
}
