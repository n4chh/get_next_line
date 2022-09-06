#include "get_next_line.h"

//
// VALORES QUE DEVUELVE:
//							- Puntero al primer elemento de la linea que tiene que terminar con un ' \n'
//							- NULL si:
//										- No hay nada mas que leer	
//										- Hay algún error
//
// BUFFER:	El buffer carga cierto tamaño, así nos evitamos tener que trabajar desde el archivo 
//			y podemos trabajar desde la memoria del programa lo cual es mas rapido.
//
// STATIC:	Una variable estática solo se inicializa una vez al comienzo de la ejecucion del programa (0 por defecto).
//			Pueden definirse tanto fuera como dentro de una función y estaran definidas portanto dentro
//			del bloque de codigo que pertenezcan y permanecerán activas hasta que acabe el programa.

char	*get_nex_line(int fd)
{
	char	*line;
	static char	*buffer[BUFFER_SIZE];

	while (buffer != )

}
char *gnl(int fd, int )

int		next_line(int	fd)