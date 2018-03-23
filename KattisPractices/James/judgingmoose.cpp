#include <iostream>
using namespace std;

int main () {
	int left, right;
	
	cin >> left >> right;

	if (left + right == 0) {
		cout << "Not a moose" << endl;
	} else if (left == right) {
		cout << "Even " << 2*left << endl;
	} else {
		cout << "Odd " << 2*max(left,right) << endl;
	}

	return 0;
}
