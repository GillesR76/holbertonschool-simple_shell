#include <stdio.h>
#include <stdlib.h>

/**
 * main – function that prints all the arguments without using ac
 * @ac: number of arguments
 * @av: string
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}

	return (0);
}
