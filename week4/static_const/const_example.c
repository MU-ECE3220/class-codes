#include "const_functions.h"

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Program requires 2 arguments\n");
		return 2;
	}
	
	int n = atoi(argv[1]);
	printf("Output is: %d\n", sum_from_1_to_n(n));
	write_to_file();
	return 0;
}
