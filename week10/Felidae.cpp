#include"Felidae.hpp"

void Felidae::makeSound() {
	cout << species << " says: "<< "ROAAAR!!!" << endl;
}

void Felidae::setSpecies(string species) {
	this->species = species;
}

string Felidae::getSpecies() {
	return this->species;
}

bool Felidae::hunt() {
	// Write something here.
	return false;
}
