#include <bits/stdc++.h>
using namespace std;

int main () {
	int num;
	string word;
	cin >> num;
	vector <string> str, sorted;

	for (int i = 0; i < num; i++) {
		cin >> word;
		str.push_back(word);
		sorted.push_back(word);
	}
	
	sort(sorted.begin(), sorted.end());
	
	if (str == sorted) cout << "INCREASING" << endl;
	else {
		reverse(sorted.begin(),sorted.end());
		printf((str == sorted)? "DECREASING\n" : "NEITHER\n");
	}
	
	return 0;
}
