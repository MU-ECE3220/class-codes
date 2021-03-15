#include <stdio.h>

void func();
//void func(int x);

int main(){

	func();
	//func(2);
	return 0;
}

void func(){
	printf("Test 0\n");
}
/*
void func(int x){
	printf("Test 1: %d\n",x);
}
*/


