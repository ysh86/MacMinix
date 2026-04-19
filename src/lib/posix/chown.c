#include <lib.h>

PUBLIC int chown(
char *name,
uid_t owner,
gid_t grp
){
  return(callm1(FS, CHOWN, len(name), owner, grp, name, NIL_PTR, NIL_PTR));
}
