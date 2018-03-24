#include <iostream>
#include <string>
using namespace std;

void sortArr (string arr[], int num) {
	string temp;

	for (int i = 0; i < num-1; i++) {
		for (int j = 0; j < num-i-1; j++) {
			if (arr[j][0] > arr[j+1][0]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			} else if (arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int num;
	string arr[200];

	do {
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}

		sortArr(arr, num);

		cout << endl;

		for (int i = 0; i < num; i++) {
			cout << arr[i] << endl;
		}

	} while (num != 0);

	return 0;
}
