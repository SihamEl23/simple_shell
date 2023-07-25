#include "shell.h"

/**
 * _getenv - Searches the environment list to find the environment variable
 * name.
 *
 * @name: The environment variable.
 *
 * Return: returns a pointer to the corresponding value string, otherwise NULL.
 */

char *_getenv(const char *name)
{
	unsigned int i = 0;

	if (name == NULL)
		return (NULL);
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			return (environ[i] + _strlen(name) + 1);
		}
		i++;
	}
	return (NULL);
}

