#include <iostream>
using namespace std;

int main () {
	int cases, speed, time;

	while (cin >> cases, cases != -1) {
		int arr[cases];
		int sum = 0;
		for (int i = 0; i < cases; i++) {
			cin >> speed >> time;
			arr[i] = time;
			if (!i) sum += speed*time;
			else sum += speed*(time-arr[i-1]);
		}
		cout << sum << " miles\n";
	}
	return 0;
}