#include <iostream>
using namespace std;

int main () {
	int task, time;
	int items[50];

	cin >> task >> time;
	for (int i = 0; i < task; i++) {
		cin >> items[i];
	}

	int sum = 0;
	int count = 0;
	for (int i = 0; i < task; i++) {
		sum += items[i];
		if (sum <= time) count++;
		else break;
	}
	cout << count << endl;
	return 0;
}