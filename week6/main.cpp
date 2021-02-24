#include "Student.h"
#include "FileIO.h"

int main () {

	string data;
	cout << "Enter file name with extension: ";
	//cin >> data;
	getline(cin, data);
	cout << "File name is: " << data << endl;

	FileIO file_obj;
	file_obj.writeFile(data);

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

	//Kids.. Don't try this at home
	//s1->~Student();

	delete s1; // free(s1);


	return 0;
}
