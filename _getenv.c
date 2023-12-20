#include "main.h"

char *_getenv(const char *name)
{
	extern char **environ;
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
