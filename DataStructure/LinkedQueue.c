#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

typedef char element;
typedef int boolean;
typedef struct QNode
{
	element data;
	struct QNode *link;
}QNode;

typedef struct LQueueType
{
	QNode *front, *rear;
}LQueueType;

LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

boolean isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf("@Err : Queue is Empty!\n");
		return TRUE;
	}
	else
		return FALSE;
}

void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	element item;
	if (isEmpty(LQ))
		return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) {
			LQ->rear = NULL;
		}
		free(old);
		return item; 
	}
}
element peek(LQueueType *LQ) {
	element item;
	if (isEmpty(LQ))
		return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf("Linked Queue : [");
	while (temp)
	{
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf("]");
}

void main() {
	LQueueType *LQ = createLinkedQueue();
	element data;
	printf("\n************ ���� ť ���� ************\n");
	printf("\n ���� A >>");
	enQueue(LQ, 'A');
	printLQ(LQ);
	printf("\n ���� B >>");
	enQueue(LQ, 'B');
	printLQ(LQ);
	printf("\n ���� C >>");
	enQueue(LQ, 'C');
	printLQ(LQ);

	data = peek(LQ);
	printf("Peek item : %c\n", data);
	
	printf("\n ����>>");
	data = deQueue(LQ);
	printLQ(LQ);
	printf("\t ���� ������ : %c", data);
	printf("\n ����>>");
	data = deQueue(LQ);
	printLQ(LQ);
	printf("\t ���� ������ : %c", data);
	printf("\n ����>>");
	data = deQueue(LQ);
	printLQ(LQ);
	printf("\t ���� ������ : %c", data);

	printf("\n ���� D>>");
	enQueue(LQ, 'D');
	printLQ(LQ);
	printf("\n ���� E>>");
	enQueue(LQ, 'E');
	printLQ(LQ);
	printf("\n");
}