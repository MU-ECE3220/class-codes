#include <iostream> 
#include<string> 

using namespace std; 
  
class Parent { 
	public: 
		virtual string print()
		{ 
			return "This is Parent class"; 
		} 
}; 
  
class Child : public Parent { 
	public: 	
		virtual string print()
		{ 
			return "This is Child class"; 
		} 
}; 
  
void describe(Parent c) {
	cout << c.print() << endl;
} 
  
int main() { 
	Parent p; 
	Child c;
	
	describe(p); 
	describe(c); 
	return EXIT_SUCCESS;
} 

