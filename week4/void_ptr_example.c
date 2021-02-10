#include<stdio.h>

int main() {
	int a = 5;
	char b = 'x';
	void *ptr;
	ptr = &a;
	printf("Int value %d\n",*(int*)ptr);
	ptr = NULL;
	ptr = &b;
	printf("Char value %c\n",*(char*)ptr);
	ptr = NULL;
	return 0;
}
