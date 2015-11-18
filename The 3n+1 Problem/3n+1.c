#include <stdio.h>

#define MAX 1000001

unsigned int table[MAX];

int main(int argc, char **argv) {
	unsigned long n, i, j, tmp, length, max_length;
	while (scanf("%lu %lu", &i, &j) != EOF) {
		printf("%lu %lu", i, j);
		max_length = 0;
		if (i > j) {
			tmp = i;
			i = j;
			j = tmp;
		}
		while (i <= j) {
			n = i;
			length = 1;
			while (n != 1) {
				if (n < MAX && table[n]) {
					length += table[n] - 1;
					n = 1;
				} else {
					if (n % 2 == 0) {
						n = n / 2;
					} else {
						n = (n * 3) + 1;
					}
					length++;
				}
			}
			table[i] = length;
			if (length > max_length) {
				max_length = length;
			}
			i++;
		}
		printf(" %lu\n", max_length);
	}
	return 0;
}
