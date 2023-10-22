#include <stdio.h>

typedef struct {
	unsigned long long a;
	unsigned long long b;
} factor_pair;

void get_factor_pair(unsigned long long n) {
	factor_pair pair;

	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pair.a = i;
			pair.b = n / i;
			printf("%llu=%llu*%llu\n", n, pair.a, pair.b);
			return;
		}
	}

	// If we reach here, then the number is prime.
	pair.a = n;
	pair.b = 1;
	printf("%llu=%llu*%llu\n", n, pair.a, pair.b);
	return;
}

