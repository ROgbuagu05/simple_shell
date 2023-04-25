#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
  info_t info[] = { INFO_INIT };
  int fd = 2;

  fd = 2;

  if (ac == 2)
  {
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
      if (errno == EACCES)
        exit(126);
      if (errno == ENOENT)
      {
        puts(av[0]);
        puts(": 0: Can't open ");
        puts(av[1]);
        putchar(' ');
      }
      return (1);
    }
  }

  /* using the info variable */
  int i;
  for (i = 0; i < sizeof(info)/sizeof(info_t); i++)
  {
    puts(info[i].fname);
  }

  return (0);
}

