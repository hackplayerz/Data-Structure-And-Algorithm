/* 단순 연결리스트 ADT 구현 */
#include <stdio.h>
#include <stdlib.h>	

typedef char element;
// Linked List 를 추상적으로 선언(abstract)
// 틀만 만들었으므로 Node(Data 상자)는 아직 선언되지 않음
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

	printf("첫번째 리스트 생성\n");
	// firstNode : C -> B -> A
	Insert_Node(&firstNode, NULL, create_Node('A', NULL));
	Insert_Node(&firstNode, NULL, create_Node('B', NULL));
	Insert_Node(&firstNode, NULL, create_Node('C', NULL));
	Display_Node(firstNode);

	printf("0번째 리스트의 값을 제거\n");
	// firstNode : B -> A
	Delete_Node(&firstNode,NULL,firstNode);
	Display_Node(firstNode);

	printf("두번째 리스트 생성\n");
	// secondNode : Z -> Y -> X
	Insert_Node(&secondNode, NULL, create_Node('X', NULL));
	Insert_Node(&secondNode, NULL, create_Node('Y', NULL));
	Insert_Node(&secondNode, NULL, create_Node('Z', NULL));
	Display_Node(secondNode);

	printf("리스트 병합\n");
	// firstNode와 secondNode를 firstNode로 합침
	firstNode = Contact_Node(firstNode, secondNode);
	Display_Node(firstNode);

	printf("데이터값 : X 를 서칭\n");
	searchNode = NodeSearch(firstNode, 'X');
	printf("탐색 성공 : %c\n", searchNode->data_Field);

	free(firstNode);
	free(secondNode);
	free(searchNode);
}

// 리스트 생성
ListNode *create_Node(element data, ListNode *Linked_List) {
	ListNode *new_Node;
	// 메모리 동적 할당
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	
	if (new_Node == NULL) {
		error("메모리 할당 불가");
	}

	// 요소 초기화
	new_Node->data_Field = data;
	new_Node->Link_Field = Linked_List;

	return new_Node;
}

// 단순 연결 리스트의 삽입
void Insert_Node(ListNode **pHead,ListNode *previous_List, ListNode *new_Node) {
	if (*pHead == NULL) { // 공백 리스트일경우 즉 리스트의 헤드(head)가 된다
		new_Node->Link_Field = NULL;
		*pHead = new_Node;
	}
	else if (previous_List == NULL) { // 선행노드가 NULL일때 즉 맨 앞에 삽입할 때
		new_Node->Link_Field = *pHead;
		*pHead = new_Node;
	}
	else { // 일반적인 삽입, 노드들 사이에 삽입할 때
		new_Node->Link_Field = previous_List->Link_Field;
		previous_List->Link_Field = new_Node;
	}
}

// 단순 연결 리스트의 삭제
void Delete_Node(ListNode **phead, ListNode *previous_Node, ListNode *delete_Node) {
	if (previous_Node == NULL) { // 제거하는 노드의 선행 노드가 없을 때
		*phead = delete_Node->Link_Field;
	}
	else { // 중간의 노드를 제거할때
		previous_Node->Link_Field = delete_Node->Link_Field;
	}
	// 제거한 노드의 메모리 할당 제거
	free(delete_Node);
}

// 노드의 값을 순차적으로 방문해 출력
void Display_Node(ListNode *head) {
	ListNode *print_Node = head;
	int index = 0;
	while (print_Node != NULL) {
		printf("Index[%d] : %c -> ",index, print_Node->data_Field);
		// 현재 노드의 데이터를 출력한 뒤 출력한 노드가 가지고 있는 주소값을 현재 노드에 대입해 다음 노드로 이동
		print_Node = print_Node->Link_Field;
		index++;
	}
	printf("\n");
	printf("================================================\n\n");
}

// 노드의 데이터 값을 탐색
ListNode *NodeSearch(ListNode *head, element searching_Data) {
	ListNode *search_Node;
	search_Node = head;
	while (search_Node ->Link_Field != NULL) {
		if (search_Node->data_Field == searching_Data) {
			return search_Node;
		}
		search_Node = search_Node->Link_Field;
	}
	return search_Node; // 찾지 못할경우 NULL반환
}

// 두개의 노드를 하나로 합침
ListNode *Contact_Node(ListNode *frontNode, ListNode *backNode) {
	ListNode *previous_Node;

	// 합치려는 노드가 없을때 그대로 반환
	if (frontNode == NULL) {
		return backNode;
	}
	else if (backNode == NULL) {
		return frontNode;
	}
	else { // 선행 노드의 맨끝 까지 이동후 맨 끝 노드가 가리키는 값을 합치려는 노드의 헤드(head)로 지정
		previous_Node = frontNode;
		while (previous_Node->Link_Field != NULL) {
			previous_Node = previous_Node->Link_Field;
		}
		previous_Node->Link_Field = backNode;
		// 합쳐진 노드는 선행노드 이므로 선행노드를 반환
		return frontNode;
	}
}

// 오류처리
void error(char *message) {
	printf("%s\n", message);
	exit(1);
}