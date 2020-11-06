#include <stdio.h>
#include <limits.h>
#define SIZE 9

int minVertex(int D[], int chk[]) {
	int i, minValue = INT_MAX, minIndex;

	for (i = 0; i < SIZE; i++)
		if (chk[i] == 0 && minValue > D[i]) {
			minValue = D[i];
			minIndex = i;
		}

	return minIndex;
}

void Dijkstra(int G[SIZE][SIZE], int D[], int P[], int i) {
	int chk[SIZE] = { 0, };
	int j, cnt = 0;

	for (j = 0; j < SIZE; j++)
		if (G[i][j] > 0 && G[i][j] < INT_MAX) {
			D[j] = G[i][j];
			P[j] = i;
		}
	chk[i] = 1;
	cnt++;

	while (cnt < SIZE) {
		i = minVertex(D, chk);
		for (j = 0; j < SIZE; j++)
			if (G[i][j] > 0 && G[i][j] < INT_MAX) //������ �ְ�
				if (D[j] > D[i] + G[i][j]) { //axis�� ��ġ�� ��ΰ� ª�ٸ�
					D[j] = D[i] + G[i][j]; //ª�� �Ÿ��� ������Ʈ
					P[j] = i; //axis�� ��ġ���� ��� ����
				}
		chk[i] = 1; //���� �� �࿡�� ����
		cnt++;
//		printf("%d�ܰ�\n", cnt);
//		printf("D : ");
//		for (i = 0; i < SIZE; i++)
//			printf("%5d", D[i]);
//		printf("\nP : ");
//		for (i = 0; i < SIZE; i++)
//			printf("%5d", P[i]);
//		printf("\n");
	}
}

int main(void) {
	int G[SIZE][SIZE] = { {0, INT_MAX, 6, INT_MAX, INT_MAX,9, INT_MAX, INT_MAX, INT_MAX},
						 {INT_MAX, 0, 18, INT_MAX, 11, 1, INT_MAX, INT_MAX, 35},
						 {6, 18, 0, 17, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
						 {INT_MAX, INT_MAX, 17, 0, INT_MAX, INT_MAX, INT_MAX, 24, INT_MAX},
						 {INT_MAX, 11, INT_MAX, INT_MAX, 0, 40, 10, INT_MAX, 44},
						 {9, 1, INT_MAX, INT_MAX, 40, 0, INT_MAX, INT_MAX, INT_MAX},
						 {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX, 0, 12, 29},
						 {INT_MAX, INT_MAX, INT_MAX, 24, INT_MAX, INT_MAX, 12, 0, 30},
						 {INT_MAX, 35, INT_MAX, INT_MAX, 44, INT_MAX, 29, 30, 0}};

	char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	char shortestPath[SIZE];
	char departureVertex, arrivalVertex;
	int P[SIZE] = { 0, };
	int D[SIZE] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };
	int i, j, vertexNum, vertexCnt = 0, departureNum;

	printf("\n\t[���� �������� �Ÿ�]\n ");
	for (i = 0; i < SIZE; i++)printf("%4c", V[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++) {
		printf("%c", V[i]);
		for (j = 0; j < SIZE; j++)
			if (G[i][j] == INT_MAX)printf("%4c", '-');
			else printf("%4d", G[i][j]);
		printf("\n");
	}

	printf("\n��� ����(A~H) : ");
	scanf_s("%c", &departureVertex, 1);
	getchar();
	printf("���� ����(A~H) : ");
	scanf_s("%c", &arrivalVertex, 1);
	getchar();
	while (departureVertex == arrivalVertex) {
		printf("��߰� ������ �����ϴ�. ���� ����(A~H) : ");
		scanf_s("%c", &arrivalVertex, 1);
		getchar();
	}

	for (i = 0; i < SIZE; i++) if (arrivalVertex == V[i]) break;
	D[i] = 0;
	P[i] = i;

	Dijkstra(G, D, P, i);

	printf("\n�� �������� ���� ���� %c���� �ִ� ��� �� �Ÿ�\n", arrivalVertex);

	for (i = 0; i < SIZE; i++) {
		if (V[i] == arrivalVertex) continue;
		printf("%c", V[i]);

		if (V[i] == departureVertex) departureNum = i;

		vertexNum = i;
		while (V[vertexNum] != arrivalVertex) {
			vertexNum = P[vertexNum];
			printf(" -> %c", V[vertexNum]);
			if (V[i] == departureVertex) shortestPath[vertexCnt++] = V[vertexNum];
		}
		printf(", %d\n", D[i]);
	}

	printf("\n��� ���� %c���� ���� ���� %c���� �ִ� ��� �� �Ÿ� : ", departureVertex, arrivalVertex);
	printf("%c", departureVertex);
	for (i = 0; i < vertexCnt; i++)
		printf(" -> %c", shortestPath[i]);
	printf(", %d\n\n", D[departureNum]);

	return 0;
}