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

char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	buffer;
	int				cplength;
	int				lecture;
	int				total;

	total = 1;
	lecture = -42;
	line = NULL;
	while (lecture == -42 || (lecture > 0 && line && line[total - 2] != '\n'))
	{
		cplength = ft_strcharlen(buffer.array + buffer.start, '\n');
		total += cplength;
		line = str_realloc(line, total);
		if (line)
			buffer.start = ft_strncpy(line + total - cplength - 1, buffer.array + buffer.start, cplength + 1) - 1;
		if (buffer.start == BUFFER_SIZE || (buffer.start == 0 && buffer.array[0] == 0))
		{
			lecture = read(fd, buffer.array, BUFFER_SIZE);
			buffer.array[lecture] = '\0';
			buffer.start = 0;
		}
	}
	if (lecture < 0)
		return (free(line), (char *)NULL);
	return (line);
}
