#include "get_next_line.h"

int	ft_strchr(char *str, char sentinel)
{
	while (*str != sentinel)
		str++;
	if (*str == sentinel)
		return (1);
	return (0);
}