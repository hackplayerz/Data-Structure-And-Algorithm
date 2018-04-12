#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

//리스트는 문자형을 저장
typedef char element;

//리스트를 구조체로 선언
typedef struct {
	element list[MAX_LIST_SIZE]; // 리스트가 저장할 수 있는 최대 Index는 100개
	int lenght; // 리스트가 현재 사용중인 Index의 갯수
}ArrayListType;

//오류처리 함수
void error(char *message) {
	fprintf(stderr, "%s\n", *message);
	exit(1);
}
//리스트 초기화
void init(ArrayListType *List) {
	List->lenght = 0;
}

//리스트가 비어있으면 1을 반환
//아니면 0을 반환
int is_empty(ArrayListType *List) {
	return List->lenght == 0;
}
//리스트가 꽉 차있으면 1을 반환
//아니면 0을 반환
int is_full(ArrayListType *List) {
	return List->lenght == MAX_LIST_SIZE;
}

//리스트 아이템 출력
void display_List(ArrayListType *List) {
	for (int i = 0; i < List->lenght; i++) {
		printf("Index[%d] : %c\n", i,List->list[i]);
	}
}
//리스트에 아이템 추가
void addItem(ArrayListType *List, int position, element item) {

	if (!is_full(List) && position >= 0 && position<= List->lenght) {
		//리스트의 아이템을 position 앞까지 늘린다.
		for (int i = List->lenght; i >= position; i--) {
			List->list[i + 1] = List->list[i];
		}
		//리스트에 추가할 아이템의 값을 대입
		List->list[position] = item;
		//추가했으므로 리스트의 전체 길이는 1 증가
		List->lenght++;
	}
	if (is_full(List)) {
		error("리스트 초과");
	}
	if (position <= 0 && position >= List->lenght) {
		error("위치 오류");
	}
}
//리스트에서 아이템 삭제
element deleteItem(ArrayListType *List, int position) {
	//지울 아이템의 위치가 0보다 크고, 전체 길이보다 작아야 한다.
	if (position < 0 || position >= List->lenght) {
		error("설정된 위치의 값이 잘못되었습니다.");
	}
	//item변수에 제거할 item을 저장후 return 하여 제거
	element item;
	item = List->list[position];

	//리스트의 요소들중 바꿀 아이템의 위치부터 리스트의 끝 아이템의 위치까지 앞으로 이동
	for (int i = position; i < List->lenght-1; i++) {
		List->list[i] = List->list[i + 1];
	}
	//1개의 아이템이 없어졌으므로 아이템의 총 갯수는 lenght -1
	List->lenght--;

	return item;
}