#ifndef FACTOR_H
#define FACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int is_prime(int n);
int is_factor(int num, int factor);
int *parse(char *str, int *numCount);
void print_factors(int *numArray, int arrLen);


#endif /* FACTOR_H */
