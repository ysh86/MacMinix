#include <lib.h>
#include <stdio.h>

size_t fwrite(
const void *ptrfix,
size_t size,
size_t count,
FILE *file
){
  size_t s;
  size_t ndone = 0;
  const char *ptr = (char *) ptrfix;

  if (size) while (ndone < count) {
		s = size;
		do {
			putc(*ptr++, file);
			if (ferror(file)) return(ndone);
		}
		while (--s);
		ndone++;
	}
  return(ndone);
}
