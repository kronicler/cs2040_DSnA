#include <iostream>
#include <sstream>
using namespace std;

int main () {
	int TC;

	cin >> TC;
	while (TC--) {
		string input;
		cin >> input;
		if (input == "P=NP") cout << "skipped\n";
		else {
			string token;
			int sum = 0;
			stringstream ss(input);
			while(getline(ss, token, '+')) sum += stoi(token);
			cout << sum << endl;
		}
	}
	return 0;
}