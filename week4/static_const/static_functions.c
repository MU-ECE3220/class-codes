#include "static_functions.h"

static void incrementor_2() {
	static int x = 5;
	x++;
	printf("Value: %d\n",x);
}

void incrementor() {
	incrementor_2();
}
