/* 
 * �ڷᱸ�� �� �˰��� 
 * �迭�� �̿��� ADT ����
 * Data Structure and Alogorithm
 * Array List ADT
 *
 * Code by Alter
 * github.com/hackplayerz
 */

#include "addArrayList.h"

/* �迭 ����Ʈ ADT �Լ� ����*/
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
	 *����ü�� �������� �����ϰ� ����ü��		  
	 * ����Ű�� �������� �Լ��� �Ű������� ����. 
	 */
	init(&List); // Reset

	addItem(&List, 0, 'A');
	// �̹� 0�� Index�� ���� �����ϹǷ� �̹� �����ߴ� ���� 1ĭ �а� 0�� Index�� ���� ����
	addItem(&List, 0, 'B'); 
	display_List(&List); // print List item
	// 0��° �ε����� ���� ����
	printf("==============\n");
	deleteItem(&List, 0);
	display_List(&List);

	printf("==============\n");

	// ����Ʈ�� ���� �޸𸮷� �Ҵ�
	pList = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(pList);
	addItem(pList, 0, 'X');
	addItem(pList, 1, 'Y');
	addItem(pList, 2, 'Z');
	display_List(pList);
	printf("==============\n");

	deleteItem(pList, 1);
	display_List(pList);
	free(pList); // �Ҵ�� �޸� ����
}