#include <lib.h>

PUBLIC int stime(long *top)
{
  _M.m2_l1 = *top;
  return(callx(FS, STIME));
}
