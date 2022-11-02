/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:32:31 by iortego-          #+#    #+#             */
/*   Updated: 2022/11/02 12:32:31 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	array[BUFFER_SIZE + 1];
	int		start;
}			t_buffer;

int		charge_buffer(t_buffer *buffer, int fd);
int		copy_counter(t_buffer *buffer, int cplength, int *lecture, int fd);
char	*add_to_line(char *line, t_buffer *buffer, int *total, int cplength);
char	*get_next_line(int fd);
int		ft_strcharlen(const char *str, const char sentinel);
int		ft_strncpy(char *dst, char *str, size_t size);
char	*str_realloc(char *str, size_t size);
#endif
