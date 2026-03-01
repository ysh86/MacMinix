#include <lib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

extern void syserr(const char *);

typedef enum {
  False, True
} BOOLEAN;

#define LOCKDIR "/tmp/"		/* or /usr/tmp/ as the case may be */
#define MAXTRIES 3
#define NAPTIME (unsigned int)5

PRIVATE _PROTOTYPE( char *lockpath, (char *name));

/* acquire lock */
BOOLEAN lock(char *name)
{
  char *path;
  int fd, tries;

  path = lockpath(name);
  tries = 0;
  while ((fd = creat(path, 0)) == -1 && errno == EACCES) {
	if (++tries >= MAXTRIES) return(False);
	sleep(NAPTIME);
  }
  if (fd == -1 || close(fd) == -1) {
	fprintf(stderr, "lock failed\n");
	exit(1);
  }
  return(True);
}

/* free lock */
void unlock(char *name)
{
  if (unlink(lockpath(name)) == -1) syserr("unlock");
}

/* generate lock file path */
PRIVATE char *lockpath(char *name)
{
  PRIVATE char path[20];

  strcpy(path, LOCKDIR);
  return(strcat(path, name));
}
