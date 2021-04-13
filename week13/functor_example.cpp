#include<iostream>

using namespace std;

class MyArithmeticFunctor {
	public:
		MyArithmeticFunctor() {}
		virtual double operator ()(double leftOp, double rightOp) = 0;
		double arithmetic_op(double leftOp, double rightOp, MyArithmeticFunctor *arit_func) {
			return (*arit_func)(leftOp, rightOp);
		}
};

class Add: public MyArithmeticFunctor {
	public:
		Add(){}
		virtual double operator ()(double leftOp, double rightOp){ return leftOp + rightOp; }
};

class Subtract: public MyArithmeticFunctor {
	public:
		Subtract(){}
		virtual double operator ()(double leftOp, double rightOp){ return leftOp - rightOp; }
};

class Divide: public MyArithmeticFunctor {
	public:
		Divide(){}
		virtual double operator ()(double leftOp, double rightOp){ return leftOp / rightOp; }
};

class Multiply: public MyArithmeticFunctor {
	public:
		Multiply(){}
		virtual double operator ()(double leftOp, double rightOp){ return leftOp * rightOp; }
};



int main() {
	double a = 2.0;
	double b = 3.6;
	MyArithmeticFunctor *may;
	MyArithmeticFunctor *fAdd = new Add();

	MyArithmeticFunctor *fDiv = new Divide();

	cout << "Div: " << may->arithmetic_op(a, b, fAdd) << endl;
	cout << "Div: " << may->arithmetic_op(a, b, fDiv) << endl;
	return EXIT_SUCCESS;
}













