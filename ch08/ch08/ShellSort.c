#include <stdio.h>

void ShellSort(int a[], int n) {
	int i, j, key, t;
	for (t = n / 2; t >= 1; t /= 2) {
		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j -= t) {
				if (key >= a[j]) break;
				a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}

int main(void) {
	int a[] = { 3, 1, 17, 20, 31, 27, 48, 88, 16, 13, 70, 8, 7 };
	int n;
	n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	printf("½© Á¤·Ä : ");
	for (int i = 0; i < n; i++) printf("%5d", a[i]);
	printf("\n");
	return 0;
}