#include "shell.h"

/**
 * _realloc - Reallocates a memory block with a new size.
 *
 * @ptr: Pointer to the memory block to be reallocated.
 * @size: New size in bytes for the memory block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr = NULL;

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (size >= SIZE_MAX)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

