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

void DepthFirstSearch(int G[][SIZE], char V[]) {	// 2차원 배열을 받을 때는 열은 생략하면 안됨 / char *V로 해도됨
	int i, j, searchOK[SIZE] = {0};
	char startV;
	printf("출발 정점 : ");
	scanf_s("%c", &startV, 1);	// scanf만 쓰면 길이를 안줘도 되지만, scanf_s가 쓰이면 뒤에 길이를 줘야됨
	for (i = 0; i < SIZE; i++) if (startV == V[i]) break;
	printf("깊이우선탐색 : %c", startV);
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
									{0, 0, 0, 1, 1, 1, 1, 0} };	// 인접행렬 (0~7까지 행열 작성)
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