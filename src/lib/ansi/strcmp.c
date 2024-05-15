#include <lib.h>
/* strcmp - compare string s1 to s2 */

#include <string.h>

int  strcmp(			/* <0 for <, 0 for ==, >0 for > */
const char *s1,
const char *s2
){
  register const char *scan1;
  register const char *scan2;

  scan1 = s1;
  scan2 = s2;
  while (*scan1 != '\0' && *scan1 == *scan2) {
	scan1++;
	scan2++;
  }

  /* The following case analysis is necessary so that characters which
   * look negative collate low against normal characters but high
   * against the end-of-string NUL. */
  if (*scan1 == '\0' && *scan2 == '\0')
	return(0);
  else if (*scan1 == '\0')
	return(-1);
  else if (*scan2 == '\0')
	return(1);
  else
	return(*scan1 - *scan2);
}
