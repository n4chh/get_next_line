#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
  register int        fd;                                       
  register char   *ptr;                               
  fd = open("prueba.txt", O_RDONLY); 
  do {
    write(0, "ent\n", 5);
    ptr = get_next_line(fd);
    write(1, ptr, 1000);
    write (1, "hola", 4);
  } while (ptr != (char *)NULL && ptr[0] != 0);
  close (fd);                                                   
  return (0);                                                   
}
