#include "shell.h"
/**
 * print_environment - Prints the environment variables
 */
void print_environment()
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL) {
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
