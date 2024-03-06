#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#define BUFFER_SIZE 1024
#define MAX_ARGS 32
extern char **environ;
char *_strtok(char *str, const char *delimiters);
size_t _strcspn(const char *str1, const char *str2);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *str);
char *get_path();
char **get_path_directories(char *path);
void sigint_handler(int sig);
void print_environment();
void execute_command(char *command_line);
#endif
