#ifndef FACTOR_H
#define FACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 8096

int is_prime(unsigned long long int n);
int is_factor(unsigned long long int num, unsigned long long int factor);
void execute(char *str);
void check_primes(unsigned long long int num);
void call_shell(char *str);


#endif /* FACTOR_H */
