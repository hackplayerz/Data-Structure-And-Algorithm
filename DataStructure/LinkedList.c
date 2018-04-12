/* �ܼ� ���Ḯ��Ʈ ADT ���� */
#include <stdio.h>
#include <stdlib.h>	

typedef char element;
// Linked List �� �߻������� ����(abstract)
// Ʋ�� ��������Ƿ� Node(Data ����)�� ���� ������� ����
typedef struct {
	element data_Field;
	struct ListNode *Link_Field;
}ListNode;

void Insert_Node(ListNode **pHead, ListNode *previous_List, ListNode *new_Node);
void Delete_Node(ListNode **phead, ListNode *previous_Node, ListNode *delete_Node);
void Display_Node(ListNode *head);
ListNode *Contact_Node(ListNode *frontNode, ListNode *backNode);
void error(char *message);

ListNode *NodeSearch(ListNode *head, element searching_Data);
ListNode *create_Node(element data, ListNode *Linked_List);


void main() {
	ListNode *firstNode = NULL, *secondNode = NULL;
	ListNode *searchNode = NULL;

	printf("ù��° ����Ʈ ����\n");
	// firstNode : C -> B -> A
	Insert_Node(&firstNode, NULL, create_Node('A', NULL));
	Insert_Node(&firstNode, NULL, create_Node('B', NULL));
	Insert_Node(&firstNode, NULL, create_Node('C', NULL));
	Display_Node(firstNode);

	printf("0��° ����Ʈ�� ���� ����\n");
	// firstNode : B -> A
	Delete_Node(&firstNode,NULL,firstNode);
	Display_Node(firstNode);

	printf("�ι�° ����Ʈ ����\n");
	// secondNode : Z -> Y -> X
	Insert_Node(&secondNode, NULL, create_Node('X', NULL));
	Insert_Node(&secondNode, NULL, create_Node('Y', NULL));
	Insert_Node(&secondNode, NULL, create_Node('Z', NULL));
	Display_Node(secondNode);

	printf("����Ʈ ����\n");
	// firstNode�� secondNode�� firstNode�� ��ħ
	firstNode = Contact_Node(firstNode, secondNode);
	Display_Node(firstNode);

	printf("�����Ͱ� : X �� ��Ī\n");
	searchNode = NodeSearch(firstNode, 'X');
	printf("Ž�� ���� : %c\n", searchNode->data_Field);

	free(firstNode);
	free(secondNode);
	free(searchNode);
}

// ����Ʈ ����
ListNode *create_Node(element data, ListNode *Linked_List) {
	ListNode *new_Node;
	// �޸� ���� �Ҵ�
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	
	if (new_Node == NULL) {
		error("�޸� �Ҵ� �Ұ�");
	}

	// ��� �ʱ�ȭ
	new_Node->data_Field = data;
	new_Node->Link_Field = Linked_List;

	return new_Node;
}

// �ܼ� ���� ����Ʈ�� ����
void Insert_Node(ListNode **pHead,ListNode *previous_List, ListNode *new_Node) {
	if (*pHead == NULL) { // ���� ����Ʈ�ϰ�� �� ����Ʈ�� ���(head)�� �ȴ�
		new_Node->Link_Field = NULL;
		*pHead = new_Node;
	}
	else if (previous_List == NULL) { // �����尡 NULL�϶� �� �� �տ� ������ ��
		new_Node->Link_Field = *pHead;
		*pHead = new_Node;
	}
	else { // �Ϲ����� ����, ���� ���̿� ������ ��
		new_Node->Link_Field = previous_List->Link_Field;
		previous_List->Link_Field = new_Node;
	}
}

// �ܼ� ���� ����Ʈ�� ����
void Delete_Node(ListNode **phead, ListNode *previous_Node, ListNode *delete_Node) {
	if (previous_Node == NULL) { // �����ϴ� ����� ���� ��尡 ���� ��
		*phead = delete_Node->Link_Field;
	}
	else { // �߰��� ��带 �����Ҷ�
		previous_Node->Link_Field = delete_Node->Link_Field;
	}
	// ������ ����� �޸� �Ҵ� ����
	free(delete_Node);
}

// ����� ���� ���������� �湮�� ���
void Display_Node(ListNode *head) {
	ListNode *print_Node = head;
	int index = 0;
	while (print_Node != NULL) {
		printf("Index[%d] : %c -> ",index, print_Node->data_Field);
		// ���� ����� �����͸� ����� �� ����� ��尡 ������ �ִ� �ּҰ��� ���� ��忡 ������ ���� ���� �̵�
		print_Node = print_Node->Link_Field;
		index++;
	}
	printf("\n");
	printf("================================================\n\n");
}

// ����� ������ ���� Ž��
ListNode *NodeSearch(ListNode *head, element searching_Data) {
	ListNode *search_Node;
	search_Node = head;
	while (search_Node ->Link_Field != NULL) {
		if (search_Node->data_Field == searching_Data) {
			return search_Node;
		}
		search_Node = search_Node->Link_Field;
	}
	return search_Node; // ã�� ���Ұ�� NULL��ȯ
}

// �ΰ��� ��带 �ϳ��� ��ħ
ListNode *Contact_Node(ListNode *frontNode, ListNode *backNode) {
	ListNode *previous_Node;

	// ��ġ���� ��尡 ������ �״�� ��ȯ
	if (frontNode == NULL) {
		return backNode;
	}
	else if (backNode == NULL) {
		return frontNode;
	}
	else { // ���� ����� �ǳ� ���� �̵��� �� �� ��尡 ����Ű�� ���� ��ġ���� ����� ���(head)�� ����
		previous_Node = frontNode;
		while (previous_Node->Link_Field != NULL) {
			previous_Node = previous_Node->Link_Field;
		}
		previous_Node->Link_Field = backNode;
		// ������ ���� ������ �̹Ƿ� �����带 ��ȯ
		return frontNode;
	}
}

// ����ó��
void error(char *message) {
	printf("%s\n", message);
	exit(1);
}