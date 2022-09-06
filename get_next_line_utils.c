#include "get_next_line.h"

int	ft_strchr(char *str, char sentinel)
{
	while (*str != sentinel)
		str++;
	if (*str == sentinel)
		return (1);
	return (0);
}

int	ft_strcharlen(const char *str,const char sentinel)
{
	char	*s;

	s = (char *)str;
	while (*s != sentinel && *s != 0)
		s++;
	return (s - str);
}

int	ft_strlcpy(char *dst, char *str, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count] != 0 && size > count + 1)
	{
		dst[count] == src[count];
		count++;
	}
	return (ft_strcharlen(str, 0));
}