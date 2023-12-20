#include "main.h"

/**
 * exec - function that calls the excve function
 * @command: arguments
 *
 * Return: void
 */

void exec(char *command)
{
	int status;
	char **argv = tokenize(command);
	char *path;
	pid_t childPid;

	path = find_file_in_path(argv);

	if (argv == NULL)
		return;

	if (path == NULL)
	{
		fprintf(stderr, "./shell: %s: not found\n", command);
		free(argv);
		return;
	}

	if (access(path, X_OK) == 0)
	{
		childPid = fork();
		if (childPid == -1)
		{
			perror("fork");
			free(argv);
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			if (execve(path, argv, environ) == -1)
			{
				fprintf(stderr, "./shell: %s: not found\n", path);
				free(path);
				free(argv);
				exit(EXIT_FAILURE);
			}
		}
		else if (wait(&status) == -1)
		{
			perror("wait");
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
		fprintf(stderr, "./shell: %s: not found\n", command);

	free(path);
	free(argv);
}


