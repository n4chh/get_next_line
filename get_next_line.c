/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:29:56 by iortego-          #+#    #+#             */
/*   Updated: 2022/11/02 12:30:54 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	charge_buffer(t_buffer *buffer, int fd)
{
	int	lecture;

	lecture = read(fd, buffer->array, BUFFER_SIZE);
	if (lecture >= 0)
	{
		buffer->array[lecture] = 0;
		buffer->start = 0;
	}
	return (lecture);
}

int	copy_counter(t_buffer *buffer, int cplength, int *lecture, int fd)
{
	cplength = ft_strcharlen(buffer->array + buffer->start, '\n');
	if (cplength == 0)
	{
		*lecture = charge_buffer(buffer, fd);
		if (*lecture <= 0)
			return (0);
		cplength = ft_strcharlen(buffer->array + buffer->start, '\n');
	}
	return (cplength);
}

char	*add_to_line(char *line, t_buffer *buffer, int *total, int cplength)
{
	int	linestart;

	*total += cplength;
	if (cplength < 1)
		return (NULL);
	line = str_realloc(line, *total);
	if (cplength >= *total)
		linestart = 0;
	else
		linestart = *total - cplength - 1;
	if (line)
		buffer->start += ft_strncpy(line + linestart, \
				buffer->array + buffer->start, cplength + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	buffer;
	int				cplength;
	int				lecture;
	int				total;

	total = 1;
	cplength = copy_counter(&buffer, CPLENGHT_INIT, &lecture, fd);
	line = NULL;
	while (cplength > 0)
	{
		if (cplength > 0)
		{
			line = add_to_line(line, &buffer, &total, cplength);
			if (line == NULL)
				return (NULL);
			if (line[total - 2] == '\n')
				return (line);
		}
		cplength = copy_counter(&buffer, cplength, &lecture, fd);
	}
	if (lecture < 0)
		return (free(line), (char *) NULL);
	return (line);
}
