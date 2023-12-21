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
			printf("$ ");

		fflush(stdout);
		command = readCommand(command);
		if (strncmp(command, "exit", 4) == 0)
		{
			free(command);
			return (2);  /* sortie du shell avec exit */
		}
		if (strncmp(command, "env", 3) == 0)
		{
			_printenv();
			continue;
		}
		else
			exec(command);
		free(command);
	}
	return (0);
}
