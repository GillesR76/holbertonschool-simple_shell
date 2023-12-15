#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function that prints and that splits
 *
 * Return: void
 */

int main(void)
{

	printf("Enter a string: ");

	char *input = NULL;
	size_t n = 0;

	if (getline(&input, &n, stdin) == -1)
	{
		perror("Error reading input");
		return (1);
	}

	const char delimiter[] = " \t\n";
	char *token = strtok(input, delimiter);

	while (token != NULL)
	{
		printf("Token: %s\n", token);

		token = strtok(NULL, delimiter);
	}

	free(input);

	return (0);
}
