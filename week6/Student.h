#include <iostream>

using namespace std;

// class == struct
class Student {
	private:
		int SSN;
	public:
		string name;
		int age;
		
		// setter and getter functions
		void setSSN(int inputSSN);
		
		int getSSN();
		
		void setName(string name);
		
		void setAge(int age);
		
		string getName();
		
		int getAge();
		
		// Default constructor
		Student();
	
		// Parameterized Constuctor
		Student(string name, int age);
		
		// Copy constructor
		Student(Student &s);
		
		// Destructor
		~Student();
};
