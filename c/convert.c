#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 *parse - Copies and converts string into number array
 *@str: Input str
 *@numCount: Pointer to number of elements in the array
 *
 *Return: Number array
 */
unsigned long long *parse(char *str, unsigned long long *numCount)
{
	unsigned long long *num = (unsigned long long *)
		malloc(BUFFER_SIZE * sizeof(unsigned long long));
	unsigned long long i = 0;
	char *token = NULL, *endptr;

	token = strtok(str, "\n");
	while (token != NULL && i < BUFFER_SIZE)
	{
		num[i] = strtoull(token, &endptr, 10);
		if (num[i] >= ULLONG_MAX - 1000)
		{
			char *cmd = malloc(strlen(token) + strlen("factor ") + 2);

			strcpy(cmd, token);
			call_shell(cmd);
			free(cmd);
			continue;
		}
		token = strtok(NULL, "\n");
		i++;
	}
	*numCount = i;
	return (num);
}

/**
 *print_factors - Prints factors of elements in a number array
 *@numArray: Number Array
 *@arrLen: Number of elements in number array
 *
 *
 */
void print_factors(unsigned long long *numArray,
		unsigned long long arrLen)
{
	unsigned long long i, j;

	for (i = 0; i < arrLen; i++)
	{
		for (j = 2; j < (numArray[i] / 2) + 1; j++)
		{
			if (is_factor(numArray[i], j))
			{
				printf("%llu=%llu*%llu\n", numArray[i], j, (numArray[i] / j));
				break;
			}
		}
	}
}
