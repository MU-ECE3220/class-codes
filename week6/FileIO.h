#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

class FileIO {
	private:
		string filename;
	public:
		bool readFile(string file);
		bool writeFile(string file);
		bool readAndAddNumbersFromFile(string filename);

};

