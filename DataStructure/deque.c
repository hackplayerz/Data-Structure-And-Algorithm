#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef int boolean;

typedef struct DlistNode
{
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}DlistNode;

typedef struct DqueType
{
	DlistNode *head;
	DlistNode *tail;
}DqueType;

boolean isEmpty(DqueType *dq) {
	if (dq->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(DqueType *dq) {
	dq->head = NULL;
	dq->tail = NULL;
}

DlistNode *create(DlistNode *llink,element item,DlistNode *rlink) {
	DlistNode *newNode = (DlistNode *)malloc(sizeof(DlistNode));

	if (newNode == NULL) {
		error("메모리 생성 에러\n");
	}
	else {
		newNode->data = item;
		newNode->llink = llink;
		newNode->rlink = rlink;
		return newNode;
	}
}

void addRear(DqueType *dq, element data) {
	DlistNode *newNode = create(dq->tail,data,NULL);

	if (isEmpty(dq)) {
		dq->head = newNode;
	}
	else {
		dq->tail->rlink = newNode;
	}
	dq->tail = newNode;
}

void addFront(DqueType *dq, element data) {
	DlistNode *newNode = create(NULL, data, dq->head);
	if (isEmpty(dq)) {
		dq->tail = newNode;
	}
	else {
		dq->head->llink = newNode;
	}
	dq->head = newNode;
}
element deleteFront(DqueType *dq) {
	element item;
	DlistNode *deleteDeQue;

	if (isEmpty(dq)) {
		error("Deque is Empty\n");
	}
	else {
		deleteDeQue = dq->head;
		item = deleteDeQue->data;

		dq->head = dq->head->rlink;
		free(deleteDeQue);
		if (isEmpty(dq)) {
			dq->tail = NULL;
		}
		else
			dq->head->llink = NULL;
	}
	return item;
}

element deleteRear(DqueType *dq) {
	DlistNode *deleteNode;
	element item;

	if (isEmpty(dq)) {
		error("Deque is Empty\n");
	}
	else {
		deleteNode = dq->tail;
		item = deleteNode->data;
		dq->tail = dq->tail->llink;
		if (isEmpty(dq)) {
			dq->head = NULL;
		}
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

void display(DqueType *dq) {
	DlistNode *p;
	printf("(");
	for (p = dq->head; p!=NULL; p = p->rlink) {
		printf("%d", p->data);
	}
	printf(")\n");
}
void main() {
	DqueType deque;

	init(&deque);
	addFront(&deque, 10);
	addFront(&deque, 20);
	addRear(&deque, 30);
	display(&deque);

	deleteFront(&deque);
	deleteRear(&deque);
	display(&deque);
}