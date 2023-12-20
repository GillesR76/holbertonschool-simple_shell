#include "main.h"

/**
 * _printenv - function that prints the environment
 *
 * Retrun: void
 */

void _printenv(void)
{
	unsigned int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
