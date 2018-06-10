#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef int boolean;

typedef struct stack {
	element data;
	struct stack *linkedStack;
}stackNode;
stackNode *top;

boolean isEmpty();
element pop();
element peek();
void push(element inputData);
void displayStack();

void main()
{
	top = NULL;
	push(1);
	displayStack();
	push(2);
	displayStack();

	printf("pop item is : %d\n", pop());
	displayStack();
}

boolean isEmpty() {
	if (top == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void push(element inputData) {
	stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));

	newNode->data = inputData;
	newNode->linkedStack = top;
	top = newNode;
}

element pop() {
	stackNode *releaseStack = top;
	element returnData;

	if (isEmpty()) {
		printf("@Err : Stack is Empty!\n");
		exit(1);
	}
	else {
		returnData = top->data;
		top = releaseStack->linkedStack;
		free(releaseStack);

		return returnData;
	}
}
element peek() {
	if (isEmpty()) {
		printf("@Err : Stack is Empty!\n");
		exit(TRUE);
	}
	else {
		return top->data;
	}
}

void displayStack() {
	stackNode *displayNode = top;
	if (isEmpty()) {
		printf("@Err : Stack is Empty!\n");
	}
	else {
		printf("===============\n");
		while (displayNode) {
			printf("Element is : %d\n", displayNode->data);
			displayNode = displayNode->linkedStack;
		}
	}
	free(displayNode);
}