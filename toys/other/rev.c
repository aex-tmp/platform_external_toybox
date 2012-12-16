/* rev.c - reverse lines of a set of given input files
 *
 * Copyright 2012 Elie De Brauwer <eliedebrauwer@gmail.com>

USE_REV(NEWTOY(rev, NULL, TOYFLAG_USR|TOYFLAG_BIN))

config REV
  bool "rev"
  default y
  help
    usage: rev [FILE...]

    Output lines reversed, when no files are given stdin is used.
*/

#include "toys.h"

void do_rev(int fd, char *name)
{
  char *c;

  for (;;) {
    int len;
    int i;
    if (!(c = get_line(fd))) break;
    len = strlen(c) - 1;
    i = 0;
    while ( i <= len/2)
    {
      char tmp;
      tmp = c[i];
      c[i] = c[len-i];
      c[len-i] = tmp;
      i++;
    }
    xputs(c);
    free(c);
  }
}

void rev_main(void)
{
  loopfiles(toys.optargs, do_rev);
}
