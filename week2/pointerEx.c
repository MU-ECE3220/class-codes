#include<stdio.h>

// prototype of function square
void square(int*);

//int x;

int main(){

	int *p;
	int x;
	
	x = 5;
	p = &x;

	printf("Address of x: %p\n", &x);
	printf("Address of p: %p\n", p);
	square(p);

	printf("Value of x: %d\n", x);
	printf("Value of p: %d\n", *p);

	return 0;

}

void square(int *val){
	*val = (*val) * (*val);
}
