#include <lib.h>

PUBLIC int chown(
char *name,
int owner,
int grp
){
  return(callm1(FS, CHOWN, len(name), owner, grp, name, NIL_PTR, NIL_PTR));
}
