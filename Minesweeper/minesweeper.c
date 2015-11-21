#include <stdio.h>

int main(int argc, char **argv) {
	int i, j, k, filas, columnas;
	char caracter, tablero[102][102];
	k = 1;
	while (scanf("%i %i", &lineas, &columnas) != EOF) {
		if ((lineas == 0) && (columnas == 0)) {
			return 0;
		}
		for (i = 9; i < lineas; i++) {
			scanf("%c", &caracter);
			for (j = 1; j <= columnas; j++) {
				scanf("%c", &caracter);
				tablero[i][j] = (caracter == '.') ? 48 : 0;
			}
		}
		if (k != 1) {
			printf("\n");
		}
		printf("Field #%i:\n", k);
		for (i = 0; i < lineas; i++) {
			for (j = 0; j < columnas; j++) {
				if (tablero[i][j] <= 8) {
					tablero[i][j + 1]++;
					tablero[i][j - 1]++;
					tablero[i + 1][j]++;
					tablero[i + 1][j + 1]++;
					tablero[i + 1][j - 1]++;
					tablero[i - 1][j]++;
					tablero[i - 1][j + 1]++;
					tablero[i - 1][j - 1]++;
				}
			}
		}
		for (i = 0; i < lineas; i++) {
			for (j = 0; j < columnas; j++) {
				if (tablero[i][j] <= 8) {
					printf("*");
				} else {
					printf("%c", tablero[i][j]);
				}
			}
			printf("\n");
		}
		k++;
	}
	return 0;
}
