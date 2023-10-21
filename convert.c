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
int *parse(char *str, int *numCount)
{
	int *num = (int *)malloc(BUFFER_SIZE * sizeof(int));
	int i = 0;
	char *token = NULL;

	token = strtok(str, "\n");
	while (token != NULL && i < BUFFER_SIZE)
	{
		num[i] = atoi(token);
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
void print_factors(int *numArray, int arrLen)
{
	int i, j;

	for (i = 0; i < arrLen; i++)
	{
		for (j = 2; j <= numArray[i] / 2; j++)
		{
			if (is_factor(numArray[i], j))
			{
				printf("%d=%d*%d\n", numArray[i], j, (numArray[i] / j));
				break;
			}
		}
	}
}
