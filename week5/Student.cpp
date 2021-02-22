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
		void setSSN(int inputSSN) {
			if(0 >= inputSSN) {
				cout << "INVALID SSN" << endl; // printf
			}
			else {
				/**
					this->SSN ==> attribute above in private
					inputSSN ==> is the parameter
				**/
				this->SSN = inputSSN;
			}
		}
		
		int getSSN() {
			return this->SSN;
		}
		
		void setName(string name) {
			this->name = name;
		}
		
		void setAge(int age) {
			this->age = age;
		}
		
		string getName() {
			return this->name;
		}
		
		int getAge() {
			return this->age;
		}
		
		// Default constructor
		Student() { }
	
		// Parameterized Constuctor
		Student(string name, int age) {
			this->name = name;
			this->age = age;
		} 
		
		// Copy constructor
		Student(Student &s) {
			this->name = s.name;
			this->age = s.age;
		}
		
		// Destructor
		~Student() { 
			cout << "Destructor triggered for " << this->name << endl;
			cout << "Destructor triggered for " << name << endl;
		}
};

int main () {

	Student *s1 = new Student("Ekin", 20);
	// endl == "\n"
	cout << s1->getName() << ", " << s1->getAge() << "\n";	
	cout << s1->name << ", " << s1->age << endl;
	
	Student s2("Alice", 15);
	cout << s2.getName() << ", " << s2.getAge() << endl;	
	cout << s2.name << ", " << s2.age << endl;
	
	Student s3("Jake", 23);
	s3.setSSN(1233456);
	cout << s3.getName() << ", " << s3.getAge() << endl;	
	cout << s3.name << ", " << s3.age << s3.getSSN() << endl;

	
	//s1->~Student();
	delete s1; // free(s1);


	return 0;
}


























