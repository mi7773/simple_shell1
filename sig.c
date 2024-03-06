#include "shell.h"
/**
 * sigint_handler - Handles the SIGINT signal
 * @sig: The signal number
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	fflush(stdout);
}
