#include <bits/stdc++.h>
using namespace std;

int main () {
	long input, output = 0, divisor = 2;
	cin >> input;
	while (divisor*divisor <= input) {
		if (!(input%divisor)) {
			input/=divisor;
			output++;
		} else divisor++;
	}
	cout << output+1 << endl;
	return 0;
}