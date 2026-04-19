#include <lib.h>
/*  getenv(3)
 *
 *  Author: Terrence W. Holm          Aug. 1988
 */

#include <stddef.h>
#include <stdlib.h>

extern char **environ;

char *getenv(const char *name)
{
  char **v;
  const register char *n;
  register char *p;

  if (environ == (char **) NULL || name == (char *)NULL) return((char *)NULL);

  for (v = environ; *v != (char *)NULL; ++v) {
	n = name;
	p = *v;

	while (*n == *p && *n != '\0') ++n, ++p;

	if (*n == '\0' && *p == '=') return(p + 1);
  }

  return((char *)NULL);
}
