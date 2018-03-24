#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	string first, last;
	map<string, vector<string> > names, lastNames;

	while (cin >> first >> last) names[first].push_back(last);

	for (auto& it: names) {
		for (auto& itt : it.second) {
			if (it.second.size() > 1) lastNames[itt].push_back(it.first+" "+itt);
			else lastNames[itt].push_back(it.first);
		}
	}

	for (auto& it : lastNames) for (auto& itt : it.second) cout << itt << endl;

	return 0;
}