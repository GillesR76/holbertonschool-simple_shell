#include "main.h"

/**
 * find_file_in_path - function that looks for files in the path
 * @filename: name of file
 *
 * Return: the full path or null if fail
 */

char *find_file_in_path(char **filename)
{
	char *pathVariable = _getenv("PATH");
	char *pathCopy = NULL, *token, fullPath[1024];
	char *result = NULL;

	if (strchr(*filename, '/') != NULL)
		return (*filename);

	if (pathVariable == NULL)
		return (NULL);

	pathCopy = strdup(pathVariable);

	token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		sprintf(fullPath, "%s/%s", token, filename[0]);

		if (access(fullPath, X_OK) != -1)
		{
			result = strdup(fullPath);
			free(pathCopy);
			return (result);
		}

		token = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}
