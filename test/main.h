#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

#define DEBUG 1 /* 0 = false, 1 = true */

/**
   * path_t - singly linked list
   * @dir: string
   * @next: points to the next node
   *
   */

typedef struct path_t
{
	char *dir;
	struct path_t *next;
} path_t;

/* print_debug.c */
int print_debug(const char *format, ...);

path_t *findPath(char *path);
void exec(char **command);

#endif
