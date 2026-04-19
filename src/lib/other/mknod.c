#include <lib.h>

PUBLIC int mknod(
char *name,
int mode,
int addr,
unsigned int size
){
  return(callm1(FS, MKNOD, len(name), mode, addr, name, (char*)size, NIL_PTR));
}
