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

char	*get_nex_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			cplength;
	int			lecture;
	int			total;

	total = 1;
	line = NULL;
	while (total == 1 || line && lecture && cplenght)
	{
		cplength = ft_strcharlen(buffer, '\n');
		if (!cplenght) {
			lecture = read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = 0;
		}
		else
			buffer[BUFFER_SIZE] += cplength;
		line = str_realloc(line, total);
		if (line)
			ft_strlcpy(line, buffer + buffer[BUFFER_SIZE], cplenght + 1);
	}
	if (lecture < 0)
		return (NULL);
	return (line);
}
