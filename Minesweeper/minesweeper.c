#include <stdio.h>

#define TABLE_MAX 102

void updateTable(char table[TABLE_MAX][TABLE_MAX], int i, int j) {
	int i_plus = i + 1;
	int j_plus = j + 1;
	int i_menus = i - 1;
	int j_menus = j - 1;
	if (table[i][j] <= 8) {
		table[i][j_plus]++;
		table[i][j_menus]++;
		table[i_plus][j]++;
		table[i_plus][j_plus]++;
		table[i_plus][j_menus]++;
		table[i_menus][j]++;
		table[i_menus][j_plus]++;
		table[i_menus][j_menus]++;
	}
}

int main(int argc, char **argv) {
	int i, j, k, rows, columns;
	char c, table[TABLE_MAX][TABLE_MAX];
	k = 1;
	while (scanf("%i %i", &rows, &columns) != EOF) {
		if (rows == 0 && columns == 0) {
			return 0;
		}
		for (i = 1; i <= rows; i++) {
			scanf("%c", &c);
			for (j = 1; j <= columns; j++) {
				scanf("%c", &c);
				table[i][j] = c == '.' ? 48 : 0;
			}
		}
		if (k != 1) {
			printf("\n");
		}
		printf("Field #%i:\n", k);
		for (i = 1; i <= rows; i++) {
			for (j = 1; j <= columns; j++) {
				updateTable(table, i, j);
			}
		}
		for (i = 1; i <= rows; i++) {
			for (j = 1; j <= columns; j++) {
				if (table[i][j] <= 8) {
					printf("*");
				} else {
					printf("%c", table[i][j]);
				}
			}
			printf("\n");
		}
		k++;
	}
	return 0;
}
