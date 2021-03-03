#include <iostream>
#include "FileIO.h"

using namespace std;

class Singleton {
	private:
		static Singleton *instance;
		FileIO file;
		Singleton(){};
	public:
		static Singleton* getInstance();
		FileIO getFile();
		void setFile(FileIO file);
};
