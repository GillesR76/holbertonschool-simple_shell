#define _GNU_SOURCE
#include "main.h"

/**
 * main - simple shell function
 *
 * Return: 0
 */

int main(void)
{
	char *command = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
	fflush(stdout);
	command = readCommand(command);
	exec(command);
	free(command);
	}
	return (0);
}
