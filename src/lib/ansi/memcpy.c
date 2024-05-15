#include <lib.h>
/* memcpy - copy bytes */

#include <string.h>

void *memcpy(
void *dst,
const void *src,
size_t size
){
  register char *d;
  register const char *s;
  register size_t n;

  if (size <= 0) return(dst);

  s = (char *) src;
  d = (char *) dst;
  if (s <= d && s + (size - 1) >= d) {
	/* Overlap, must copy right-to-left. */
	s += size - 1;
	d += size - 1;
	for (n = size; n > 0; n--) *d-- = *s--;
  } else
	for (n = size; n > 0; n--) *d++ = *s++;

  return(dst);
}
