#include "Singleton.h"
#include "Student.h"

int main () {

	string data;
	cout << "Enter file name with extension: ";
	getline(cin, data);
	cout << "File name is: " << data << endl;

	FileIO file_obj;
	//set file name
	file_obj.setFileName(data);

	if(file_obj.writeFile()) {
		cout << "File created successfully!\n"; 	
	}
	else {
		cout << "File operation failed!\n";
	}

	// Set the file name through the Singleton object
	Singleton::getInstance()->setFile(file_obj);
	Singleton::getInstance()->getFile().readFile();


	return EXIT_SUCCESS;
}


