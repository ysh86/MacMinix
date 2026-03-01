#include <lib.h>

PUBLIC int mount(
char *name,
char *special,
int rwflag
){
  return(callm1(FS, MOUNT, len(special), len(name), rwflag, special, name, NIL_PTR));
}
