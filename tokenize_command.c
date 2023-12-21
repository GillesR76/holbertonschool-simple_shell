#include "main.h"

/**
 * tokenize - function to tokenize the command string
 * @command: input command string
 *
 * Return: array of strings
 */

char **tokenize(char *command)
{
	char *token;
	int i;
	char **tokens = NULL;

	while (*command == ' ' || *command == '\t')
		command++;

	token = strtok(command, " ");
	for (i = 0; token != NULL; i++)
	{
		tokens = realloc(tokens, (i + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("Memory allocation error");
			return (NULL);
		}
		tokens[i] = token;
		token = strtok(NULL, " ");
	}

	/* Place pour ajouter le marqueur de fin NULL */
	tokens = realloc(tokens, (i + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	tokens[i] = NULL;

	return (tokens);
}
