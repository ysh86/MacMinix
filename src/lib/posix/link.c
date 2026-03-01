#include <lib.h>

PUBLIC int link(
_CONST char *name,
_CONST char *name2
){
  return(callm1(FS, LINK, len(name), len(name2), 0,
	 (char *) name, (char *) name2,	/* perhaps callm1 preserves these */
	 NIL_PTR));
}
