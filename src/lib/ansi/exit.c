#include <lib.h>

void (*__cleanup) ();

void exit(int status)
{
  if (__cleanup) (*__cleanup) ();
  callm1(MM, EXIT, status, 0, 0, NIL_PTR, NIL_PTR, NIL_PTR);
}
