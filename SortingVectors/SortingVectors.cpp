
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort


using namespace std;

class Test {
	int id;
	string name;

public:
	Test(int id, string name): id(id), name(name) {}

	void print() {
		cout << id << " : " << name <<endl;
	}

	friend bool comp(const Test &a, const Test &b);
	

};

bool comp(const Test& a, const Test& b) {
	return a.name < b.name;
}

int main()
{
	vector<Test> tests;

	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10, "Sue"));
	tests.push_back(Test(7, "Raj"));
	tests.push_back(Test(3, "Vicky"));
	
	sort(tests.begin(), tests.end(), comp);

	for (int i = 0; i < tests.size(); i++) {
		tests[i].print();
	}

}

