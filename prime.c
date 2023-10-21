#include "main.h"

/**
 *is_prime - Checks if n is prime
 *@n: Input number
 *
 *Return: 1 if prime, 0 if not.
 */
int is_prime(int n)
{
	int i;

	for (i = 2; i < (n / 2) + 1; i++)
	{
		if ((n % i) == 0)
			return (0);
	}
	return (1);
}

/**
 *is_factor - Checks if @factor is a factor of @num
 *@factor: Factor
 *@num: Num
 *
 *Return: 1 if yes, 0 if no
 */
int is_factor(int num, int factor)
{
	if (num % factor == 0)
		return (1);
	else
		return (0);
}
