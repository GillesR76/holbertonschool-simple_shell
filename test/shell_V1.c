#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *  * main - super simple shell function
 *   *
 *    * Return: void
 *     */

int main(void)
{
	int status;
	char *command = NULL;
	size_t commandSize = 0;
	ssize_t bytesRead;
	char *argv[2];
	pid_t childPid;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");

		bytesRead = getline(&command, &commandSize, stdin);
		if (bytesRead == -1)
		{
			if (feof(stdin))
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
			free(command);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		command[bytesRead - 1] = '\0';
		childPid = fork();
		if (childPid == -1)
		{
			free(command);
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			argv[0] = command;
			argv[1] = NULL;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				free(command);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(command);
	return (0);
}
