#include <lib.h>
#include <sgtty.h>

int gtty(
int fd,
struct sgttyb *argp
){
  return(ioctl(fd, TIOCGETP, argp));
}
