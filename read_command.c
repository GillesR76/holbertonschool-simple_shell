#define _GNU_SOURCE
#include "main.h"

/**
 * readCommand - functions that reads a command line from input
 * @command: string that reads the input command
 *
 * Return: returns a string containing the command line
 */

char *readCommand(char *command)
{
	size_t commandSize = 0;
	ssize_t bytesRead;

	bytesRead = getline(&command, &commandSize, stdin);

	if (bytesRead == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			free(command);
			exit(EXIT_SUCCESS);
		}
		free(command);
		perror("Error");
		exit(EXIT_FAILURE);
	}

	command[bytesRead - 1] = '\0';
	return (command);
}
