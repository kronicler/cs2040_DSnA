#include <bits/stdc++.h>
using namespace std;

int main () {
	int cases;

	while (cin >> cases, cases) {
		cin.get();
		map <string, set<string>> myMap;
		for (int i = 0; i < cases; i++) {
			string line, name, food;
			getline(cin, line);
			istringstream iss(line);
			iss >> name;
			while (iss >> food)
				myMap[food].insert[name];
		}

		for (auto &it : myMap) {
			cout << it.first;
			for (auto &itt : it.second)
				cout << " " << itt;
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}