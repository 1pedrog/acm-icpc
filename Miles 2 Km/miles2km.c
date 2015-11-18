#include <stdio.h>

int main(int argc, char **argv) {
	int n;
	char e[5] = { 48, 52, 50, 50, 52 };
	while (scanf("%i", &n) != EOF) {
		if (n == 0) {
			return 0;
		}
		printf("0.%c0\n", e[n % 5]);
	}
	return 0;
}
