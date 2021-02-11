#include "static_functions.h"

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Program requires 2 arguments, Example: ./static 2");
		return 1;
	}
	
	int n = atoi(argv[1]);
	for(int i=0; i<n; i++) {
		incrementor();
	}
	
	return 0;
}
