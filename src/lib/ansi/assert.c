/* assert.c - diagnostics */

#include <lib.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* ANSI version */
void __bad_assertion(
const char *expr,
const char *file,
int line
){
  fprintf(stderr,"Assertion \"%s\" failed, file \"%s\", line %d\n", 
							expr, file, line);
  abort();
}
