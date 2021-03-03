#include <iostream> 
using namespace std; 

int main() { 

	try{
		throw "MIZ!";
	}
	catch(...) {
		cerr << "Default exception!\n";
	}
	return EXIT_SUCCESS;
} 

