
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<string, vector<int> > scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Vicky"].push_back(15);

	for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++) {
		string name = it->first;
		vector<int> scoreList = it->second;

		cout << name << " : " << flush;

		for (int i = 0; i < scoreList.size(); i++) {
			cout << scoreList[i] << " " << flush;
		}
		cout << endl;
	}
	return 0;
}

