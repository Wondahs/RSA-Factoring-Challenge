#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *parse - Copies and converts string into number array
 *@str: Input str
 *@numCount: Pointer to number of elements in the array
 *
 *Return: Number array
 */
long long int *parse(char *str, long long int *numCount)
{
	long long int *num = (long long int *)malloc(BUFFER_SIZE * sizeof(long long int));
	long long int i = 0;
	char *token = NULL, *endptr;

	token = strtok(str, "\n");
	while (token != NULL && i < BUFFER_SIZE)
	{
		num[i] = strtoll(token, &endptr, 10);
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
void print_factors(long long int *numArray, long long int arrLen)
{
	long long int i, j;

	for (i = 0; i < arrLen; i++)
	{
		for (j = 2; j < numArray[i]; j++)
		{
			if (is_factor(numArray[i], j))
			{
				printf("%lld=%lld*%lld\n", numArray[i], j, (numArray[i] / j));
				break;
			}
		}
	}
}
