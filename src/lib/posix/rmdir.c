#include <lib.h>

PUBLIC int rmdir(_CONST char *name)
{
  return(callm3(FS, RMDIR, 0, name));
}
