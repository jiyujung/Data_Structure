#include <stdio.h>

void matrixMultiflication(int a[][4], int b[][5], int c[][5]) {
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 4; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main(void) {
	int i, j;

	int a[3][4] = {
		{5, 3, -1, 2},
		{-2, 4, 3, 1},
		{2, 3, 0, 7} };

	int b[4][5] = {
		{3, 0, 2, 4, -2},
		{1, 6, 0, 8, 2},
		{2, 2, -3, 1, 7},
		{0, 6, 5, 2, 4} };

	int c[3][5] = { 0 };

	matrixMultiflication(a, b, c);

	printf("    ��� a\n");
	printf("----------------------------\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("----------------------------\n\n\n");

	printf("    ��� b\n");
	printf("----------------------------\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++)
			printf("%5d", b[i][j]);
		printf("\n");
	}
	printf("----------------------------\n\n\n");

	printf("    ��� �� ���\n");
	printf("----------------------------\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++)
			printf("%5d", c[i][j]);
		printf("\n");
	}
	printf("----------------------------\n\n\n");

	return 0;

}