#include <lib.h>
/* strcat - append string src to  */

#include <string.h>

char *strcat(
char *dst,
const char *src
){
  register char *dscan;
  register const char *sscan;

  for (dscan = dst; *dscan != '\0'; dscan++) continue;
  sscan = src;
  while ((*dscan++ = *sscan++) != '\0') continue;
  return(dst);
}
