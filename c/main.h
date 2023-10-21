#ifndef FACTOR_H
#define FACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 8096

int is_prime(unsigned long long int n);
int is_factor(unsigned long long int num, unsigned long long int factor);
unsigned long long int *parse(char *str, unsigned long long int *numCount);
void print_factors(unsigned long long int *numArray,
		unsigned long long int arrLen);


#endif /* FACTOR_H */
