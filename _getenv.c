#include "main.h"

/**
 * _getenv - function that replicates the getenv function
 * @name: environment variable name
 *
 * Return: null
 */

char *_getenv(const char *name)
{
	char *token, *envCopy;
	char *value;

	for (; *environ != NULL; environ++)
	{
		envCopy = strdup(*environ);
		token = strtok(envCopy, "=");

		if (token != NULL && strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");

			if (token != NULL)
			{
				value = strdup(token);
				free(envCopy);
				return (value);
			}
		}
		free(envCopy);
	}
	return (NULL);
}
