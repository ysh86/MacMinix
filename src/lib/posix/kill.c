#include <lib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

PUBLIC int kill(
pid_t proc,		/* which process is to be sent the signal */
int sig			/* signal number */
){
  return(callm1(MM, KILL, proc, sig, 0, NIL_PTR, NIL_PTR, NIL_PTR));
}

PUBLIC int raise(
int sig
){
  return kill(getpid(), sig);
}
