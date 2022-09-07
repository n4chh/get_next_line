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
	if (*s == sentinel)
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
	if (size != 0)
		dst[count] = 0;
	return (ft_strcharlen(str, 0));
}

char	*str_realloc(char *str, size_t size)
{
	char	*astr;

	astr = (char *)malloc(size * sizeof(char));
	if (astr && str)
	{
		ft_strslcpy(astr, str, size, 0);
		free(str);
		str = NULL;
	}
	return (astr)
}