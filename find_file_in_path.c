#include "main.h"

/**
 * find_file_in_path - function that looks for files in the path
 * @filename: name of file
 *
 * Return: the full path or null if fail
 */

char *find_file_in_path(char **filename)
{
	char *pathVariable;
	char *token, *fullPath;

	if (strchr(*filename, '/') != NULL)
		return (*filename);

	pathVariable = _getenv("PATH");
	if (pathVariable == NULL)
		return (NULL);

	fullPath = malloc(1024);
	if (fullPath == NULL)
		return (NULL);

	token = strtok(pathVariable, ":");

	while (token != NULL)
	{
		sprintf(fullPath, "%s/%s", token, filename[0]);
		if (access(fullPath, X_OK) != -1)
		{
			free(pathVariable);
			return (fullPath);
		}
		token = strtok(NULL, ":");
	}
	free(fullPath);
	free(pathVariable);

	return (NULL);
}
