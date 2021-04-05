#include <iostream>

using namespace std;

class Parent {
	public:
		Parent(){
			cout << "Parent Constructor" << endl;
		}
		virtual ~Parent(){
			cout << "Destructing Parent" << endl;
		}
		void print(){
			cout << "Parent Constructor" << endl;
		}

};

class A : public Parent {
	public:
		A(){
			cout << "A Constructor" << endl;
		}
};

class B : public Parent {
	public:
		B(){
			cout << "B Constructor" << endl;
		}
};

class C : public A, public B {
	public:
		C(){
			cout << "C Constructor" << endl;
		}
};

int main() {
	C c;
	c.print();
	return EXIT_SUCCESS;
}
