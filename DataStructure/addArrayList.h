#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

//����Ʈ�� �������� ����
typedef char element;

//����Ʈ�� ����ü�� ����
typedef struct {
	element list[MAX_LIST_SIZE]; // ����Ʈ�� ������ �� �ִ� �ִ� Index�� 100��
	int lenght; // ����Ʈ�� ���� ������� Index�� ����
}ArrayListType;

//����ó�� �Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", *message);
	exit(1);
}
//����Ʈ �ʱ�ȭ
void init(ArrayListType *List) {
	List->lenght = 0;
}

//����Ʈ�� ��������� 1�� ��ȯ
//�ƴϸ� 0�� ��ȯ
int is_empty(ArrayListType *List) {
	return List->lenght == 0;
}
//����Ʈ�� �� �������� 1�� ��ȯ
//�ƴϸ� 0�� ��ȯ
int is_full(ArrayListType *List) {
	return List->lenght == MAX_LIST_SIZE;
}

//����Ʈ ������ ���
void display_List(ArrayListType *List) {
	for (int i = 0; i < List->lenght; i++) {
		printf("Index[%d] : %c\n", i,List->list[i]);
	}
}
//����Ʈ�� ������ �߰�
void addItem(ArrayListType *List, int position, element item) {

	if (!is_full(List) && position >= 0 && position<= List->lenght) {
		//����Ʈ�� �������� position �ձ��� �ø���.
		for (int i = List->lenght; i >= position; i--) {
			List->list[i + 1] = List->list[i];
		}
		//����Ʈ�� �߰��� �������� ���� ����
		List->list[position] = item;
		//�߰������Ƿ� ����Ʈ�� ��ü ���̴� 1 ����
		List->lenght++;
	}
	if (is_full(List)) {
		error("����Ʈ �ʰ�");
	}
	if (position <= 0 && position >= List->lenght) {
		error("��ġ ����");
	}
}
//����Ʈ���� ������ ����
element deleteItem(ArrayListType *List, int position) {
	//���� �������� ��ġ�� 0���� ũ��, ��ü ���̺��� �۾ƾ� �Ѵ�.
	if (position < 0 || position >= List->lenght) {
		error("������ ��ġ�� ���� �߸��Ǿ����ϴ�.");
	}
	//item������ ������ item�� ������ return �Ͽ� ����
	element item;
	item = List->list[position];

	//����Ʈ�� ��ҵ��� �ٲ� �������� ��ġ���� ����Ʈ�� �� �������� ��ġ���� ������ �̵�
	for (int i = position; i < List->lenght-1; i++) {
		List->list[i] = List->list[i + 1];
	}
	//1���� �������� ���������Ƿ� �������� �� ������ lenght -1
	List->lenght--;

	return item;
}