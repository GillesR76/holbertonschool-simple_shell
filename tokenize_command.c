#include "main.h"

/**
 * tokenize - function to tokenize the command string
 * @command: input command string
 *
 * Return: array of strings
 */

char **tokenize(char *command)
{
	int size = strlen(command);
	char *token;
	int i;
	char **tokens = malloc((size + 2)  * sizeof(char *));

	if (tokens == NULL)
		return (NULL);

	token = strtok(command, " ");

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
	}

	tokens[i] = NULL;

	return (tokens);

}
