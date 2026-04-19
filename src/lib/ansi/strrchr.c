#include <lib.h>
/* strrchr - find last occurrence of a character in a string */

#include <string.h>

char *strrchr(		/* found char, or NULL if none */
const char *s,
int charwanted
){
  register const char *scan;
  register const char *place;

  place = (char *) NULL;
  for (scan = s; *scan != '\0'; scan++)
	if (*scan == charwanted) place = scan;
  if (charwanted == '\0') return ((char *) scan);
  return((char *) place);
}
