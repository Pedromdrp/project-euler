#include <stdio.h>
#include <limits.h>

unsigned reverse(unsigned n) {
	unsigned m;
	for (m = 0; n != 0; n /= 10) {
		m = 10 * m + n % 10;
	}
	return m;
}

int has_trailing_zeros(unsigned n) {
	return n % 10 == 0;
}

int odd_digits(unsigned n) {
	while (n > 0) {
		if (n % 2 == 0) {
			return 0;
		}
		n /= 10;
	}
	return 1;
}

int is_reversible(unsigned n) {
	unsigned m;
	if (has_trailing_zeros(n)) {
		return 0;
	}
	m = reverse(n);
	if (has_trailing_zeros(n)) {
		return 0;
	}
	return odd_digits(n + m);
}

unsigned count_reversible(unsigned limit) {
	unsigned counter = 0;
	unsigned i;
	for (i = 1; i < limit; ++i) {
		if (is_reversible(i)) {
			++counter;
		}
	}
	return counter;
}

int main() {
	printf("%u\n", count_reversible(1000000000));
	return 0;
}
