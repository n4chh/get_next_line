#include "get_next_line.h"

int	ft_strcharlen(const char *str, const char sentinel)
{
	char	*s;

	s = (char *)str;
	while (*s != sentinel && *s != 0)
		s++;
	if (*s == sentinel)
		s++;
	return ((int)(s - str));
}

int	ft_strncpy(char *dst, char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count] != 0 && size > count + 1)
	{
		dst[count] = src[count];
		count++;
	}
	if (size != 0)
		dst[count] = 0;
	return (size);
}

char	*str_realloc(char *str, size_t size)
{
	char	*astr;

	astr = (char *)malloc(size * sizeof(char));
	if (str && astr)
	{
		ft_strncpy(astr, str, size);
		free(str);
		str = NULL;
	}
	return (astr);
}
