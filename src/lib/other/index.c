#include <lib.h>
/* index - find first occurrence of a character in a string */

#include <string.h>

char *index(	/* found char, or NULL if none */
const char *s,
char charwanted
){
  return(strchr(s, charwanted));
}
