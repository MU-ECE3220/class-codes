
#include <iostream> 
using namespace std; 
  
int fun() { 
	throw 'c';
	throw 10;
} 
  
int main() { 

	try {
		fun();
	}
   	catch(char) {
		cerr << "Caught a character exception\n";
	}
	catch(int) {
		cerr << "Caught an integer exception\n";
	}

	return EXIT_SUCCESS;
} 

