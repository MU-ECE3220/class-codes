#include <iostream> 

using namespace std; 

int main() { 

	int x = -1;
	try {
		cout<< "Inside try block\n";
		if(x < 0) {
			throw x;
			cout << "After throw\n";
		}
	}
	catch(int x){
		cerr << "Exception caught: x=" << x << endl;
		return EXIT_FAILURE;
	}
	cout << "After catch\n";
	return EXIT_SUCCESS;
} 

