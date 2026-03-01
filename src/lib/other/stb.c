#include <lib.h>
 /* library routine for copying structs with unpleasant alignment */

void __stb(
register char *f,
register char *t,
register int n
){
  if (n > 0) do
		*t++ = *f++;
	while (--n);
}
