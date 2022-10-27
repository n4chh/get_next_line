#include "get_next_line.h"

//
// VALORES QUE DEVUELVE:
//							- Puntero al primer elemento de la línea que tiene que terminar con un '\n'
//							- NULL si:
//										- No hay nada más que leer
//										- Hay algún error
//
// BUFFER:	El buffer carga cierto tamaño, así nos evitamos tener que trabajar desde el archivo 
//			y podemos trabajar desde la memoria del programa lo cual es más rápido.
//			El buffer será estático para que guarde los caracteres que siguen a un '\n' cuando este está en medio de
//			una entrada en el buffer
//
// STATIC:	Una variable estática solo se inicializa una vez al comienzo de la ejecución del programa (0 por defecto).
//			Pueden definirse tanto fuera como dentro de una función y estarán definidas por tanto dentro
//			del bloque de código que pertenezcan y permanecerán activas hasta que acabe el programa.
int 	charge_buffer(t_buffer *buffer, int fd)
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

char 	*add_to_line(char *line, t_buffer *buffer, int *total, int cplength)
{
	int linestart;

	*total += cplength;
	line = str_realloc(line, *total);
	if (cplength >= *total)
		linestart = 0;
	else
		linestart = *total - cplength - 1;
	if (line)
		buffer->start += ft_strncpy(line + linestart, buffer->array + buffer->start, cplength + 1);
	return (line);
}
int	copy_counter(t_buffer *buffer, int cplength, int *lecture, int fd)
{
	cplength = ft_strcharlen(buffer->array + buffer->start, '\n');
	if (cplength == 0)
	{
		*lecture = charge_buffer(buffer, fd);
		cplength = ft_strcharlen(buffer->array + buffer->start, '\n');
	}
	return (cplength);
}
char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	buffer;
	int				cplength;
	int				lecture;
	int				total;

	total = 1;
	cplength = copy_counter(&buffer, 42, &lecture, fd);
	line = NULL;
	while (cplength > 0)
	{
		if (lecture > 0 && cplength > 0)
		{
			line = add_to_line(line, &buffer, &total, cplength);
			if (line == NULL)
				return (NULL);
			if (line[total - 2] == '\n')
				cplength = 0;
		}
		if (cplength > 0)
			cplength = copy_counter(&buffer, cplength, &lecture, fd);
	}
	if (lecture < 0)
		return (free(line), (char *)NULL);
	return (line);
}
