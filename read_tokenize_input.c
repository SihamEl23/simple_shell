#include "shell.h"

/**
 * read_input - Reads input from a file stream and stores it in a buffer.
 *
 * @buf: Double pointer to a pointer that will store the input buffer.
 * @size_buf: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: void
 */

void read_input(char **buf, size_t *size_buf, FILE *stream)
{
	ssize_t read_char = 0;

	read_char = _getline(buf, size_buf, stream);
	if (read_char == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
}

/**
 * tokenize_buffer - Tokenizes a buffer into an array of strings.
 *
 * @buffer: Pointer to the buffer to be tokenized.
 * @size_buffer: Size of the buffer.
 * @i: Initial index for storing tokens in the arguments array.
 *
 * Return: Double pointer to an array of strings containing the tokens.
 */

char **tokenize_buffer(char *buffer, size_t size_buffer, int i)
{
	char *tokens = NULL;
	char **args = NULL;

	tokens = _strtok(buffer, " \t\n");
	if (tokens == NULL)
		return (NULL);

	args = malloc((size_buffer + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (tokens != NULL)
	{
		args[i++] = tokens;
		tokens = _strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return (args);
}

