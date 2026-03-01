#include <mac/Events.h>
#include <mac/Other.h>

/*
 * NOT IN ROM Routines.
 */

void FlushEvents(
short emask,
short smask
){
  unsigned long mask = smask & 0xFFFF;
  mask <<= 16;
  mask |= (emask & 0xFFFF);
  _FlushEvents_(mask);
}

QHdrPtr GetEvQHdr()
{
  extern QHdr EventQueue;
  return &EventQueue;
}

void SetEventMask(short theMask)
{
  extern short SysEvtMask;
  SysEvtMask = theMask;
}
