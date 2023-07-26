#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: The number of command line arguments (unused).
 * @av: An array of command line argument strings (unused).
 *
 * Return: Always returns 0.
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t size_buffer = 0;
	char **args;
	int i = 0, status = 0;
	(void)ac, (void)av;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		read_input(&buffer, &size_buffer, stdin);
		args = tokenize_buffer(buffer, size_buffer, i);
		if (args == NULL)
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		if (_strcmp(args[0], "echo") == 0 && args[1] != NULL &&
		   (_strcmp(args[1], "$$") == 0 ? (p_num(getpid()), p_ch('\n'), 1) :
		    _strcmp(args[1], "$?") == 0 ? (p_num(status), p_ch('\n'), 1) :
		    _strncmp(args[1], "$", 1) == 0 ? (p_var(args), p_ch('\n'), 1) : 0))
		{
			free(args);
			args = NULL;
			i = 0;
			continue;
		}
		myExitFunction(args, buffer);
		execute_command(args);
		free(args);
		args = NULL;
		i = 0;
	}
	free(buffer);
	buffer = NULL;
	return (0);
}

