#include <iostream>
using namespace std;

int sumDigs (int num) {
	int sum = 0;
	
	while (num) {
		sum += num%10;
		num /= 10;
	}
	return sum;
}

int main () {
	int l, d, x;
	int i, sum;
	
	cin >> l >> d >> x;
	
	for (i = l; i <= d; i++) {
		sum = sumDigs(i);
		if (sum == x) {
			cout << i << endl;
			break;
		}
	}
	
	for (i = d; i >= l; i--) {
		sum = sumDigs(i);
		if (sum == x) {
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
