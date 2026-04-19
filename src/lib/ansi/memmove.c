/* memmove.c */
/* Moves a block of memory (safely). */
/* Calls memcpy(), so memcpy() had better be safe. */
/* Henry Spencer's routine is fine. */

#include <string.h>

void *memmove(
void *s1,
const void *s2,
size_t n
){
  return memcpy(s1, s2, n);
}
