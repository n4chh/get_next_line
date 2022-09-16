#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_buffer
{
	char	array[BUFFER_SIZE + 1];
	int		start;
}			t_buffer;

char	*get_next_line(int fd);
int		ft_strcharlen(const char *str, const char sentinel);
int		ft_strlcpy(char *dst, char *str, size_t size);
char	*ft_strchr(char *str, char sentinel);
char	*str_realloc(char *str, size_t size);
int 	ft_buffercheck(char *buffer);
#endif