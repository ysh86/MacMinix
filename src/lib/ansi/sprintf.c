#include <lib.h>
#include <stdarg.h>
#include <stdio.h>

char *sprintf(
char *buf,
const char *format,
...
){
  FILE _tempfile;
  va_list args;

  _tempfile._fd = -1;
  _tempfile._flags = WRITEMODE + STRINGS;
  _tempfile._buf = buf;
  _tempfile._ptr = buf;

  va_start(args, format);
  _doprintf(&_tempfile, format, args);
  va_end(args);
  putc('\0', &_tempfile);

  return(buf);
}
