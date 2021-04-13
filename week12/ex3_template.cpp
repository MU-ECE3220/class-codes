#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
 
struct Jedi {
	/** ATTENTION
		For those haven't watched a single movie of Star Wars!
		Midi-chlorians is a blood count for Jedis that shows
		their power.
		
		WATCH IT!!!
		
		Advice for watching order: IV, V, I, II, III, VI, VII, VIII, IX (aka. Machete Order)
	**/
	int midichlorians;
	string name;
 
	Jedi(int jediMidichlorians, string jediName) :  midichlorians(jediMidichlorians), name(jediName)
	{
	}
	
	// Implement the comparator function
	bool operator <(const Jedi &jedi_obj) const {
		return midichlorians > jedi_obj.midichlorians;
	}
};
 
struct JediComparator {
	// Compare 2 Jedi objects using name
	bool operator ()(const Jedi &jedi1, const Jedi &jedi2){
		return jedi1.name <= jedi2.name;
	}
};

bool jedi_compare(const Jedi &jedi1, const Jedi &jedi2){
		return jedi1.name <= jedi2.name;
}

int main() {
	list<Jedi> listOfJedis = { Jedi(2200, "Luke Skywalker"),
				Jedi(1750, "Obi-wan Kenobi"),
				Jedi(3000, "Anakin Skywalker"),
				Jedi(1250, "Qui-gon Jinn"),
				Jedi(2500, "Mace Windu"),
				Jedi(2700, "Master Yoda"),};
 
 	// Print jedis with their midichlorians
	cout<<"-----Initial Jedi list-----"<<endl;
	for(Jedi &jedi : listOfJedis)
		cout << jedi.midichlorians << " :: " << jedi.name << endl;
 
	// Sort List by default criteria i.e < operator of Jedi
	cout << "-----After Sort By Midi-chlorians-----" << endl;
	listOfJedis.sort();
	for(Jedi &jedi : listOfJedis)
		cout << jedi.midichlorians << " :: " << jedi.name << endl;

 
	cout<<"-----After Sorting By Jedi Name"<<endl;
 
	// Sorting List using Lambda function as comparator
	listOfJedis.sort([](const Jedi &jedi1, const Jedi &jedi2)
				{
					//if(jedi1.name == jedi2.name)
					//	return jedi1.name < jedi2.name;
					return jedi1.name <= jedi2.name;
				});
	for(Jedi &jedi : listOfJedis)
		cout << jedi.midichlorians << " :: " << jedi.name << endl;
	
	cout << "==============SORTING WITH COMPARATOR==============" << endl;
	// Sorting List using Function Objects as comparator
	listOfJedis.sort(JediComparator());

	for(Jedi &jedi : listOfJedis)
		cout << jedi.midichlorians << " :: " << jedi.name << endl;
 
	return EXIT_SUCCESS;
}










