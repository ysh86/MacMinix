#include <lib.h>
#include <stddef.h>

time_t time(time_t *tp)
{
  int k;
  time_t l;
  k = callm1(FS, TIME, 0, 0, 0, NIL_PTR, NIL_PTR, NIL_PTR);
  if (_M.m_type < 0 || k != 0) {
	errno = -_M.m_type;
	return(-1L);
  }
  l = _M.m2_l1;
  if (tp != (time_t *) NULL) *tp = l;
  return(l);
}
