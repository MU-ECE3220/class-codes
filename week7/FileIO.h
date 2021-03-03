#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

class FileIO {
	private:
		string filename;
	public:
		bool readFile();
		bool writeFile();
		bool readAndAddNumbersFromFile(string filename);
		void setFileName(string filename);
		string getFileName();
};

