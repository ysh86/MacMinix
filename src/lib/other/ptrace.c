#include <lib.h>

PUBLIC long ptrace(
int req, pid_t pid,
long addr, long data
){
  _M.m2_i1 = pid;
  _M.m2_i2 = req;
  _M.m2_l1 = addr;
  _M.m2_l2 = data;
  if (callx(MM, PTRACE) == -1) return(-1L);
  if (_M.m2_l2 == -1) {
	errno = 0;
	return(-1L);
  }
  return(_M.m2_l2);
}
