#include<iostream> 
   
using namespace std; 
class A { 
 public: 
     A(){ cout << "Class A's constructor is called" << endl;  } 
}; 
   
class B : public A { 
 public: 
     B(){ cout << "Class B's constructor is called" << endl;  } 
}; 
   
class C: public A, public B { 
   public: 
     C(){  cout << "Class C's constructor is called" << endl;  } 
}; 
   
int main() 
{ 
   C c; 
   return EXIT_SUCCESS;
} 

