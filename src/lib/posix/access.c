#include <lib.h>

PUBLIC int access(
char *name,
int mode
){
  return(callm3(FS, ACCESS, mode, name));
}
