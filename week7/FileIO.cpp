#include "FileIO.h"

bool FileIO::readFile() {
	ifstream my_file;
	my_file.open(this->filename);
	string data;
	if(!my_file) {
		cerr << "Cannot open file "<< this->filename << "\n";
		return false;
	}

	while(getline(my_file, data)){
		cout << data << endl;
	}	
	return true;
}

bool FileIO::writeFile() {
	ofstream my_file;
	my_file.open(filename);
	if(my_file) {
		my_file << "Die, DIE. Why won't you die\n";
		my_file << "Beneath this mask there is more than flesh, Beneath this mask there is an idea, Mr. Creedy, and ideas are bulletproof.\n";
		my_file.close();
		return true;
	}

	cerr << "Cannot read file\n";
	return false;
}

/**
	@Return: bool
	@Paremater: string filename
		Receives a string file name for reading
	@Description:	Expects to a file name specifcally named "number.txt".
			Read each line one-by-one, adds the two numbers in the file,
			and prints the summation of the numbers.
*/
bool FileIO::readAndAddNumbersFromFile(string filename) {
	// Control if file name is correct
	//if(strncmp(filename, "number.txt", 10) != 0) {
	if(filename.compare("numbers.txt") != 0) {
		cerr << "Wrong file name. File name must be 'numbers.txt'\n";
		return false;	
	}
	ifstream my_file;
	my_file.open(filename); 	// Open file
	if(!my_file) { 			// Check if file open is successful or not
		return false;
	}
	string text, number = "";
	int lineCounter = 1, numbers[2];
	while(getline(my_file, text)){		// Read file line by line
		int index = 0;
		for(auto digit : text) {	// Read the text letter by letter in a line 
			if(digit == ' '){	// Check if numbers are splitted by a whitespace
				numbers[index] = stoi(number);
				number = "";
				index++;
			}
			else{
				number = number + digit;	// Concatenate digits to build the number
			}
		}
		numbers[index] = stoi(number);	// After the digits are concatenated convert the string number to an integer number
		cout << "At line " << lineCounter << " sum is: " << (numbers[0]+numbers[1]) << endl;
		lineCounter++;	// Increment line number
		number = "";
	}
	return true;
}

void FileIO::setFileName(string filename) {
	this->filename = filename;
}

string FileIO::getFileName() {
	return filename;
}

