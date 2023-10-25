#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

/**
 *parse - Copies and converts string into number array
 *@str: Input str
 *@numCount: Pointer to number of elements in the array
 *
 *Return: Number array
 */
void execute(char *str)
{
	unsigned long long i = 0;
	char *token = NULL, *endptr;

	token = strtok(str, "\n");
	while (token != NULL && i < BUFFER_SIZE)
	{
		unsigned long long number = 0;
		if (strtoull(token, &endptr, 10) >= ULLONG_MAX - 1000)
		{
			char *cmd = malloc(strlen(token) + strlen("factor ") + 2);

			strcpy(cmd, token);
			call_shell(cmd);
			free(cmd);
			token = strtok(NULL, "\n");
		}
		else
		{
			number = strtoull(token, &endptr, 10);
			check_primes(number);
			token = strtok(NULL, "\n");
			i++;
		}
	}
}

/**
 *print_factors - Prints factors of elements in a number array
 *@numArray: Number Array
 *@arrLen: Number of elements in number array
 *
 *
 */
void check_primes(unsigned long long num)
{
	unsigned long long j;
	unsigned long long root, result;
	double limit;

	root = (unsigned long long) sqrt((double) num) + 1;
	limit = (float)(root) / num;
	printf("limit is %f\n", limit);
	result = limit * num;
	printf("limit is %llu\n", result);

	for (j = 2; j < result + 1; j++)
	{
		if (is_factor(num, j) && is_prime(j))
		{
			if (is_prime(num / j))
			{
				printf("%llu=%llu*%llu\n", num, j, (num / j));
				return;
			}
		}
	}
	printf("No primes");
}
