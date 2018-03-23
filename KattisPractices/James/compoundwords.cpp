#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main () {
	string in;
	vector <string> input;
	set <string> output;
	while (cin >> in) {
		for (auto it = input.begin(); it != input.end(); it++) {
			output.insert(in + *it);
			output.insert(*it + in);
		}
		input.push_back(in);
	}

	for (auto it = output.begin(); it != output.end(); it++)
		cout << *it << endl;

	return 0;
}