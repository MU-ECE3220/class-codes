#include <iostream>
using namespace std;

// a/b
double division(int a, int b) {

	cout << "Performing division\n";
	if(b == 0) {
		throw "Division by zero\n";
	}
	return a/b;
}

int main () {
	int a=5, b=0;
	cout << "Before division\n";
	try{
		division(a, b);
	}
	catch(const char*msg) {
		cerr << msg << endl;
	}
	cout << "Hahahaha I'm alive!!\n";
	return EXIT_SUCCESS;
}
