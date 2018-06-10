#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef int boolean;
//define Node to Struct
typedef struct stackName
{
	element data;
	struct stackName *link;
}stackNode;
stackNode *top;

boolean isEmpty();
void push(element item);
element pop();
element peek();
void displayStack();


void main() {
	element item;
	top = NULL;
	printf("\n**연걸 스택 연산**\n");
	displayStack();

	push(1);
	displayStack();
	push(2);
	displayStack();
	push(3);
	displayStack();

	printf("\n\n");

	item = peek();
	displayStack();
	printf("\t Peek => %d", item);

	item = pop();
	displayStack();
	printf("\t POP  => %d", item);

	item = pop();
	displayStack();
	printf("\t POP  => %d", item);

	item = pop();
	displayStack();
	printf("\t POP  => %d\n", item);
}

// Scanning Stack is Empty
boolean isEmpty() {
	if (top == NULL)
		return TRUE;
	else
		return FALSE;
}

// Release Top item
element pop() {
	element getItem;
	stackNode *releasedStack = top;

	if (isEmpty()) {
		printf("@Err : Stack is Empty");
		return 0;
	}
	else
	{
		getItem = top->data;
		top = releasedStack->link;
		free(releasedStack);
		return getItem;
	}
}

// Show Stack's Element
void displayStack() {
	stackNode *getStack = top;
	printf("\nStack [");
	while (getStack) {
		printf("%d", getStack->data);
		getStack = getStack->link;
	}
	printf("]");
}

// Get Top item
element peek() {
	if (isEmpty()) {
		printf("@Err : Stack is Empty");
		return 0;
	}
	else
	{
		return (top->data);
	}
}

// Input new Element to stack
void push(element item) {
	stackNode *newStack = (stackNode *)malloc(sizeof(stackNode));
	newStack->data = item;
	newStack->link = top;
	top = newStack;
}
