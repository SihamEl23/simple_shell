#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 *
 * @s: Pointer to the string whose length is to be calculated.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
	size_t len_s = 0;

	while (s[len_s] != '\0')
		len_s++;
	return (len_s);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @s: Pointer to the null-terminated string to search.
 * @c: The character to be located.
 *
 * Return: Pointer to the first occurrence of the character,
 *         or NULL if not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}

	if ((char)c == '\0')
		return ((char *)s);

	return (NULL);
}

/**
 * _memcpy - Copies memory area.
 *
 * @dest: Pointer to the destination memory.
 * @src: Pointer to the source memory.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strcpy - Copies a string from source to destination.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: An integer less than, equal to, or greater
 * than zero if @s1 is found to be less than,
 *         equal to, or greater than @s2, respectively.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, cmp = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		cmp = s1[i] - s2[i];
		if (cmp != 0)
			break;
		i++;
	}
	return (cmp);
}

