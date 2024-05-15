/* strcoll.c */
/* Compares the strings s1 and s2 in light of the current locale setting */
/* WARNING: This is a bogus implementation, since I have no idea what	 */
/*          ANSI is prattling about with respect to locale.              */

#include <string.h>

int strcoll(
const char *s1,
const char *s2
){
  return strcmp(s1, s2);
}
