#include <iostream>
#include <string>
#include<fstream>

using namespace std;

void anErrorFunc(const string& x) {
	ifstream file;
	file.open(x);
	if(!file)
		throw runtime_error("Variable x: could not open file\n");	
}

void someOtherFunction(const std::string& y) {
	// Do stuff
	anErrorFunc(y);
	// Do more stuff
}

int main() {
	try{
		someOtherFunction("numberss.txt");
	} catch(exception &ex) {
		cout << "Ouch! That hurts, because of: " << ex.what();
	}
	return EXIT_SUCCESS;
}
