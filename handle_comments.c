#include "shell.h"

/**
 * handle_comments - Handle comments if they occur in a command line.
 *
 * @args: A double pointer to an array of strings representing
 * the command and its arguments.
 *
 * Return: void.
 */

void handle_comments(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '#')
		{
			args[i] = NULL;
			break;
		}
	}
}

