#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
	clock_t start, finish; // 시간을 저장할 변수
	double duration;

	start = clock(); // 시작시간 저장
	printf("ABCD\n");
	finish = clock; // 종료시간 저장

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초 입니다.\n", duration);
}