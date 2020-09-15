#include<stdio.h>
#include<stdlib.h>    //메모리 로테이션 함수가 여기 있음

struct node {                // 메인에서만 쓰는게 아니기 때문에 전역에 준비
	char data;
	struct node* link;
};

void deleteLinkedList(struct node* p) {
	if (p != NULL) {      //재귀호출
		deleteLinkedList(p->link);
		printf("%c.", p->data);
		free(p);
	}
}

int main(void) {

	struct node* head;
	struct node* p = (struct node*)malloc(sizeof(struct node));
	char input = ' ';         //A 앞에 의미없는 로드 하나 있음

	p->data = input;
	p->link = NULL;
	head = p;

	printf("데이터 입력: ");
	scanf_s("%c", &input, 1);
	getchar();

	while (input != '0') {
		p->link = (struct node*)malloc(sizeof(struct node));
		p = p->link;
		p->data = input;
		p->link = NULL;
		printf("데이터 입력: ");
		scanf_s("%c", &input, 1);
		getchar();
	}

	printf("\n연결리스트 출력: ");
	p = head->link;         //첫번째 유효 데이터가 들어 있는 

	while (p != NULL) {
		printf("%c", p->data);
		p = p->link;
		if (p != NULL)printf(" -> ");
	}
	printf("\n");

	printf("\n사라지는 순서: ");
	deleteLinkedList(head);
	printf("\n");

	return 0;
}