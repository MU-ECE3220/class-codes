#include<iostream>
#ifndef FELIDAE_H
#define FELIDAE_H
using namespace std;

class Felidae {
	public:
		void setSpecies(string species);
		string getSpecies();	
		virtual void makeSound();
		bool hunt();
	protected:
		string name;
		string species;
};
#endif
