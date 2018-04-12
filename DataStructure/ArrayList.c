/* 
 * 자료구조 및 알고리즘 
 * 배열을 이용한 ADT 구현
 * Data Structure and Alogorithm
 * Array List ADT
 *
 * Code by Alter
 * github.com/hackplayerz
 */

#include "addArrayList.h"

/* 배열 리스트 ADT 함수 선언*/
//------------------------------------------------------------
void init(ArrayListType *List);
void display_List(ArrayListType *List);
void addItem(ArrayListType *List, int position, element item);
element deleteItem(ArrayListType *List, int position);
//------------------------------------------------------------

void main() {
	ArrayListType List;
	ArrayListType *pList;
	/*
	 *구조체를 정적으로 선언하고 구조체를		  
	 * 가르키는 포인터의 함수를 매개변수로 전달. 
	 */
	init(&List); // Reset

	addItem(&List, 0, 'A');
	// 이미 0번 Index에 값이 존재하므로 이미 존재했던 값을 1칸 밀고 0번 Index에 값을 대입
	addItem(&List, 0, 'B'); 
	display_List(&List); // print List item
	// 0번째 인덱스의 값을 제거
	printf("==============\n");
	deleteItem(&List, 0);
	display_List(&List);

	printf("==============\n");

	// 리스트를 동적 메모리로 할당
	pList = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(pList);
	addItem(pList, 0, 'X');
	addItem(pList, 1, 'Y');
	addItem(pList, 2, 'Z');
	display_List(pList);
	printf("==============\n");

	deleteItem(pList, 1);
	display_List(pList);
	free(pList); // 할당된 메모리 제거
}