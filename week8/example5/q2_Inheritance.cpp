#include<iostream> 
   
using namespace std; 

class A { 
	public: 
		void print() { cout <<"I am in Class A" << endl; } 
}; 
   
class B : public A { 
	public: 
		void print() { cout <<"I am in Class B" << endl; } 
}; 
   
class C: public B { 
	public: 
		//void print() { cout <<"I am in Class C" << endl; } 
}; 
   
int main(void) 
{ 
	A a;
	a.print();
	B b;
	b.print();
	C c;  
	c.print(); 
	return EXIT_SUCCESS;
} 

