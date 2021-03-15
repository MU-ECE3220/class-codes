#include <iostream>
 
using namespace std;


class Shape {
   public:
	string shapeType = "NO SPECIFIC TYPE";
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      int getWidth() {
         return width;
      }
      int getHeight() {
         return height;
      }
	void printShapeType() {
		cout << "My shape is: " << shapeType << endl;
	}
      
   protected:
      int width;
      int height;
};

class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
	Rectangle() {
		shapeType = "Rectangle";
	}
};

class Square : public Shape {
	public:
		int getArea(){
			if(height != width) {
				cerr << "height=" << height <<" and width=" << width <<" are not equal!" << endl;
				throw this;
			}
			return (width * height);		
		}
		Square(){
			shapeType = "Square";
		}
};


int main() {
	Rectangle rect;
	rect.setWidth(5);
	rect.setHeight(3);
	rect.printShapeType();
	cout << "Area: " << rect.getArea() << endl; 

	Square *sq = new Square;
	try {
		sq->setWidth(3);
		sq->setHeight(5);
		cout << "Area: " << sq->getArea() << endl; 
	}
	catch(Shape *s) {
		cerr << "Exception caught! " << endl;
		s->printShapeType();
	}
	sq->printShapeType();
	
	delete sq;

	return EXIT_SUCCESS;
}











