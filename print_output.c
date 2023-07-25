#include "shell.h"

/**
 * p_ch - Writes a single character to the standard output.
 *
 * @c: The character to be written.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int p_ch(char c)
{
	return (write(1, &c, 1));
}

/**
 * p_num - Prints an integer to the standard output.
 *
 * @n: The integer to be printed.
 *
 * Return: void
 */
void p_num(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		p_ch('-');
		num = -num;
	}

	if ((num / 10) > 0)
		p_num(num / 10);

	p_ch((num % 10) + '0');
}

/**
 * p_var - Prints the value of an environment variable.
 *
 * @args: Double pointer to an array of strings representing
 *        the command and its arguments.
 *
 * Return: void
 */
void p_var(char **args)
{
	char *var_name = args[1] + 1;
	char *path_variable;
	size_t len;

	path_variable = _getenv(var_name);
	if (path_variable != NULL)
	{
		len = _strlen(path_variable);
		write(1, path_variable, len);
	}
}

/**
 * myExitFunction - Exits the program gracefully.
 *
 * @args: Double pointer to an array of strings representing
 *        the command and its arguments.
 *
 * @buffer: Pointer to a buffer that needs to be freed before exiting.
 *
 * Return: void
 */
void myExitFunction(char **args, char *buffer)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free(buffer);
		buffer = NULL;
		free(args);
		args = NULL;
		exit(EXIT_SUCCESS);
	}
}

