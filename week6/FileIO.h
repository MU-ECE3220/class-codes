#include <iostream>
#include <fstream>

using namespace std;

class FileIO {
	private:
		string filename;
	public:
		bool readFile(string file);
		bool writeFile(string file);

};

