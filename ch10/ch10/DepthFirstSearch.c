#include <stdio.h>
#define SIZE 8

int stack[SIZE];
int top = -1;

void push(int index) {
	stack[++top] = index;
}

int pop(void) {
	if (top == -1) return -1;
	else return stack[top--];
}

void DepthFirstSearch(int G[][SIZE], char V[]) {	// 2���� �迭�� ���� ���� ���� �����ϸ� �ȵ� / char *V�� �ص���
	int i, j, searchOK[SIZE] = {0};
	char startV;
	printf("��� ���� : ");
	scanf_s("%c", &startV, 1);	// scanf�� ���� ���̸� ���൵ ������, scanf_s�� ���̸� �ڿ� ���̸� ��ߵ�
	for (i = 0; i < SIZE; i++) if (startV == V[i]) break;
	printf("���̿켱Ž�� : %c", startV);
	searchOK[i] = 1;
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == 0) {
				printf(" -> %c", V[j]);
				searchOK[j] = 1;
				push(i);
				i = j;
				break;
			}
		}

		if(j == SIZE) i = pop();
	} while (i >= 0);
}

int main(void) {
	int i, j;
	int G[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
									{1, 0, 0, 1, 1, 0, 0, 0},
									{1, 0, 0, 0, 0, 1, 1, 0},
									{0, 1, 0, 0, 0, 0, 0, 1},
									{0, 1, 0, 0, 0, 0, 0, 1},
									{0, 0, 1, 0, 0, 0, 0, 1},
									{0, 0, 1, 0, 0, 0, 0, 1},
									{0, 0, 0, 1, 1, 1, 1, 0} };	// ������� (0~7���� �࿭ �ۼ�)
	char V[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%3d", G[i][j]);
		}
		printf("\n");
	}

	DepthFirstSearch(G, V);
	return 0;
}