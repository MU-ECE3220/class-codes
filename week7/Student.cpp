#include "Student.h"
#include "Singleton.h"

using namespace std;


		// setter and getter functions
void Student::setSSN(int inputSSN) {
	if(0 >= inputSSN) {
		cout << "INVALID SSN" << endl; // printf
	}
	else {
		this->SSN = inputSSN;
	}
}

int Student::getSSN() {
	return this->SSN;
}

void Student::setName(string name) {
	this->name = name;
}

void Student::setAge(int age) {
	this->age = age;
}

string Student::getName() {
	return this->name;
}

int Student::getAge() {
	return this->age;
}

// Default constructor
Student::Student() {
	// Call the Single object and read function here
	cout<< "Student: "<< name << endl;
	Singleton::getInstance()->getFile().readFile();
}

// Parameterized Constuctor
Student::Student(string name, int age) {
	this->name = name;
	this->age = age;
	cout<< "Student: "<< name << endl;
	Singleton::getInstance()->getFile().readFile();
}

// Copy constructor
Student::Student(Student &s) {
	this->name = s.name;
	this->age = s.age;
}

// Destructor
Student::~Student() { 
	cout << "Destructor triggered for " << this->name << endl;
	cout << "Destructor triggered for " << name << endl;
}

