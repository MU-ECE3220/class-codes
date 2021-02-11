#include "const_functions.h"

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Program expects 2 arguments, Example: ./const_example 5");
		return -1;
	}
	
	int n = atoi(argv[1]);
	printf("Output: %d\n", sum_from_1_to_n(n));
	write_to_file();
	return 0;
}
