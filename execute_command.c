#include "shell.h"

/**
 * execute_command - Executes a command in a child process,
 *                   handling comments and errors.
 * @args: A double pointer to an array of strings representing
 *        the command and its arguments.
 *
 * Return: void
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd, *error_message1, *error_message2;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		handle_comments(args);
		cmd = handle_path(args[0]);
		if (cmd)
			execve(cmd, args, environ);
		else if (execve(args[0], args, environ) == -1)
		{
			error_message1 = "bash: ";
			write(2, error_message1, _strlen(error_message1));
			write(2, args[0], _strlen(args[0]));
			error_message2 = ": command not found\n";
			write(2, error_message2, _strlen(error_message2));
		}
	}
	else
	{
		wait(&status);
	}
}

