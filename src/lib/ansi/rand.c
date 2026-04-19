#include <lib.h>
/*  rand(3)
 *
 *  Changed to return high order bits. Terrence W. Holm, Nov. 1988
 */

static long _seed = 1L;

void srand(unsigned int x)
{
  _seed = (long) x;
}

int rand(void)
{
  _seed = 1103515245L * _seed + 12345;

  if (sizeof(int) == 2) {
    return((int) ((_seed >> 16) & 0x7fff));
  } else {
    return (int) (_seed & 0x7fffffffL);
  }
}
