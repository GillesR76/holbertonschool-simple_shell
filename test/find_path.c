#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * findPath - function that finds the path
 * @path: string
 *
 * Return: head
 */

path_t *findPath(char *path)
{
	path_t *head = NULL;
	path_t *tail = NULL;

	char *dir = strtok(path, ":");

	while (dir)
	{
		path_t *newPath = malloc(sizeof(path_t));

		if (newPath == NULL)
			return (0);

		newPath->dir = strdup(dir);
		newPath->next = NULL;

		if (head == NULL)
		{
			head = newPath;
			tail = newPath;
			return (0);
		}
		tail->next = newPath;
		tail = newPath;

		dir = strtok(NULL, ":");
	}
	return (head);
}

