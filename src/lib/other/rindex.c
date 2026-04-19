#include <lib.h>
/* rindex - find last occurrence of a character in a string  */

#include <string.h>

/* found char, or NULL if none */
char *rindex(
const char *s,
char charwanted
){
  return(strrchr(s, charwanted));
}
