#include<stdio.h>
#include<stdlib.h>    //�޸� �����̼� �Լ��� ���� ����

struct node {                // ���ο����� ���°� �ƴϱ� ������ ������ �غ�
	char data;
	struct node* link;
};

void deleteLinkedList(struct node* p) {
	if (p != NULL) {      //���ȣ��
		deleteLinkedList(p->link);
		printf("%c.", p->data);
		free(p);
	}
}

int main(void) {

	struct node* head;
	struct node* p = (struct node*)malloc(sizeof(struct node));
	char input = ' ';         //A �տ� �ǹ̾��� �ε� �ϳ� ����

	p->data = input;
	p->link = NULL;
	head = p;

	printf("������ �Է�: ");
	scanf_s("%c", &input, 1);
	getchar();

	while (input != '0') {
		p->link = (struct node*)malloc(sizeof(struct node));
		p = p->link;
		p->data = input;
		p->link = NULL;
		printf("������ �Է�: ");
		scanf_s("%c", &input, 1);
		getchar();
	}

	printf("\n���Ḯ��Ʈ ���: ");
	p = head->link;         //ù��° ��ȿ �����Ͱ� ��� �ִ� 

	while (p != NULL) {
		printf("%c", p->data);
		p = p->link;
		if (p != NULL)printf(" -> ");
	}
	printf("\n");

	printf("\n������� ����: ");
	deleteLinkedList(head);
	printf("\n");

	return 0;
}