#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toString(int n) {
	int tmp, digits;
	char *asString;
	tmp = n;
	digits = 0;
	do {
		tmp /= 10;
		digits++;
	} while (tmp != 0);
	asString = (char*) malloc(sizeof(char) * digits);
	tmp = n;
	while (digits--) {
		asString[digits] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return asString;
}

void printChar(char c, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%c", c);
	}
}

int main(int argc, char **argv) {
	int i, j, k, n, s, d, digits, lines;
	char *string, c;
	char *segment0 = "- -- -----";
	char *segment1 = "|   ||| ||";
	char *segment2 = "|||||  |||";
	char *segment3 = "  ----- --";
	char *segment4 = "| |   | | ";
	char *segment5 = "|| |||||||";
	char *segment6 = "- -- -- --";
	while (scanf("%i %i", &s, &n) != EOF) {
		if (s == 0 && n == 0) {
			return 0;
		}
		string = toString(n);
		digits = strlen(string);
		lines = (s * 2) + 3;
		for (i = 0; i < lines; i++) {
			for (j = 0; j < digits; j++) {
				if (j > 0) {
					printf(" ");
				}
				d = string[j] - 48;
				if (i == 0) {
					printf(" ");
					c = segment0[d];
					printChar(c, s);
					printf(" ");
				} else if (i > 0 && i <= s) {
					c = segment1[d];
					printf("%c", c);
					printChar(' ', s);
					c = segment2[d];
					printf("%c", c);
				} else if (i == s + 1) {
					printf(" ");
					c = segment3[d];
					printChar(c, s);
					printf(" ");
				} else if ((i > s + 1) && (i <= (s * 2) + 1)) {
					c = segment4[d];
					printf("%c", c);
					printChar(' ', s);
					c = segment5[d];
					printf("%c", c);
				} else {
					printf(" ");
					c = segment6[d];
					printChar(c, s);
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
