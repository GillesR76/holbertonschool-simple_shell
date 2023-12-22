#include "main.h"

/**
 * exec - function that calls the excve function
 * @command: arguments
 *
 * Return: void
 */

int exec(char *command)
{
	int status;
	char *path, **argv = tokenize(command);
	pid_t childPid;

	if (argv == NULL)
		return (EXIT_FAILURE);
	if (argv[0] == NULL)
		return (error_not_found(argv, NULL, command));
	path = find_file_in_path(argv);
	if (path == NULL)
		return (error_not_found(argv, "./shell: %s: not found\n", command));

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
				free(argv);
				free(path);
				exit(2);
			}
		}
		waitpid(childPid, &status, 0);
	} else
		fprintf(stderr, "./shell: %s: not found\n", command);
	if (path != argv[0]) /* _getenv return argv[0] si commence / */
		free(path);
	free(argv);
	return (EXIT_SUCCESS);
}
