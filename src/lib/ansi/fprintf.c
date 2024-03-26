#include <lib.h>
#include <stdarg.h>
#include <stdio.h>

void fprintf(
FILE *file,
const char *fmt,
...
){
  va_list args;
  va_start(args, fmt);
  _doprintf(file, fmt, args);
  va_end(args);
  if (testflag(file, PERPRINTF)) fflush(file);
}


void printf(
const char *fmt,
...
){
  va_list args;
  va_start(args, fmt);
  _doprintf(stdout, fmt, args);
  va_end(args);
  if (testflag(stdout, PERPRINTF)) fflush(stdout);
}
