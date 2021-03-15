#include <iostream> 
using namespace std; 

class Parent { 
	public: 
		string parent_data; 
}; 
   
class Child : public Parent { 
	public: 
		string child_data;
};
  
int main() { 
	Child cObj;
	cObj.child_data = "Nooooooo!!!!!!";	
	cObj.parent_data = "I am your father Luke...";

	cout << "Darth Vader: " << cObj.parent_data << endl;
	cout << "Luke: " << cObj.child_data << endl;

	return 0; 
}
