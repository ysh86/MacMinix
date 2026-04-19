#include <lib.h>
#include <stdarg.h>
#include <stdio.h>

char *vsprintf(
char *buf,
const char *format,
void *argp
){
  FILE _tempfile;

  _tempfile._fd = -1;
  _tempfile._flags = WRITEMODE + STRINGS;
  _tempfile._buf = buf;
  _tempfile._ptr = buf;

  vfprintf(&_tempfile, format, argp);
  putc('\0', &_tempfile);

  return(buf);
}


int vfprintf(
FILE *file,
const char *fmt,
void *args
){
  _doprintf(file, fmt, args);
  if (testflag(file, PERPRINTF)) fflush(file);
  return 0;  /* WRONG, but a right way requires _doprintf to return the length output */
}
