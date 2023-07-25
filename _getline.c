#include "shell.h"

/**
 * _getline - Reads a line from a file stream and stores it in a buffer.
 *
 * @lineptr: Double pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: the number of characters read, or -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE], *new_buffer;
	ssize_t read_bytes = 0;
	ssize_t read_char = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while ((read_bytes = read(stream->_fileno, buffer, BUFFER_SIZE)) != -1)
	{
		if (read_char >= (ssize_t)*n)
		{
			*n += BUFFER_SIZE;
			new_buffer = _realloc(*lineptr, *n);
			if (new_buffer == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = new_buffer;
		}

		_memcpy(*lineptr + read_char, buffer, read_bytes);
		read_char += read_bytes;

		if (read_bytes == 0 || buffer[read_bytes - 1] == '\n'
			|| buffer[read_bytes - 1] == EOF)
			break;
	}

	if (read_char == 0)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}

	(*lineptr)[read_char] = '\0';
	return (read_char);
}

