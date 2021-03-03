#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      cout << "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 10;
   int y = 0;
   double z = 0;
   try{
   z = division(x, y);
   }
catch(exception &ex) {
	cout << "Exception: " << endl;
}
//   cout << z << endl;

   cout << "Muhahahahha I'm still alive!!!";

   return 0;
}
