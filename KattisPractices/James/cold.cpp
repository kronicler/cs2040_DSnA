#include <iostream>
using namespace std;

int main () {
	int cases, in, sum = 0;
	cin >> cases;
	while (cases--) {
		cin >> in;
		if (in < 0) sum++;
	}
	cout << sum << endl;
	return 0;
}
