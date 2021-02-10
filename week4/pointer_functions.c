#include "pointer_functions.h"

void function_ptr_1() {
	printf("Function Pointer #1\n");
}
void function_ptr_2(int counter) {
	for(int i=0; i<counter; i++){
		printf("Function Pointer #2\n");
	}
}

void function_ptr_all(void (*ptr)()) {
	ptr();
}
