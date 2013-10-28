#include <stdio.h>

#define LIMIT 28123

unsigned abundant(unsigned n) {
	unsigned sum = 0;
	unsigned i;
	for (i = 1; i < n; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum > n;
}

int sum() {
	char a[LIMIT + 1];
	char sa[LIMIT + 1];
	unsigned i, j;
	unsigned total = 0;
	for (i = 0; i <= LIMIT; ++i) {
		a[i] = 0;
		sa[i] = 0;
	}
	for (i = 12; i <= LIMIT; ++i) {
		if (abundant(i)) {
			a[i] = 1;
			for (j = 12; j <= i && j + i <= LIMIT; ++j) {
				if (a[j]) {
					sa[j + i] = 1;
				}
			}
		}
	}
	for (i = 0; i <= LIMIT; ++i) {
		if (!sa[i]) {
			total += i;
		}
	}
	return total;
}

int main() {
	printf("%d\n", sum());
	return 0;
}
