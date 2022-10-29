#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  register int        fd;
  register char   *ptr;
  int   count;
  count = 0;

  fd = open("gnl_lotr.txt", O_RDONLY);
  //fd = open("prueba.txt", O_RDONLY);
  // fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
  do {
      
    //write(1, "linea ", 6);
    ptr = get_next_line(fd);
    if (ptr != NULL)
      write(1, ptr, ft_strcharlen(ptr, 0));
    else 
      write(1, "NULL", 4);
    count++;
  } while (ptr != (char *)NULL);
  close (fd);
  return (0);
}
