#include "LinkedListADT.h"

void InsertFirst(ListNode **pHead, ListNode *insertNode);
void InsertLast(ListNode **pHead, ListNode *insertNode);

void main() {
	ListNode *firstNode = NULL;

	//firstNode : 30 -> 20 -> 10
	InsertFirst(&firstNode, CreateNode('A', NULL));
	InsertFirst(&firstNode, CreateNode('B', NULL));
	InsertLast(&firstNode, CreateNode('C', NULL));

	display(firstNode);
}

void InsertFirst(ListNode **pHead, ListNode *insertNode) {
	if (*pHead == NULL) {
		*pHead = insertNode;
		(*pHead)->link_Field = insertNode;
	}
	else {
		insertNode->link_Field = (*pHead)->link_Field;
		(*pHead)->link_Field = insertNode;
	}
}

void InsertLast(ListNode **pHead, ListNode *insertNode) {
	if (*pHead == NULL) {
		*pHead = insertNode;
		(*pHead)->link_Field = insertNode;
	}
	else {
		insertNode->link_Field = (*pHead)->link_Field;
		(*pHead)->link_Field = insertNode;
		*pHead = insertNode;
	}
}