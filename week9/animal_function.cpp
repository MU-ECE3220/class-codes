#include "animal_function.h"

int totalNumberOfLegs(vector<Animal> list) {
	int totalLegs = 0;
	for(int i=0; i<list.size(); i++) {
		totalLegs = totalLegs + list[i].countLegs();
	}
	return totalLegs;
}

int numOfDietType(vector<Animal> list, string dietType) {
	return 0;
}
