#include "main.h"

/**
 * exec - function that calls the excve function
 * @command: arguments
 *
 * Return: void
 */

void exec(char **command)
{
	int status;
	char *argv[2];
	pid_t childPid;

	print_debug("[Info] -> exec start");
	childPid = fork();
	if (childPid == -1)
	{
		print_debug("[Error] -> exec() -> fork invalid");
		perror("fork");
		free(*command);
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		print_debug("[Success] -> childPid valid");
		argv[0] = *command;
		argv[1] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
		{
			print_debug("[Error] -> exec() -> execve failed");
			perror("execve");
			free(*command);
			exit(EXIT_FAILURE);
		}
		print_debug("[Success] -> execve");
	}
	else if (wait(&status) == -1)
	{
		print_debug("[Error] -> wait failed");
		perror("wait");
		free(*command);
		exit(EXIT_FAILURE);
	}
}


