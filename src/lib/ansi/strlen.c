#include <lib.h>
/* strlen - length of string (not including NUL) */

#include <string.h>

size_t strlen(
const char *s
){
  register const char *scan;
  register size_t count;

  count = 0;
  scan = s;
  while (*scan++ != '\0') count++;
  return(count);
}
