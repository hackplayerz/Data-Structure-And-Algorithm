#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
	clock_t start, finish; // �ð��� ������ ����
	double duration;

	start = clock(); // ���۽ð� ����
	printf("ABCD\n");
	finish = clock; // ����ð� ����

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f �� �Դϴ�.\n", duration);
}