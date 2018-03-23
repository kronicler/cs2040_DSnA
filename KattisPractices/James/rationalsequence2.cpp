#include <iostream>
using namespace std;

int main () {
	int cases;
	unsigned long left, right, out;
	char num, dump;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> num >> left >> dump >> right;

		if (left+right == 2) out = 1;
		else if (left < right) {
			out = ;
		} else if (left > right) {
			out = ;
		}

		cout << num << " " << out << endl;
	}

	return 0;
}