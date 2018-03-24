#include <iostream>
using namespace std;

int main () {
	int cases;

	cin >> cases;
	int arr[cases];
	int in;
	for (int i = 0; i < cases; i++) {
		cin >> in;
		arr[i] = in;
	}

	for (int i = 1; i < cases; i++) {
		int a = arr[0], b = arr[i];
		while (a != b) {
			if (a > b) a -= b;
			else b -= a;
		}
		cout << arr[0]/a << "/" << arr[i]/a << endl;
	}

	return 0;
}