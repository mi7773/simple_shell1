#include "shell.h"

/**
 * _strlen - calculate length
 *
 * @: str: string
 * return: length
 */
size_t _strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return (length);
}
/**
 * _strcpy - cpy
 *
 * Return: Always (ptr).
 */
char *_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return (ptr);
}
/**
 * _strcat - concate
 *
 * Return: ptr
 */
char *_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return (ptr);
}
/**
 * strcmp - compare
 *
 * @str1 : string
 * @str2: string
 * Return: *str1 - *str2
 */
int _strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

/**
 * strcspn - strcspn
 *
 * @str1 : string
 * @str2: string
 * Return: count
 */
size_t _strcspn(const char *str1, const char *str2) {
    const char *p1, *p2;
    size_t count = 0;

    for (p1 = str1; *p1 != '\0'; p1++) {
        for (p2 = str2; *p2 != '\0'; p2++) {
            if (*p1 == *p2) {
                return count;
            }
        }
        count++;
    }

    return (count);
}
/**
 * strspn - strspn
 *
 * @str1 : string
 * @str2: string
 * Return: count
 */
size_t _strspn(const char *str1, const char *str2) {
    const char *p1, *p2;
    size_t count = 0;

    for (p1 = str1; *p1 != '\0'; p1++) {
        for (p2 = str2; *p2 != '\0'; p2++) {
            if (*p1 == *p2) {
                break;
            }
        }
        if (*p2 == '\0') {
            return count;
        }
        count++;
    }

    return (count);
}

/**
 * strtok - tokanize
 *
 * @str : string
 * @delimiters: delimiters
 * Return: token
 */
char *_strtok(char *str, const char *delimiters) {
    static char *next_token = NULL;
    char *token;
    
    if (str != NULL) {
        next_token = str;
    } else if (next_token == NULL) {
        return NULL;
    }
    next_token += _strspn(next_token, delimiters);
    if (*next_token == '\0') {
        return NULL;
    }
	token = next_token;
    next_token += _strcspn(next_token, delimiters);
    if (*next_token != '\0') {
        *next_token++ = '\0';
    }
    return (token);
}
/**
 * strdup - dup
 *
 * @s : string
 * Return: _strcpy(copy, s))
 */
char *_strdup(const char *s) {
    size_t len = _strlen(s) + 1;
    char *copy = malloc(len);
    if (copy == NULL) {
        return NULL;
    }
    return (_strcpy(copy, s));
}

