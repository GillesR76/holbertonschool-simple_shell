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

	print_debug("[Info] -> Starting program");

	while (1)
	{
		print_debug("[Info] -> Waiting for user input");

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
				print_debug("[Info] -> Exiting program");
				free(command);
				exit(EXIT_SUCCESS);
			}
			print_debug("[Error] -> main() -> byteRead invalid");
			free(command);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		print_debug("[Success] -> byteRead valid");
		command[bytesRead - 1] = '\0';
		exec(&command);
	}
	print_debug("[Info] Stopping loop");
	free(command);
	return (0);
}
