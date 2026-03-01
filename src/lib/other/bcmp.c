#include <lib.h>
/* bcmp - Berklix equivalent of memcmp  */

#include <string.h>

/* == 0 or != 0 for equality and inequality */ 
int bcmp(
_CONST char *s1,
_CONST char *s2,
int length
){
  return(memcmp((_CONST _VOIDSTAR) s1, (_CONST _VOIDSTAR) s2, (_SIZET) length));
}
