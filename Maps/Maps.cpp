
#include <iostream>
#include <map>

using namespace std;

int main() {

	map<string, int> ages;

	// adding key value pairs into the map
	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages.insert(make_pair("Peter", 85));

	// checking for a key
	if (ages.find("Vicky") != ages.end()) {
		cout << "Found vicky" << endl;
	}
	else {
		cout << "Key not found" << endl;
	}

	//iterating through map
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

	// secon way for iterating
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		pair<string, int> age = *it;

		cout << age.first << " : " << age.second << endl;
	}

	return 0;

}
