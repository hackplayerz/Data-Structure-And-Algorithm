#include <stdio.h>

int recursive(int n);
void main() {
	printf("%d\n",recursive(5));
}

int recursive(int n) {
	printf("%d\n", n);
	if (n < 1)
		return 2;
	else {
		return (2 * recursive(n - 1) + 1);
	}
}