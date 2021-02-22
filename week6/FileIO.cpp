#include "FileIO.h"


/*
	TODO: readFile(string) not implemented
	      This function should read the file and print it
		return 0 on fail
		return 1 on success
*/
bool FileIO::readFile(string file) {
	return false;
}

bool FileIO::writeFile(string file) {
	ofstream my_file;
	my_file.open(file);
	my_file << "Die, DIE. Why won't you die\n";
	my_file << "Beneath this mask there is more than flesh, Beneath this mask there is an idea, Mr. Creedy, and ideas are bulletproof.\n";
	my_file.close();
	return true;
}

