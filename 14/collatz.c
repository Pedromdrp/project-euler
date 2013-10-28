#include <stdio.h>

unsigned long collatz(unsigned long n) {
	if (n % 2 == 0) {
		return n / 2;
	} else {
		return 3 * n + 1;
	}
}

unsigned longest_sequence(unsigned limit) {
	unsigned max_len = 0;
	unsigned max_n = 0;
	unsigned i;
	for (i = 2; i <= limit; ++i) {
		unsigned long n;
		unsigned len = 1;
		for (n = i; n > 1; ++len) {
			n = collatz(n);
		}
	    if (len > max_len) {
    		max_len = len;
    		max_n = i;
    	}
	}
	return max_n;
}

int main() {
	printf("%u\n", longest_sequence(1000000));
	return 0;
}
