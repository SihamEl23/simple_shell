#include "shell.h"

/**
 * handle_signal - handles the signal SIGINT
 * @signal: signal to handle
 */

void handle_signal(int signal)
{
	(void)signal;
	write(1, "\n$ ", 3);
}

