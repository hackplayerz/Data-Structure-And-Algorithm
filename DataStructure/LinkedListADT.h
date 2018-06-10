#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct {
	element data_Field;
	struct ListNode *link_Field;
}ListNode;

void display(ListNode *head);
void Error(char *message);
ListNode *CreateNode(element data, ListNode *linked_Address);

ListNode *CreateNode(element data, ListNode *linked_Address) {
	ListNode *newNode;
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		Error("메모리 오류");
	}
	newNode->data_Field = data;
	newNode->link_Field = linked_Address;
	return newNode;
}

void display(ListNode *head) {
	ListNode *listHead;

	if (head == NULL)
		return;

	listHead = head;

	do {
		printf("%c -> ", listHead->data_Field);
		listHead = listHead->link_Field;
	} while (listHead != NULL);
}

void Error(char *message) {
	printf("%s\n", message);
	exit(1);
}