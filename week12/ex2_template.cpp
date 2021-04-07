#include<iostream>

using namespace std;

// Implement a template for a class attribute
// Define a class first
template <class F>
class MyTemplate {
	private: 
		F element;
	public:
		MyTemplate(F arg) {
			element = arg;
		}
		F getElement() {
			return element;		
		}
		void setElement(F elem) {
			element = elem;
		}
};


class Student {
	private:
		string studentName;
		int studentID;
		double studentGPA;
	public:		
		Student(){}

		string getStudentName() const {return studentName;}
		int getStudentID() const {return studentID;}
		double getStudentGPA() const {return studentGPA;}
		
		void setStudentName(string name) {studentName=name;}
		void setStudentID(int id) {studentID=id;}
		void setStudentGPA(double gpa) {studentGPA=gpa;}
};

class Teacher {
	private:
		string teacherName;
		int teacherID;
	public:		
		Teacher(){}

		string getTeacherName() const {return teacherName;}
		int getTeacherID() const {return teacherID;}
		
		void setTeacherName(string name) {teacherName=name;}
		void setTeacherID(int id) {teacherID=id;}
};

// override operator

ostream& operator<<(ostream &strm, const Teacher &t) {
	return strm << "Teacher(" << t.getTeacherName() << ", " << t.getTeacherID() << ")";
}

ostream& operator<<(ostream &strm, const Student &s) {
	return strm << "Student(" << s.getStudentName() << ", " << s.getStudentID() << ", " << s.getStudentGPA() << ")";
}

int main ()
{
	MyTemplate<string> mt1("name");
	cout << mt1.getElement() << endl;

	Teacher t1;
	t1.setTeacherName("Ekincan");
	t1.setTeacherID(123);

	MyTemplate<Teacher> mt2(t1);
	cout << mt2.getElement() << endl;

	Student s1;
	s1.setStudentName("John");
	s1.setStudentID(101);
	s1.setStudentGPA(4.00);

	MyTemplate<Student> mt3(s1);
	cout << mt3.getElement() << endl;
	

	return EXIT_SUCCESS;
}





