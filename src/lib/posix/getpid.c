#include <lib.h>

PUBLIC pid_t getpid()
{
  return(callm1(MM, GETPID, 0, 0, 0, NIL_PTR, NIL_PTR, NIL_PTR));
}
