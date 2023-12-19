#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exec - function that calls the excve function
 * @command: arguments
 *
 * Return: void
 */

extern char **environ;

void exec(char **command)
{
	int status;
	char *argv[2];
	pid_t childPid;

	if (access(*command, F_OK) != -1)
	{
		childPid = fork();
		if (childPid == -1)
		{
			perror("fork");
			free(*command);
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			argv[0] = *command;
			argv[1] = NULL;
			if (execve(argv[0], argv, environ) == -1)
			{
				fprintf(stderr, "./shell: %s: not found\n", *command);
				free(*command);
				exit(EXIT_FAILURE);
			}
		}
		else if (wait(&status) == -1)
		{
			perror("wait");
			free(*command);
			exit(EXIT_FAILURE);
		}
	}
	else
		fprintf(stderr, "./shell: %s: not found\n", *command);
}


