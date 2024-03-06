#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

extern char **environ;

/**
 * cdel - cdel
 * @str: str
 * @ch: ch
 *
 * Return: return
 */
int cdel(char *str, char ch)
{
	if (str == NULL)
	{
		return (0);
	}
	else
	{
		int i = 0, j = 0;

		while (str[i])
		{
			if (str[i] == ch)
			{
				j++;
			}
			i++;
		}
		return (j);
	}
}

/**
 * cotok - cotok
 * @str: str
 * @del: del
 *
 * Return - return
 */
char **cotok(char *str, char *del)
{
	int i = cdel(str, ' ');
	char **ca = (char **) malloc((i + 2) * sizeof(char *));
	char *tok = NULL;

	tok = strtok(str, del);
	i = 0;
	while (tok)
	{
		ca[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	ca[i] == NULL;
	return (ca);
}

/**
 * main - Entry point of the shell program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL, **ca = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	pid_t fr;
	(void) argc;
	(void) argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		characters_read = getline(&buffer, &bufsize, stdin);
		if (characters_read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		ca = cotok(buffer, " \n\t");
		fr = fork();
		if (fr == -1)
		{
		}
		else if (fr == 0)
		{
			execve(ca[0], ca, environ);
		}
		else
		{
			int st;

			wait(&st);
		}
	}
	free(buffer);
	free(ca);
	return (0);
}
