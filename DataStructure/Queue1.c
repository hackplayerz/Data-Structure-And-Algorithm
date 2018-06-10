#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef int boolean;

typedef struct QueueNode
{
	element item;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) {
	q->front = NULL;
	q->rear = NULL;
}

boolean isEmpty(QueueType *q) {
	return q->front == NULL;
}

// 삽입 - FIFO
void enqueue(QueueType *q,element data) {
	QueueNode *newQueue = (QueueNode *)malloc(sizeof(QueueNode));
	if (newQueue == NULL) {
		error("메모리 생성 에러");
	}
	else {
		newQueue->item = data;
		newQueue->link = NULL;
		if (isEmpty(q)) {
			q->front = newQueue;
			q->rear = newQueue;
		}
		else {
			q->rear->link = newQueue;
			q->rear = newQueue;
		}
	}
}

//삭제
element dequeue(QueueType *q) {
	QueueNode *getQueue = q->front;
	element data;
	if (isEmpty(q)) {
		error("스택이 비었습니다.\n");
	}
	else {
		data = getQueue->item;
		q->front = q->front->link;
		if (q->front == NULL) {
			q->rear = NULL;
		}
		free(getQueue);
		return data;
	}
}
element peek(QueueType *q) {
	if (isEmpty(q)) {
		error("Stak is Empty\n");
	}
	else {
		return q->front->item;
	}
}
void main() {
	QueueType q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("deQueue() = %d\n", dequeue(&q));
	printf("deQueue() = %d\n", dequeue(&q));
	printf("deQueue() = %d\n", dequeue(&q));
}