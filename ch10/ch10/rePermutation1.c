#include<stdio.h>

int main(void) {
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int i, j, k;

	for (i = 0; i < 6; i++) {

		for (j = 0; j < 6; j++) {

			for (k = 0; k < 6; k++) {

				printf("%3d %3d %3d\n", a[i], a[j], a[k]);

			}

		}

	}

	return 0;

}