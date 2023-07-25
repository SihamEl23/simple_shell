#include "shell.h"

/**
 * _strtok - Tokenizes a string into tokens using specified delimiters.
 *
 * @str: The string to be tokenized.
 * @delims: The delimiters used to separate the tokens.
 *
 * Return: Pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char str[], const char *delims)
{
	char *token = NULL;
	static char *next_str;
	int i = 0, len = 0;

	if (!delims)
		return (NULL);
	if (!str && next_str)
		str = next_str;
	if (!str || *str == '\0')
		return (NULL);

	len = _strlen(str);
	while (i < len && _strchr(delims, str[i]))
		i++;

	str += i;
	if (*str == '\0')
	{
		next_str = NULL;
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (_strchr(delims, str[i]))
		{
			str[i] = '\0';
			token = str;
			next_str = str + i + 1;
			return (token);
		}
	}

	next_str = NULL;
	return (token);
}

