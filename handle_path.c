#include "shell.h"

/**
 * handle_path - Handle the path of a command line.
 *
 * @com: A pointer to string representing the command line.
 *
 * Return: returns the full path of the command, or NULL on failure.
 */
char *handle_path(char *com)
{
	char *value = _getenv("PATH");
	char *token, *full_path;
	struct stat st;

	token = strtok(value, ":");
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(com) + 2);
		if (full_path == NULL)
		{
			return (NULL);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, com);
		if (stat(full_path, &st) == 0)
			return (full_path);
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

