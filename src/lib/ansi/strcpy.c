#include <lib.h>
/* strcpy - copy string src to dst  */

#include <string.h>

char *strcpy(
char *dst,
const char *src
){
  register char *dscan;
  register const char *sscan;

  dscan = dst;
  sscan = src;
  while ((*dscan++ = *sscan++) != '\0') continue;
  return(dst);
}
