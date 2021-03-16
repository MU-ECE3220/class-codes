#include "Dog.h"
#include "Gorilla.h"
#include "animal_function.h"

int main() {

	Dog *d1 = new Dog(4, "Everything", "Dog");

	Dog *d2 = new Dog(4, "Everything", "Dog");

	Gorilla *g1 = new Gorilla(6, "Vegeterian", "Gorilla");
	
	vector<Animal> animals;
	animals.push_back(*d1);
	animals.push_back(*d2);
	animals.push_back(*g1);

	cout << "Legs=" << totalNumberOfLegs(animals) << endl;
	return EXIT_SUCCESS;
}
