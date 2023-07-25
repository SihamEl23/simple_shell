#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdint.h>
#define BUFFER_SIZE 1024

extern char **environ;

size_t _strlen(const char *s);
char *_strchr(const char *s, int c);
char *_memcpy(char *dest, char *src, unsigned int n);
char *handle_path(char *com);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
char *_strtok(char str[], const char *delims);
char *_getenv(const char *name);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_memset(char *s, char b, unsigned int n);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, const char *src, int n);
char *_strncat(char *dest, const char *src, int n);
void execute_command(char **args);
int _strcmp(char *s1, char *s2);
void handle_signal(void);
void handle_comments(char **args);
char **tokenize_buffer(char *buffer, size_t size_buffer, int i);
void myExitFunction(char **args, char *buffer);
void read_input(char **buf, size_t *size_buf, FILE *stream);
void p_num(int n);
int p_ch(char c);
void p_var(char **args);

#endif
