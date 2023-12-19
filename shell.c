#define _GNU_SOURCE
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell function
 *
 * Return: void
 */

int main(void)
{
	char *command = NULL;
	size_t commandSize = 0;
	ssize_t bytesRead;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		else if (isatty(STDIN_FILENO) == -1)
		{
			perror("isatty");
			free(command);
			exit(EXIT_FAILURE);
		}

		bytesRead = getline(&command, &commandSize, stdin);
		if (bytesRead == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(command);
				exit(EXIT_SUCCESS);
			}
			free(command);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		command[bytesRead - 1] = '\0';
		exec(&command);
	}
	free(command);
	return (0);
}
