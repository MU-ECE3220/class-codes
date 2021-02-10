#include "pointer_functions.h"
#include "math_functions.h"

int main() {
	
	/*
	void (*f_ptr)(int);
	void (*f_ptr)();
	f_ptr = function_ptr_1;
	f_ptr(0);
	f_ptr = function_ptr_2;
	f_ptr(5);
	
	function_ptr_all(f_ptr);
	*/
	
	float (*m_funcs[4])(float, float);
	
	m_funcs[0] = add;
	m_funcs[1] = sub;
	m_funcs[2] = div;
	m_funcs[3] = mul;
	
	int choice = 1;
	while(choice != -1) {
		scanf("%d", &choice);
		if(choice<6)
			printf("Result %f\n", m_funcs[choice](2.0,5.0));
		else
			fprintf(stderr, "Something went wrong\n");
	}
	return 0;
}
