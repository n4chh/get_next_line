#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  register int        fd;
  register char   *ptr;
  int   count;
  count = 0;

  fd = open("prueba.txt", O_RDONLY);
  do {
      
    printf("linea %d:\n", count);
    ptr = get_next_line(fd);
    write(1, ptr, ft_strcharlen(ptr, 0));
    write (1, "\n",1);
    count++;
  } while (ptr != (char *)NULL);
  close (fd);
  return (0);
}
