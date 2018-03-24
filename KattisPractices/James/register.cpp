#include <iostream>
using namespace std;

int main () {
	int a[8], count = 0;
	int b[8] = {2, 3, 5,7, 11, 13, 17, 19};

	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}

	while (a[7] < 19) {
		a[0]++;
		count++;
		for (int i = 0; i < 7; i++) {
			if (a[i] >= b[i]) {
				a[i+1]++;
				a[i] = 0;
			}
		}
	}

	count--;

	cout << count << endl;
	
	return 0;
}
