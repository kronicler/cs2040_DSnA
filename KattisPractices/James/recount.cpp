#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main () {
	string name;
	map <string, int> votes;
	map <int, vector<string> > freq;
	while(getline(cin,name), name != "***") {
		votes[name]++;
	}

	for (auto it = votes.begin(); it != votes.end(); it++)
		freq[it->second].push_back(it->first);

	auto itt = freq.end();
	itt--;
	if (freq[itt->first].size() > 1) cout << "Runoff!" << endl;
	else cout << itt->second[0] << endl;
	return 0;
}