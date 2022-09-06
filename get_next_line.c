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
//
// STATIC:	Una variable estática solo se inicializa una vez al comienzo de la ejecución del programa (0 por defecto).
//			Pueden definirse tanto fuera como dentro de una función y estarán definidas por tanto dentro
//			del bloque de código que pertenezcan y permanecerán activas hasta que acabe el programa.

char	*get_nex_line(int fd)
{
	char	*line;
	static char	*buffer[BUFFER_SIZE];

	while ()
	{
		if (read(fd, buffer, BUFFER_SIZE) >= 0)
		{

			ft_strlcpy(line, buffer, ft_strcharlen(buffer, '\n') + 1);
		}
		else
			return (NULL);
	}
}
char	*gnl(int fd, int )

int		buffer_charge(int fd)
{
}