//#include "felidae.hpp"
#include "Kitten.hpp"
#include "Tiger.hpp"

int main(){
	Felidae *f1;
	Felidae *f2;

	//Kitten *k = new Kitten();
	Kitten k;
	k.setSpecies("Meowth");
	k.makeSound();
	//*f1 = k;
	//f1->makeSound();

	Tiger *t = new Tiger();
	t->setSpecies("Truman");
	f2 = t;
	f2->makeSound();
	return 0;
}
