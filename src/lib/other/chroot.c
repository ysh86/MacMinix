#include <lib.h>

#include <unistd.h>

PUBLIC int chroot(_CONST char *name)
{
  return(callm3(FS, CHROOT, 0, name));
}
