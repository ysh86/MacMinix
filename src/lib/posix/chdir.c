#include <lib.h>

PUBLIC int chdir(char *name)
{
  return(callm3(FS, CHDIR, 0, name));
}
