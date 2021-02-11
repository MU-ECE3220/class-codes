#include "const_functions.h"

int sum_from_1_to_n (const int n) {
	int sum=0;
	
	/*
	int const *a;
	a = &n;
	*a = 5;*/
	for(int i=1; i<=n; i++) {
		sum = sum + i;
	}
	return sum;
}

char const *path="files/star_wars_script.txt";

int write_to_file() {
	FILE *file;
	file = fopen(path, "w+");
	if(file == NULL) {
		printf("Error\n");
		return 2;
	}
	fprintf(file, "May the force be with you!\n");
	fclose(file);
	return 0;
}
