#include <bits/stdc++.h>
using namespace std;

int main() {
	int trips, k;
	string country;
	unordered_map<string, vector<int> > uM;
	vector<string> list;
	cin >> trips;
	while (trips--) {
		cin >> country >> k;
		uM[country].push_back(k);
	}

	for (auto it = uM.begin(); it != uM.end(); it++) {
		stable_sort(it->second.begin(), it->second.end());
	}

	cin >> trips;
	while (trips--) {
		cin >> country >> k;
		cout << uM[country][k-1] << endl;
	}

	return 0;
}