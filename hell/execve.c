#include "main.h"

/**
 * exec - function that calls the excve function
 * @command: arguments
 *
 * Return: void
 */

void exec(char *command)
{
	int status, i;
	char **argv = tokenize(command);
	char *path;
	pid_t childPid;

	if (argv == NULL || argv[0] == NULL)
		return;

	if (strcmp(argv[0], "exit") == 0 && (argv[1] == NULL))
	{
		free(argv);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(argv[0], "env") == 0 && (argv[1] == NULL))
	{
		_printenv();
		free(argv);
	}
	path = find_file_in_path(argv);

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
		waitpid(childPid, &status, 0);
	} else
		fprintf(stderr, "./shell: %s: not found\n", command);

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(path);
	free(argv);
}


