#include "shell.h"

/**
 * _strncmp - Compare two strings up to a maximum number of characters.
 *
 * @str1: Pointer to the first string.
 * @str2: Pointer to the second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less
 * than, equal to, or greater than zero, depending on whether
 * the first n characters of str1 are less
 * than, equal to, or greater than the first n
 * characters of str2, respectively.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i] < str2[i]) ? -1 : 1);
		}
		if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _strncpy - Copy a string up to a specified number of characters.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: Pointer to the destination buffer.
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strncat - Concatenate two strings up to a specified number of characters.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: Pointer to the destination buffer.
 */

char *_strncat(char *dest, const char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (j < n)
	{
		dest[i] = src[j];
		if (src[j] == '\0')
			break;
		i++;
		j++;
	}
	return (dest);
}

/**
 * _memset - Fill a block of memory with a specified byte value.
 *
 * @s: Pointer to the memory block to fill.
 * @b: The byte value to set in the memory block.
 * @n: The number of bytes to fill.
 *
 * Return: Pointer to the memory block.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}

/**
 * _strcat - Concatenate two strings.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string to be appended.
 *
 * Return: Pointer to the destination buffer.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

