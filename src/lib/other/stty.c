#include <lib.h>
#include <sgtty.h>

int stty(
int fd,
struct sgttyb *argp
){
  return ioctl(fd, TIOCSETP, argp);
}
