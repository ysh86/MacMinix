#include <lib.h>
/* memcmp - compare bytes */

#include <string.h>

int  memcmp(
const void *s1,		/* <0, == 0, >0 */
const void *s2,
size_t size
){
  register const char *scan1;
  register const char *scan2;
  register size_t n;

  scan1 = (char *) s1;
  scan2 = (char *) s2;
  for (n = size; n > 0; n--)
	if (*scan1 == *scan2) {
		scan1++;
		scan2++;
	} else
		return(*scan1 - *scan2);

  return(0);
}
