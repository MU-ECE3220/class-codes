#include "const_functions.h"

int sum_from_1_to_n(int const n) {
	int sum = 0;
	
	for(int i=1; i<=n; i++) {
		sum = sum + i;
	}
	return sum;
}

char const *path = "files/star_wars_script.txt";

int write_to_file() {
	FILE *file;
	file = fopen(path, "w");
	if(file == NULL) {
		printf("File error\n");
		return 1;
	}
	fprintf(file, "May the force be with you!\n");
	fclose(file);
	return 0;
}
