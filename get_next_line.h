#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list 
{
	void			*content;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
int		ft_strcharlen(const char *str, const char sentinel);
int		ft_strlcpy(char *dst, char *str, size_t size);
char	*ft_strchr(char *str, char sentinel);
char	*str_realloc(char *str, size_t size);
int 	ft_buffercheck(char *buffer);
#endif