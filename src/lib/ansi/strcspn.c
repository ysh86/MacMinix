#include <lib.h>
/* strcspn - find length of initial segment of s consisting entirely
 * of characters not from reject
 */

#include <string.h>

size_t strcspn(
const char *s,
const char *reject
){
  register const char *scan;
  register const char *rscan;
  register size_t count;

  count = 0;
  for (scan = s; *scan != '\0'; scan++) {
	for (rscan = reject; *rscan != '\0';)	/* ++ moved down. */
		if (*scan == *rscan++) return(count);
	count++;
  }
  return(count);
}
