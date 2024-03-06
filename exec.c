#include "shell.h"

/**
 * execute_command - Execute a command.
 * @command_line: The command line to execute.
 */
void execute_command(char *command_line)
{
	char *args[MAX_ARGS];
	char *token;
	int arg_count = 0;
	char error_message[BUFFER_SIZE];
	char *directory;
	DIR *dir;
	struct dirent *entry;
	char cwd[1024];
	char **env = environ;

	token = _strtok(command_line, " ");
	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = token;
		token = _strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (_strcmp(args[0], "ls") == 0)
	{
		directory = (arg_count > 1) ? args[1] : ".";

		if ((dir = opendir(directory)) != NULL)
		{
			while ((entry = readdir(dir)) != NULL)
			{
				write(STDOUT_FILENO, entry->d_name, _strlen(entry->d_name));
				write(STDOUT_FILENO, "\n", 1);
			}
			closedir(dir);
		}
		else
		{
			perror("ls");
		}
	}
	else if (_strcmp(args[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			perror("pwd");
		}
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		if (arg_count > 1)
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
		else
		{
			if (chdir(getenv("HOME")) != 0)
			{
				perror("cd");
			}
		}
	}
	else if (_strcmp(args[0], "mkdir") == 0)
	{
		if (arg_count > 1)
		{
			if (mkdir(args[1], 0777) != 0)
			{
				perror("mkdir");
			}
		}
		else
		{
			fprintf(stderr, "mkdir: missing operand\n");
		}
	}
	else if (_strcmp(args[0], "rm") == 0)
	{
		if (arg_count > 1)
		{
			if (remove(args[1]) != 0)
			{
				perror("rm");
			}
		}
		else
		{
			fprintf(stderr, "rm: missing operand\n");
		}
	}
	else if (_strcmp(args[0], "mv") == 0)
	{
		if (arg_count > 2)
		{
			if (rename(args[1], args[2]) != 0)
			{
				perror("mv");
			}
		}
		else
		{
			fprintf(stderr, "mv: missing operand\n");
		}
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	else
	{
		if (access(args[0], X_OK) == 0)
		{
			pid_t pid = fork();
			if (pid < 0)
			{
				perror("Fork failed");
			}
			else if (pid == 0)
			{
				execv(args[0], args);
				perror(args[0]);
				exit(1);
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			snprintf(error_message, sizeof(error_message), "%s: No such file or directory\n", args[0]);
			write(STDERR_FILENO, error_message, strlen(error_message));
		}
	}
}

