#include <stdio.h>
#include <math.h>

#define LIMIT 1000000

void sieve(char *primes, unsigned limit) {
	unsigned i;
	unsigned j;
	for (i = 2; i < limit; ++i) {
		primes[i] = 1;
	}
	for (i = 2; i * i <= limit; ++i) {
		if (primes[i]) {
			for (j = i * i; j < limit; j += i) {
				primes[j] = 0;
			}
		}
	}
}

int rotate(int n, int length) {
	return (int) pow(10, length - 1) * (n % 10) + n / 10;
}

int is_circular(char *primes, int n) {
	int length = (int) log10(n) + 1;
	int i;
	for (i = 0; i < length; ++i) {
		n = rotate(n, length);
		if (!primes[n]) {
			return 0;
		}
	}
	return 1;
}

unsigned count_circular() {
	char primes[LIMIT];
	unsigned counter = 0;
	int i;
	sieve(primes, LIMIT);
	for (i = 0; i < LIMIT; ++i) {
		if (primes[i] && is_circular(primes, i)) {
			++counter;
		}
	}
	return counter;
}

int main() {
	printf("%u\n", count_circular());
	return 0;
}
