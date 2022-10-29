#include "get_next_line.h"

// This version always allocates memory with BUFFER_SIZE's size, does not realize if there is a \n or not.
// That allows us to reduce the times we execute the strlen function, because is the same copy function the
// one which detects when does it need to stop.



static char *copy_till_n(t_buffer *buffer, char *line)
{
	char	*newline;
	int		count;

	newline = str_realloc(line, BUFFER_SIZE);
	while (newline != 0)
		newline++;
	while (buffer->array[count + buffer->start] != 0 \
			&& buffer->array[count + buffer->start] != '\n')
	{
		newline[count] = buffer.array[count];
		
	}
	return (newline);
}
char	*get_next_line(int fd)
{
	t_buffer buffer;

}
