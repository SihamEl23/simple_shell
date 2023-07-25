#include "shell.h"

/**
 * handle_signal - Handles the SIGINT signal.
 *
 * Return: void.
 */

void handle_signal(void)
{
	write(1, "\n$ ", 3);
}

