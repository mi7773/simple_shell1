#include "shell.h"
/**
 * main - Entry point of the shell program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = BUFFER_SIZE;
	ssize_t characters_read;
	FILE *file = NULL;

	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			perror("Error opening file");
			exit(1);
		}

		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}

		while ((characters_read = getline(&buffer, &bufsize, file)) != -1)
		{
			buffer[strcspn(buffer, "\n")] = '\0';
			execute_command(buffer);
		}

		fclose(file);
		free(buffer);
	}
	else
	{
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}

		while (1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);

			characters_read = getline(&buffer, &bufsize, stdin);

			if (characters_read == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}

			buffer[strcspn(buffer, "\n")] = '\0';

			execute_command(buffer);
		}

		free(buffer);
	}
	return (0);
}
