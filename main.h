#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>

#define DEBUG 0 /* 0 = false, 1 = true */

/* print_debug.c */
int print_debug(const char *format, ...);

extern char **environ;
void exec(char *command);
char *_getenv(const char *name);
char **tokenize(char *command);
int lencommand(char *command);
char *find_file_in_path(char **filename);
char *readCommand(char *command);

#endif
