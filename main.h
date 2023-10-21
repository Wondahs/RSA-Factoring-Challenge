#ifndef FACTOR_H
#define FACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int is_prime(long long int n);
int is_factor(long long int num, long long int factor);
long long int *parse(char *str, long long int *numCount);
void print_factors(long long int *numArray, long long int arrLen);


#endif /* FACTOR_H */
